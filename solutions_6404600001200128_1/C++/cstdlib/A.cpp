#include <bits/stdc++.h>
#define rep(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
vector<int> plate;

int main()
{
  int T, N, m;
  cin>>T;
  rep(c, 1, T)
  {
    plate.clear();
    cin>>N;
    int a1 = 0, a2 = 0;
    rep(i, 1, N) { cin>>m; plate.push_back(m); }
    int mx = -1;
    rep(i, 1, plate.size()-1) 
    { 
      if(plate[i] <= plate[i-1]) a1 += plate[i - 1] - plate[i]; 
      if(plate[i] <= plate[i-1]) if(plate[i - 1] - plate[i] > mx) mx = plate[i - 1] - plate[i];
    }
    rep(i, 0, plate.size()-2)
    {
      if(plate[i] <= mx) a2 += plate[i];
      if(plate[i] > mx) 
      {
        a2 += mx;
      }
    }


    printf("Case #%d: %d %d\n", c, a1, a2);
  }
  return 0;
}
