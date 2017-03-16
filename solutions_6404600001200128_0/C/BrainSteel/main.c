/* 
 
Google Code Jam Round 1A
April 17, 2015

Jesse Pritchard
Public contact: chaserdevelopment@gmail.com
 
Problem A

*/

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main() {
    int num, iii;
    scanf(" %d", &num);
    for (iii = 0; iii < num; iii++) {
        
        int mushnum;
        scanf(" %d", &mushnum);
        int jjj, mush[mushnum];
        for (jjj = 0; jjj < mushnum; jjj++) {
            scanf(" %d", &mush[jjj]);
        }

        //First method:
        
        long eaten1 = 0;
        for (jjj = 1; jjj < mushnum; jjj++) {
            if (mush[jjj] < mush[jjj - 1]) {
                eaten1 += mush[jjj - 1] - mush[jjj];
            }
        }
        
        //Second method:
        
        long eaten2 = 0, largest = 0;
        for (jjj = 1; jjj < mushnum; jjj++) {
            if (mush[jjj - 1] - mush[jjj] > largest) {
                largest = mush[jjj - 1] - mush[jjj];
            }
        }
        
        for (jjj = 0; jjj < mushnum - 1; jjj++) {
            eaten2 += largest > mush[jjj] ? mush[jjj] : largest;
        }
        
        printf("Case #%d: %ld %ld\n", iii + 1, eaten1, eaten2);
    }
    return 0;
}
