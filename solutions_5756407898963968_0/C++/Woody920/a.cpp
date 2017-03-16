#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

int counter = 0;

int a[4][4];
int pos[4];
void runCase() {
    printf("Case #%d: ", ++counter);
    
    int f; scanf("%d", &f);
     for (int i=0; i<4; ++i) {
         for (int j=0; j<4; ++j) {
             scanf("%d", &a[i][j]);
         }
     }
     
     for(int i = 0; i < 4; ++i)
     {
        pos[i] = a[f-1][i];
     }
     
     
     int s; scanf("%d", &s);
      for (int i=0; i<4; ++i) {
          for (int j=0; j<4; ++j) {
              scanf("%d", &a[i][j]);
          }
      }
     
      int answers = 0;
      for(int i = 0; i < 4; ++i)
      {
         for(int j = 0; j < 4; ++j)
         {            
            if(a[s-1][i] == pos[j]) {
               if(answers != 0) {
                  printf("Bad magician!\n");
                  return;
               } else {
                  answers = pos[j];
               }
            }
         }
      }
      
      if(answers == 0) {
         printf("Volunteer cheated!\n");
      } else {
         printf("%d\n", answers);
      }
     
     

    return;
}

void preprocess() {
   
}

int main() {
   preprocess();
    int t; scanf("%d", &t);
    while(t--) {
        runCase();
    }
    return 0;
}

/*
    string s;
    getline(cin, s);
    for(int i = 0; i < s.length(); i++) {
    	char c = s.at(i);

//  n, m, 2 numbers per line
//    int n, m; scanf("%d %d", &n, &m);


/* GRID - N x M  
int n, m; scanf("%d %d", &n, &m);
 for (int i=0; i<n; ++i) {
     for (int j=0; j<m; ++j) {
         scanf("%d", &t[i][j]);
     }
 }

/*
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
*/

