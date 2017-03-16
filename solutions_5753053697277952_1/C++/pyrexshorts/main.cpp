#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
int cnt[30], n, s;
void _main()
{
    cin >> n;
    s = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> cnt[i];
        s += cnt[i];
    }
    while(s--)
    {
        int idx = max_element(cnt, cnt + n)-cnt;
        cout << char(idx + 'A');
        cnt[idx]--;
        int idx2 = max_element(cnt, cnt + n)-cnt;
        if(cnt[idx2] > (s)/2)
        {
            cout << char(idx2 + 'A');
            cnt[idx2]--;
            s--;
        }
        cout << " ";
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    for(int i = 1; i <= tt; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        cout << "Case #" << i << ": ";
        _main();
        cout << "\n";
    }
    return 0;
}
