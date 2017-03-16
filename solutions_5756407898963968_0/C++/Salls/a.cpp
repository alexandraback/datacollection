#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

void solve() {
   int grid[4][4];
   int grid2[4][4];
   int ans1, ans2;
   cin >> ans1;
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         cin >> grid[i][j];

   cin >> ans2;
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         cin >> grid2[i][j];

   int possible[4];
   for(int i = 0; i < 4; i++)
      possible[i] = grid[ans1-1][i];

   vector<int> ans;
   for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
         if(possible[j] == grid2[ans2-1][i])
            ans.push_back(possible[j]);

   if(ans.size() == 0)
      cout << "Volunteer cheated!";
   if(ans.size() == 1)
      cout << ans[0];
   if(ans.size() > 1)
      cout << "Bad magician!";

}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
