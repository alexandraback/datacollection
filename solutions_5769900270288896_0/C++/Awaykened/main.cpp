#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int r,c,n,t,grid[16][16],ans,best = 1e9;

void brute(int pos, int guest) {
      /*
      cout << pos << " " << guest << endl;
      for (int i = 0;i<r;i++) {
            for (int j = 0;j<c;j++)
                  cout << grid[i][j] << " " ;
      cout << endl;
}
      cout << endl;
       */
      if (guest == n+1) {
            best = min(best,ans);
            return;
      }
      if (pos == r*c) return;
      grid[pos/c][pos%c] = 1;
      if (pos/c-1 >= 0 && grid[pos/c-1][pos%c]) ans ++;
      if (pos%c-1 >= 0 && grid[pos/c][pos%c-1]) ans ++;
      brute(pos+1,guest+1);
      grid[pos/c][pos%c] = 0;
      if (pos/c-1 >=0 && grid[pos/c-1][pos%c]) ans --;
      if (pos%c-1 >= 0 && grid[pos/c][pos%c-1]) ans --;
      brute(pos+1,guest);
}
int main() {
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
      cin >> t;
      for (int test = 1;test<=t;test++) {
      scanf("%d%d%d",&r,&c,&n);
      ans = 0;
      brute(0,1);
            printf("Case #%d: %d\n",test,best);
            best = 1e9;

      }
}