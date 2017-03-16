#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;


    vector<string> all;
    pair<char,int> cnt[100][100];
int main()
{
  int t;
  int i;
  cin>>t;
  for(i=1;i<=t;i++)
  {
    int n;
    cin>>n;

    all.clear();
    int j;
    for(j=0;j<n;j++)
    {
      string t;
      cin>>t;
      all.push_back(t);
    }
    for(j=0;j<100;j++)
    {
        int k;
        for(k=0;k<100;k++)
          cnt[i][j] = make_pair(0,-1);
    }
    int mp = 0;
    for(j=0;j<n;j++)
    {
        int k;
        cnt[j][0] = make_pair(all[j][0],1);
        int p = 0;
        for(k=1;k<all[j].length();k++)
        {
            if(all[j][k] == all[j][k-1])  
              cnt[j][p].second++;
            else
            {
                p++;
                cnt[j][p] = make_pair(all[j][k],1);
            }
        }
        mp = max(mp,p);
    }
    int ans = 0;
    bool br = false;
    int k;
    for(k=0;k<=mp && !br;k++)
    {
        vector<int> lst; 
        char cu = cnt[0][k].first;
        for(j=0;j<n && !br;j++)
        {
           if(cnt[j][k].second == -1 || cnt[j][k].first!=cu)     
           {
              br = true;
              printf("Case #%d: Fegla Won\n",i);
              break;
           }
           lst.push_back(cnt[j][k].second);
        }
        if(!br)
        {
            sort(lst.begin(),lst.end());
            for(j=0;j<lst.size();j++)
            {
                ans+=abs(lst[j]-lst[lst.size()/2]);
            }
        }
        else
          break;
    }
    if(!br)
    printf("Case #%d: %d\n",i,ans);
  }
}
