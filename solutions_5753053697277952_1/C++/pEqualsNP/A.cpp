#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
typedef long long LL;


main() {
	int T;
   int N;
   int P[30];
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
      cin >> N;
      for (int i = 0; i < N; i++)
         cin >> P[i];
      bool isFirst = true;
      while (1) {
         bool found = false; 
         int max = -1;
         int index = -1;
         for (int i = 0; i < N; i++)
            if ( (P[i] > 0) && (max < P[i])) {
               index = i;
               max = P[i];
            }
         if (max == -1)
            break;
         if (!isFirst)
           printf(" %c", 65 + index);
         else
           printf("%c", 65 + index);
         isFirst = false;
         P[index]--;
         max = -1;
         index = -1;
         int sum = 0;
         for (int i = 0; i < N; i++)
         {
            sum += P[i];
            if ((P[i] > 0) && (max < P[i])) {
               index = i;
               max = P[i];
            }
         }
         if (max == -1)
            break;
         P[index]--;
         max = -1;
         for (int i = 0; i < N; i++)
            if ( (P[i] > 0) && (max < P[i])) {
               max = P[i];
            }
         if ((max == -1) || (max <= (sum - 1) / 2))
           printf("%c", 65 + index);
         else
           P[index]++;
      }
      std::cout << std::endl;
   }
	exit(0);
}
