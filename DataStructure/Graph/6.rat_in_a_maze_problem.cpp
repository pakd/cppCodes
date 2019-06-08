#include <iostream>

#define N 4

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << sol[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// utility function to check if cell is safe or not(out of boundary)
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x == N-1 && y == N-1)
    {
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(maze, x, y))
    {
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if(solveMazeUtil(maze, x + 1, y, sol))
        {
            return true;
        }

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if(solveMazeUtil(maze, x, y + 1, sol))
        {
            return true;
        }

         /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }
}


void solveMaze(int maze[N][N])
{
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if(!solveMazeUtil(maze, 0, 0, sol))
    {
        std::cout << "Solution doesn't exist";
        return;
    }
    else
    {
        printSolution(sol);
    }
}

int main()
{
    // 0 = gray cell, not allowed
    // 1 = allowed
    int maze[N][N]  =  {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
