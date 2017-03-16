#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <sstream>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef map<string,int> MSI;
typedef map<string,string> MSS;
typedef queue<string> QS;
typedef map<int,int> MII;
typedef queue<VI> QVI;
typedef map<VI,int> MVII;

string getm (string a)
{
  string ans = "";
  ans += a[0];
  fii (1,a.size())
  {
    if (a[i] != a[i-1]) ans += a[i];
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    int n;
    cin >> n;
    VS v(n);
    fi (n) cin >> v[i];
    string molde = getm (v[0]);
    bool ok = true;
    fii (1,n) if (getm(v[i]) != molde) ok = false;
    if (not ok)
    {
      cout << "Fegla Won" << endl;
      continue;
    }
    VVI ent (n);
    fi (n)
    {
      ent[i].push_back(1);
      fjj (1,v[i].size())
        if (v[i][j] == v[i][j-1]) ent[i][ent[i].size()-1] ++;
        else ent[i].push_back(1);
    }
//     fi (n) 
//     {
//       fj (v[i].size()) cout << ent[i][j] << " ";
//       cout << endl;
//     }
    int ans = 0;
    fi (ent[0].size())
    {
      int mn = inf;
      fj(101)
      {
        int ct = 0;
        fk (n)
          ct += abs(ent[k][i]-j);
        mn = min (mn, ct);
      }
      ans += mn;
    }
    cout << ans << endl;
  }
}