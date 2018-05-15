#include <iostream>
#define N 3
#define M 3
using namespace std;

void find_saddle_points(int arr[N][M])
{
    int row, col, r, m, saddles_count = 0, saddle_flag = 0, duplicate_row = 0, duplicate_col = 0;

    //print matrix
    cout << "MATRIX:" << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << arr[i][j] << "\t";
            if(j==M-1){
                cout << endl;
            }
        }
    }
    cout << endl;

    //find saddle points
    for(row=0;row<N;row++){
        duplicate_row = duplicate_col = m = 0;

        //find max in row
        for(col=0;col<M;col++){
            if(arr[row][col] > arr[row][m]){
                duplicate_row = 0;
                m = col;
            }
            else if(arr[row][col] == arr[row][m]){
                if(col){
                    duplicate_row = 1;
                }
            }
        }
        saddle_flag = 0;

        //find min in col
        for(r=0;r<N;r++){
            if(arr[r][m] < arr[row][m]){
                saddle_flag = 1;
            }
            else if(arr[r][m] == arr[row][m]){
                duplicate_col++;
            }
        }

        if(!saddle_flag && !duplicate_row && duplicate_col == 1){
            saddles_count++;
            cout << "Saddle point found at [" << row << "," << m << "] Value: " << arr[row][m] << endl;
        }
        duplicate_row = duplicate_col = m = 0;

        //find min in row
        for(col=0;col<M;col++){
            if(arr[row][col] < arr[row][m]){
                duplicate_row = 0;
                m = col;
            }
            else if(arr[row][col] == arr[row][m]){
                if(col){
                    duplicate_row = 1;
                }
            }
        }
        saddle_flag = 0;

        //find max in col
        for(r=0;r<N;r++){
            if(arr[r][m] > arr[row][m]){
                saddle_flag = 1;
            }
            else if(arr[r][m] == arr[row][m]){
                duplicate_col++;
            }
        }

        if(!saddle_flag && !duplicate_row && duplicate_col == 1){
            saddles_count++;
            cout << "Saddle point found at [" << row << "," << m << "] Value: " << arr[row][m] << endl;
        }
    }

    if(saddles_count){
        cout << "Total saddle points: " << saddles_count;
    }
    else {
        cout << "There are no saddle points in this matrix";
    }
}

int main()
{
    int test_arr_one[N][M] = {{1,2,3},{4,5,6},{7,8,9}}; // 2 saddle points expected result
    int test_arr_two[N][M] = {{2,2,2},{4,4,4},{7,7,7}}; // no saddle points expected result
    int test_arr_three[N][M] = {{2,2,2},{4,5,6},{7,8,8}}; // one saddle point expected result

    find_saddle_points(test_arr_one);
    cout << endl << endl;
    find_saddle_points(test_arr_two);
    cout << endl << endl;
    find_saddle_points(test_arr_three);

    return 0;
}
