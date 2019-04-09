#include <iostream>
#include <queue>
using namespace std;

#define R 3
#define C 4

struct BinaryCell
{
    int x;
    int y;
};

bool isDelim(BinaryCell bC)
{
    if(bC.x == -1 && bC.y == -1)
    {
        return true;
    }
    return false;
}

// is valid cell
bool isValid (int i, int j)
{
    return (i >= 0 && j >= 0 && i < R && j < C);
}

// Function to check whether there is still a fresh
// orange remaining
bool checkall(int arr[][C])
{
    for (int i=0; i<R; i++)
       for (int j=0; j<C; j++)
          if (arr[i][j] == 0)
             return true;
    return false;
}


void findMinDistance(int arr[][C])
{
    queue<BinaryCell> Q;

    // preprocessing: push all cells with value = 1 in queue
    BinaryCell temp;
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (arr[i][j] == 1)
            {
                arr[i][j] = INT_MIN;
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }

    // push delimiter
    BinaryCell delim;
    delim.x = -1;
    delim.y = -1;
    Q.push(delim);

    int i = 1;

    int ans = 0;


    while(!Q.empty())
    {
        bool flag = false;

        while(!isDelim(Q.front()))
        {

            temp = Q.front();


            if (isValid(temp.x + 1, temp.y) && arr[temp.x + 1][temp.y] == 0)
            {

                arr[temp.x+1][temp.y] = i;


                temp.x++;
                Q.push(temp);

                temp.x--;
            }

            // Check left adjacent cell
            if (isValid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 0)
            {
                arr[temp.x-1][temp.y] = i;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }

            // Check top adjacent cell
            if (isValid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 0)
            {
                arr[temp.x][temp.y+1] = i;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }

            // Check bottom adjacent cell
            if (isValid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 0) {
                arr[temp.x][temp.y-1] = i;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }

            // pop the temp element
            Q.pop();

        }

        // pop the delimiter
        Q.pop();
        i++;

        // If queue is not empty
        if(!Q.empty())
        {
            temp.x = -1;
            temp.y = -1;

            Q.push(temp);
        }
    }


    // print 2d array
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (arr[i][j] == INT_MIN)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

}


int main()
{


    int mat[R][C] =
    {
        0, 0, 0, 1,
        0, 0, 1, 1,
        0, 1, 1, 0
    };

    findMinDistance(mat);

    return 0;
}
