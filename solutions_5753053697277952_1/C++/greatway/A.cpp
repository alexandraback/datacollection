#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

const int MAXN = 1010;

int T;
int N;
int a[MAXN];
vector<string> ans;

bool checkend()
{
    for(int i=1;i<=N;i++)
        if( a[i] != 0 )
            return false;
    return true;
}
bool checksame()
{
    int amt;
    for(int i=1;i<=N;i++)
    {
        if( a[i] != 0 )
        {
            amt = a[i];
            break;
        }

    }
    for(int i=1;i<=N;i++)
        if( a[i] != 0 && a[i] != amt )
            return false;
    return true;
}
int checkcnt()
{
    int cnt = 0;
    for(int i=1;i<=N;i++)
        if( a[i] != 0 )
            cnt++;
    return cnt;
}
int getMax()
{
    int pos = 1;
    int tm = -1;
    for(int i=1;i<=N;i++)
    {
        if( a[i] > tm )
        {
            pos = i;
            tm = a[i];
        }
    }
    return pos;
}
void solve(int idx)
{
    ans.clear();
    cout << "Case #" << idx << ": ";
    bool same = false;
    while( !checkend() )
    {
        if( checksame() && checkcnt() == 2 )
        {
            int x;
            string tmp = "";
            x = getMax(); a[x]--; tmp = tmp + char(x-1+'A');
            x = getMax(); a[x]--; tmp = tmp + char(x-1+'A');
            ans.push_back(tmp);
        }
        else
        {
            int x = getMax();
            a[x]--;
            string tmp = ""; tmp = tmp + char(x-1+'A');
            ans.push_back(tmp);
        }
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
//    freopen("in.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("A-large-out.txt","w",stdout);

    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> N;
        for(int j=1;j<=N;j++)
            cin >> a[j];
        solve(i);
    }

    return 0;
}
