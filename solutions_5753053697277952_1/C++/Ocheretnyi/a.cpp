#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define ld long double
#define ll long long
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf (int)1e9
#define pi pair<int,int>
#define y1 fdfs
using namespace std;
inline void read(int &x){x = 0;while(1){char ch = getchar();if(ch==' '||ch=='\n') break;x = x*10 + ch - '0';}}
inline void write(int x){char wr[12];int k = 0;if(!x) ++k,wr[k] = '0';while(x){++k;wr[k] = char(x%10+'0');x/=10;}for(int i=k;i>=1;--i)putchar(wr[i]);}
int t,n,a[27];
bool good()
{
    int s = 0;
    for(int i=1;i<=n;++i)
        s+=a[i];
    for(int i=1;i<=n;++i)
    {
        if(!a[i]) continue;
        if(a[i]>s-a[i]) return 0;
    }
    return 1;
}
vector<string> ans;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("1.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>t;
    for(int T=1;T<=t;++T)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        ans.clear();
        while(1)
        {
            bool p = 0;
            for(int i=1;i<=n;++i)
                if(a[i])
            {
                for(int j=1;j<=n;++j)
                {
                    if(i==j&&a[i]<2) continue;
                    if(!a[j]) continue;
                    int x = 1,y = 0;
                    if(i==j) ++x;else ++y;
                    a[i]-=x;
                    a[j]-=y;

                    if(good())
                    {
                        string z;
                        p = 1;
                        z.pb(char(i-1+'A'));
                        z.pb(char(j-1+'A'));
                        ans.pb(z);
                        continue;
                    }
                    a[i]+=x;
                    a[j]+=y;
                }
            }
            for(int i=1;i<=n;++i)
            {
                if(a[i])
                {
                    --a[i];
                    if(good())
                    {
                        string z;
                        p = 1;
                        z.pb(char(i-1+'A'));
                        ans.pb(z);
                        continue;
                    }
                    ++a[i];
                }
            }
            if(!p) break;
        }
        cout<<"Case #"<<T<<": ";
        for(int i=0;i<ans.size();++i)
            cout<<ans[i]<<' ';
        cout<<"\n";
    }
}
