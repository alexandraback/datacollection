#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstring>


using namespace std;

long int t , ans1 , ans2;
long int mat1[5][5] , mat2[5][5];

int main()
{
    freopen("abc.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    long int i , j , k , a , b , c;
    vector<long int> v;
    scanf("%ld" , &t);
    k = 1;
    while(k <= t) {
            scanf("%ld" , &ans1);
            for(i = 1; i <= 4; i++) {
                  for(j = 1; j <= 4; j++) {
                        scanf("%ld" , &mat1[i][j]);
                  }
            }
            scanf("%ld" , &ans2);
            for(i = 1; i <= 4; i++) {
                  for(j = 1; j <= 4; j++) {
                        scanf("%ld" , &mat2[i][j]);
                  }
            }
            
            for(i = 1; i <= 4; i++) {
                  for(j = 1; j <= 4; j++) {
                        if(mat1[ans1][i] == mat2[ans2][j]) {
                                         v.push_back(mat1[ans1][i]);
                                         break;
                        }
                  }
            }
           // cout << v.size() << "\n";
            printf("Case #%ld: " , k);
            if(v.size() == 1) {
                        printf("%ld\n" , v[0]);
            } else if(v.size() > 1) {
                        printf("Bad magician!\n");
            } else if(v.size() == 0){
                        printf("Volunteer cheated!\n");
            }
            v.clear();
            k++;
    }
    //system("pause");
    return 0;
}
