#include <bits/stdc++.h>
using namespace std;

#define llj(a,b,c) for (int (a) = (b); (a) < (c); (a)++)
#define lli(a,b) llj(i,a,b)
#define lll(i, x) llj(i, 0, x)
#define fori(x) lll(i, x)
#define forj(x) lll(j, x)
#define fork(x) lll(k, x)

#define all(X) (X).begin(), (X).end()
#define ever ;;
#define fe(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)

#define LINF ((ll) 1e18 + 10)
#define pb push_back
#define mp make_pair
#define ms(arr,val) memset(arr , val , sizeof(arr))
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))
#define endl "\n"
#define trace(X) cout << (X) << endl;
#define trace2(X,Y) cout << (X) << ' ' << (Y) << endl;
#define trace3(X,Y,Z) cout << (X) << ' ' << (Y) << ' ' << (Z) << endl;
#define trace4(X,Y,Z,A) cout << (X) << ' ' << (Y) << ' ' << (Z) << ' ' << (A) << endl;
#define tp(X) trace2(X.first ,X.second)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pvi(a) fe(thing ,a) cout << thing << ' '; cout << "\n";

typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) ((int)A.size())
#define x first
#define y second
#define read_speed ios::sync_with_stdio(false); cin.tie(0)
#define LINE cout << endl << "--------------------------" << endl
/*--------------------------THE END---------------------------------*/
const int MAX = 30;


int cnt[MAX], n;

inline char TO(int i)
{
  return 'A' + (i - 1);
}

void solve()
{
  ms(cnt, 0);

  cin >> n;

  llj(i,1,n+1)
    cin >> cnt[i];

  string ans = "";

  if (n == 2)
  {
    fori(cnt[1])
      ans += "AB ";
    trace(ans);
    return;
  }

  // FIRST REDUCE EVERYTHING TO 1


  int max_ind;

  while (1){
    max_ind = 1;
    llj(i,1,n+1)
    {
      if (cnt[i] > cnt[max_ind])
        max_ind = i;
    } 
    if (cnt[max_ind] == 1) break;

    cnt[max_ind]--;
    ans += TO(max_ind);
    ans += " ";
  }

  // 1 by 1 until two

  llj(i,1,n-1){
    ans += TO(i);
    ans += " "; 
  }

  char c1 = TO(n-1), c2 = TO(n);
  ans += c1;
  ans += c2;


  trace(ans);
}




int main()
{
  freopen("test.txt", "r", stdin);
  //freopen("vacationgold.in", "r", stdin);
  //freopen("vacationgold.out", "w", stdout);

  freopen("test.out", "w", stdout);
  read_speed;

  int t;
  cin >> t;

  llj(z,1,t+1)
  {
    cout << "Case #" << z << ": ";
    solve();
  }





  


  
}


  
