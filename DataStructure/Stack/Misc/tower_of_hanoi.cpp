#include <iostream>
using namespace std;

// moving disks from src rod to dest rod using aux rod
 void towerOfHanoi(int n, char src, char dest, char aux)
 {
     if( n == 1)
     {
         cout << "disk 1 moved from " << src << " to " << dest << endl;
         return;

     }

     // moving n-1 disks from src to aux using dest rod
     towerOfHanoi( n-1, src, aux, dest);

     cout << "disk " << n << " moved from " << src << " to " << dest << endl;

     // moving n-1 disks from aux to dest using src rod
     towerOfHanoi(n-1, aux , dest, src);
 }


int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}
