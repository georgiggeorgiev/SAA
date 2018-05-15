#include <iostream>

using namespace std;

void recursive_print(int* arr, int* sequences, int index)
{
    int next_index = sequences[index];

    if (sequences[next_index] == -1) {
        cout << arr[next_index] << " ";
        cout << arr[index] << " ";

        return;
    }

    recursive_print(arr,sequences, next_index);
    cout << arr[index] << " ";
}

int get_max(int* arr, int size)
{
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int get_max_index(int* arr, int size)
{
    int index = 0;
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void print_sequence(int* arr, int* sequences, int size)
{
    int first_index = get_max_index(sequences,size);
    recursive_print(arr,sequences, first_index);
}

int main()
{
    int arr[7] = {10, 5, 40, 4, 9, 1, 0}, size = 7, sequence_len[size], sequence[size];

    for(int i = 0; i < size; i++){
        sequence_len[i] = 1;
        sequence[i] = -1;
    }

    for (int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++){
            if (arr[j] > arr[i]) {
                int current_len = sequence_len[i];
                int new_len = sequence_len[j]+1;
                if (current_len > new_len) {
                    sequence_len[i] = current_len;
                } else {
                    sequence_len[i] = new_len;
                    sequence[i] = j;
                }

            }
        }
    }

    for(int j = size - 1,i=0; j >= 0; j--){
        cout << "Longest sequence for element: " << i++ << " has length: " << sequence_len[j] << endl;
    }
    cout << "Longest sequence length: " << get_max(sequence_len,size) << endl;
    cout << "Longest sequence: ";
    print_sequence(arr,sequence,size);
    return 0;
}
