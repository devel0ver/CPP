#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool testPalindrome(string testString){
    stack<char> astack;
    queue<char> aqueue;
    char charAt;
    // Filling the data structure
    for (int i = 0; i < testString.length(); i++){
        charAt = testString[i];
        astack.push(charAt);
        aqueue.push(charAt);
    }
    bool isEqual = true;
    // char qtest, stest;
    // Testing using stack and queue
    while(!aqueue.empty() && isEqual){
        // qtest = aqueue.front();
        // stest = astack.top();
        if(aqueue.front() != astack.top())
            isEqual = false;  
        aqueue.pop();
        astack.pop();
    }
    return isEqual;
}

bool isPalindrome(string testString)
{
    int stringLen = testString.length()-1;
    for(int i = 0; i <= stringLen; i++){
        if(testString[i] != testString[stringLen - i]){
            return false;
        }
    }
    return true;
}

int main(){
    string test[6] = {"racecar", "penguins", "deified", "civic", "radar","raddar"};
    for(int i = 0; i < test->size(); i++){
        cout << test[i] << " testing... got " << (testPalindrome(test[i]) ? "true" : "false") << endl;
    }

    return 0;
}