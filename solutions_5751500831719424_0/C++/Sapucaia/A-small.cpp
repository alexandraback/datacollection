#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define rep0(i,n) for(int i = 0;i < (int)n;i++)
#define rep1(i,n) for(int i = 1;i <= (int)n;i++)
#define per0(i,n) for(int i = (int)n-1;i >= 0;i--)
#define per1(i,n) for(int i = (int)n ;i >= 1;i--)

#define pb push_back
#define fill(d,v) memset(d,v,sizeof(d))

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<char,int> pci;
typedef vector<int> vi;
typedef vector<pii> vii;


#define MAX_N 110
string s[MAX_N];
vector<pci> decom[MAX_N];
int N;

void decompose(const string & a,vector<pci> & v)
{
  char last = a[0];
  int cnt = 1;
  v.clear();
  for(int i = 1; i < (int)a.size();i++)
    {
      if(a[i] == last)
	{
	  cnt++;
	}
      else
	{
	  v.push_back(pci(last,cnt));
	  last = a[i];
	  cnt = 1;
	}
    }
  v.push_back(pci(last,cnt));
}

int cost(int i)
{
  int ret = INF;
  for(int k = 1; k <= 100; k++)
    {
      int curC = 0;
      for(int j = 0; j < N;j++)
	{
	  curC += abs(decom[j][i].second - k);
	}
      ret = min(ret,curC);
    }
  return ret;
}
int main()
{
  cin.sync_with_stdio(false);
  int T_;
  cin >> T_;
  for(int t_ = 1; t_ <= T_;t_++)
    {
      cin >> N;
      rep0(i,N)
	{
	  cin >> s[i];
	  decompose(s[i],decom[i]);
	}
      
      int ans = 0;
      for(int j = 1; j < N;j++)
	if(decom[j].size() != decom[0].size())
	  ans = -1;

      for(int i = 0; i < (int)decom[0].size() && ans != -1;i++)
	{
	  for(int j = 0; j < N && ans != -1;j++)
	    {
	      if(decom[j][i].first !=decom[0][i].first)
		  ans = -1;
	    }
	}
      cout << "Case #" << t_ << ": ";
      if(ans == -1)
	cout << "Fegla Won";
      else
	{
	  ans = 0;
	  for(int i = 0; i < (int)decom[0].size();i++)
	    ans += cost(i);
	  cout << ans;
	}
      cout << "\n";
    }
  return 0;
}
