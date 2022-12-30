#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    string name;
    while(true){
        cout << "\n\nEnter a string to test: ";
        getline(cin, name);
        int len = name.length();
        queue <char> Q;
        stack <char> S;
        int i;
        bool notsame = 0;

        for (i = 0; i < len/2; i++)
            Q.push(name[i]);
        for (; i < len; i++)
            S.push(name[i]);
        
        while (!Q.empty())
        {
            if(Q.front() != S.top())
                notsame += 1;
            Q.pop();
            S.pop();
        }
        notsame ? cout << "Not a Palindrome!\n" : cout << "Is a Palindrome!\n";
    }
    return 0;
}