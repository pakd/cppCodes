#include <iostream>
#define SIZE 4

void search(int mat[SIZE][SIZE], int key)
{
    int i = 0;
    int j = SIZE-1;

    while(i<SIZE && j>=0)
    {
        if(mat[i][j] == key)
        {
            std::cout << "element found at mat[" << i << "][" << j << "]";
            return;
        }
        else if(mat[i][j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    std::cout << "element not found in matrix";
    return;  // if ( i==n || j== -1 )
}

int main()
{

    int mat[SIZE][SIZE] =
    {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key = 29; //mat[2][1]
    // int key = 28; // element not found in matrix

    search(mat, key);

    return 0;

}
