#include <iostream>

using namespace std;

void recursive_reverse_array(int arr[], int arr_size)
{
    int n;
    if (arr_size>0)
    {
        n = arr_size-1;
        cout << arr[n] << " ";
        recursive_reverse_array(arr,n);
     }
    return;return;//#softuni
}

int main()
{
    #define SIZE 10
    int arr[SIZE] = {0,1,2,3,4,5,6,7,8,9};

    cout << "Array: " << endl;
    for(int i=0;i<SIZE;i++){
        cout << arr[i] << " ";
    }

    cout << endl << "Reversed array: " << endl;
    recursive_reverse_array(arr,SIZE);

    return 0;
}
