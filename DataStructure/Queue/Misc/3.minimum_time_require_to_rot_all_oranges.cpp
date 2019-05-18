#include <iostream>
#include <queue>
using namespace std;

#define R 3
#define C 5

struct orangeCell
{
    int x;
    int y;
};

bool isDelim(orangeCell oC)
{
    if(oC.x == -1 && oC.y == -1)
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
          if (arr[i][j] == 1)
             return true;
    return false;
}


int rotOranges(int arr[][C])
{
    queue<orangeCell> Q;

    // preprocessing: push rotten oranges in queue
    orangeCell temp;
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }

    // push delimiter
    orangeCell delim;
    delim.x = -1;
    delim.y = -1;
    Q.push(delim);

    int ans = 0;


    while(!Q.empty())
    {
        bool flag = false;

        while(!isDelim(Q.front()))
        {

            temp = Q.front();


            // Check right adjacent cell that if it can be rotten
            if (isValid(temp.x + 1, temp.y) && arr[temp.x + 1][temp.y] == 1)
            {
                // if this is the first orange to get rotten, increase
                // count and set the flag.
                if (!flag) ans++, flag = true;

                // Make the orange rotten
                arr[temp.x+1][temp.y] = 2;

                // push the adjacent orange to Queue
                temp.x++;
                Q.push(temp);

                temp.x--; // Move back to current cell
            }

            // Check left adjacent cell that if it can be rotten
            if (isValid(temp.x-1, temp.y) && arr[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x-1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }

            // Check top adjacent cell that if it can be rotten
            if (isValid(temp.x, temp.y+1) && arr[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y+1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }

            // Check bottom adjacent cell if it can be rotten
            if (isValid(temp.x, temp.y-1) && arr[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y-1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }

            // pop the temp element
            Q.pop();

        }

        // pop the delimiter
        Q.pop();

        // If queue is not empty that means new rotten oranges to process
        if(!Q.empty())
        {
            temp.x = -1;
            temp.y = -1;

            Q.push(temp);
        }
    }

    return (checkall(arr))? -1: ans;
}


int main()
{


    int arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};

    /* // all oranges can not be rotten.
    int arr[][C] = { {2, 1, 0, 2, 1},
                     {0, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
    */
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rot";
    else
         cout << "Time required for all oranges to rot => " << ans << endl;
    return 0;
}
