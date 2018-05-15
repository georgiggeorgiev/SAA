#include <iostream>

using namespace std;

int fib(int n)
{
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

long long fact(int n)
{
    if(n==0 || n==1){
        return 1;
    }
    return n*fact(n-1);
}

int binary_powers(int n)
{
    if(n==0){
        return 1;
    }
    else if(n==1){
        return 2;
    }
    else return 2*binary_powers(n-1);
}

int trib(int n)
{
    if(n==1 || n==2 || n==3){
        return 1;
    }
    return trib(n-1)+trib(n-2)+trib(n-3);
}

int main()
{
    cout << "Fibonacci: " << endl;
    for(int i=0;i<20;i++){
        cout << fib(i) << endl;
    }
    cout << "Factorial: " << endl;
    for(int i=0;i<20;i++){
        cout << fact(i) << endl;
    }
    cout << "Powers of two: " << endl;
    for(int i=0;i<20;i++){
        cout << binary_powers(i) << endl;
    }
    cout << "Tribonacci: " << endl;
    for(int i=1;i<20;i++){
        cout << trib(i) << endl;
    }

    return 0;
}
