#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn = 1005;
vector <int> adj[maxn];
bool two[maxn], vis[maxn];
int sz[maxn], f[maxn], d[maxn], gl, n;
void dfs(int cur)
{
    gl++;
    vis[cur] = 1;
    for(int i : adj[cur])
    {
        if(two[i])
        {
            sz[i] = max(sz[i], gl);
            return;
        }
        else if(!vis[i])
        {
            d[i] = d[cur]+1;
            dfs(i);
        }
        else
        {
            sz[i] = max(sz[i], d[cur] - d[i] + 1);
            return;
        }
    }
}
int _main()
{
    cin >> n;
    int ans = 0;
    for(int i = 1, x; i <= n; i++)
    {
        cin >> x;
        adj[i].pb(x);
        f[i] = x;
    }
    for(int i = 1; i <= n; i++)if(i == f[f[i]])two[i] = two[f[i]] = 1;
    for(int i = 1; i <= n; i++)if(!two[i])
    {
        gl = 0;
        memset(vis, 0, sizeof(vis));
        dfs(i);
    }
    for(int i = 1; i <= n; i++)if(two[i])ans += sz[i] + 1;
    for(int i = 1; i <= n; i++)if(!two[i])ans = max(ans, sz[i]);
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": ";
        memset(sz, 0, sizeof(sz));
        memset(vis, 0, sizeof(vis));
        memset(two, 0, sizeof(two));
        memset(d, 0, sizeof(d));
        for(int i = 1; i < maxn; i++)adj[i].clear();
        cout << _main() << "\n";
    }
    return 0;
}
