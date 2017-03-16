#include<bits/stdc++.h>

using namespace std;

#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf mod
#define eps 1e-4
//#define int long long
#define gc getchar

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("inn.in","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int cases;
	cin >> cases;
	for (int caseno = 1; caseno <= cases; caseno++)
	{
		cout << "Case #" << caseno << ": ";
		priority_queue<PII> q;
		int n;
		cin>>n;
		int a[n];
		REP(i,n)
		{
		    cin>>a[i];
		    q.push(mp(a[i],i));
		}
		while(true)
        {
            int c = a[0];
            bool k = false;
            for(int i=1;i<n;i++)
                if(a[i]!=c)
                {
                    k = true;
                    break;
                }
            if(!k)
                break;
            PII z = q.top();
            q.pop();
            a[z.second]--;
            q.push(mp(z.first-1, z.second));
            cout << (char)('A' + z.second) << ' ' ;
        }
		while(a[n-1] != 0)
        {
            REP(i,n-2)
            {
                a[i]--;
                cout << char('A' + i) << ' ';
            }
            cout << char('A'+n-2) << char('A'+n-1) << ' ';
            a[n-2]--;
            a[n-1]--;
        }
        cout << endl;
	}
    return 0;
}
