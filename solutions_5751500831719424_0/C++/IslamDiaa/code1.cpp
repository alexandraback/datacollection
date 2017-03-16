#include<iostream>
#include<string>
#include<vector>
using namespace std;

int T;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin >> T;
    int t = 1;
    while(T--)
    {
              string a[105];
              string b[105];
              int N;
              cin >> N;
              int cnt[105];
              for(int i = 0 ; i < N; i++)  
                      cin >> a[i];
              for(int i = 0 ; i < N; i++)
                      for(int j = 0 ; j < a[i].size(); j++)
                              if(j == 0 || a[i][j] != a[i][j - 1])
                                   b[i] += a[i][j];
                                   
              cout << "Case #"<<t++<<": ";
              bool flag = 1;
              for(int i = 1; i < N; i++)
                      if(b[i] != b[i - 1])
                              flag = 0;
              if(flag == 0)
              {
                      cout << "Fegla Won" << endl;
                      continue;
              }
              memset(cnt,0,sizeof cnt);
              string s = b[0];
              int ans = 0;
              for(int i = 0 ; i < s.size(); i++)
              {
                      int c[105];
                      memset(c,0,sizeof c);
                      for(int j = 0 ; j < N; j++)
                      {
                              while(cnt[j] < a[j].size() && a[j][cnt[j]] == s[i])
                              {
                                                c[j]++;
                                                cnt[j]++;
                              }                 
                      }
                      int mi = 1e9;
                      for(int k = 1; k <= 1000; k++)
                      {
                              int res = 0;
                              for(int j = 0 ; j < N; j++)
                                      if(k > c[j])
                                           res += k - c[j];
                                      else if(k < c[j])
                                           res += c[j] - k;
                              mi = min(mi,res);
                      }
                      ans += mi;
              }
              cout << ans << endl;
    }   
}
