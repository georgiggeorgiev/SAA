#include <iostream>

using namespace std;

int f(int arr[],int arr_size)
{
    for(int i=1;i<=arr_size-1;i+=2){
        if(arr[i]<=arr[i-1]){
            return 0;
        }
        if((i+1)!=arr_size){
            if(arr[i]<=arr[i+1]){
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int arr_true[7] = {1,10,1,10,1,10,1}; // expected result 1
    cout << f(arr_true,7) << endl;

    int arr_false[6] = {1,1,1,10,1,10}; // expected result 0
    cout << f(arr_false,7) << endl;

    return 0;
}
