#include <iostream>

using namespace std;

int factorialRecursive(int);

int main(){
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "\nFactorial of " << num << " using recursion is " << factorialRecursive(num) << endl;

    return 0;
}

int factorialRecursive(int n){
    if(n == 0)
        return 1;
    return n * factorialRecursive(n-1);
}