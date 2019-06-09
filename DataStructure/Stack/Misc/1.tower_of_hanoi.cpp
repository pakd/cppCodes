#include <iostream>


// moving disks from src rod to dest rod using aux rod
 void towerOfHanoi(int n, char src, char dest, char aux)
 {
     if( n == 1)
     {
         std::cout << "disk 1 moved from " << src << " to " << dest << std::endl;
         return;

     }

     // moving n-1 disks from src to aux using dest rod
     towerOfHanoi( n-1, src, aux, dest);

     std::cout << "disk " << n << " moved from " << src << " to " << dest << std::endl;

     // moving n-1 disks from aux to dest using src rod
     towerOfHanoi(n-1, aux , dest, src);
 }


int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}
