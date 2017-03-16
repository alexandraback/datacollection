#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-12;

void solve(int num)
{
    int n;
    cin>>n;
    vector<string> s(n);
    vector<pair<char,int> > v[142];
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        char last=s[i][0], ile=1;
        for(int j=1; j<s[i].length(); j++)
        {
            if(s[i][j]!=last)
            {
                v[i].pb(mp(last, ile));
                last=s[i][j];
                ile=1;
            }
            else ile++;
        }
        v[i].pb(mp(last, ile));
    }
    int ans=0;
    cout<<"Case #"<<num<<": ";
    for(int i=0; i<v[0].size(); i++)
    {
        vi wyst(n, v[0][i].se);
        int maksi=v[0][i].se;
        for(int j=1; j<n; j++)
        {
            if(v[j].size()!=v[0].size() || v[0][i].fi!=v[j][i].fi)
            {
                cout<<"Fegla Won\n";
                return;
            }
            wyst[j]=v[j][i].se;
            maksi=max(maksi, wyst[j]);
        }
        int best=424242;
        for(int i=1; i<=maksi; i++)
        {
            int cur=0;
            for(int j=0; j<n; j++) cur+=abs(wyst[j]-i);
            best=min(best, cur);
        }
        ans+=best;
    }
    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
