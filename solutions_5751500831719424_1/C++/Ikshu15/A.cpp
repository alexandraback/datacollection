/*
* Author: Ikshu Bhalla
* Language: C++
*/
#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define fori(s,e) for(i=s;i<=e;i++)
#define forj(s,e) for(j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int)x.size()
#define ln(s) s.length()
#define ppb pop_back
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define psi pair<string,int>
#define in(c,x) scanf("%"#c,&x)
#define out(c,x) printf("%"#c" ",x)
#define aa first
#define bb second
#define Endl endl
using namespace std;
int readint()
{
    int t=0;
    char c,ch;
    ch=getchar();
    if (ch=='-') c=getchar();
    else c=ch;
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        t=(t<<3)+(t<<1)+c-'0';
        c=getchar();
    }
    if (ch=='-' ) return -t;
    else return t;
}
vector<pair<char,int> > rle(string s)
{
    int i,j;
    vector<pair<char,int> > ans;
    fori(0,ln(s)-1)
    {
        int cnt=1;
        char c=s[i];
        while(i<ln(s)-1&&s[i]==s[i+1])
        {
            i++;
            cnt++;
        }
        ans.pb(mp(c,cnt));
    }
    return ans;
}
int cost(vi v,int x)
{
    int i,j,ans=0;
    fori(0,sz(v)-1) ans+=abs(v[i]-x);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m,t;
    freopen("A-large.in","r",stdin);
    freopen("OutALarge.txt","w",stdout);
    cin>>t;
    int T=t;
    while(t--)
    {
        string a,b;
        cin>>n;
        vector<pair<char,int> > v[110];
        int flag=1;
        int ans=0;
        int siz=-1;
        fori(0,n-1)
        {
            string x;
            cin>>x;
            v[i]=rle(x);
            if (siz==-1) siz=sz(v[i]);
            else if (siz!=sz(v[i]))
            {
                flag=0;
            }
        }
        if (!flag)
        {
            goto here;
        }
        else
        {
            fori(0,sz(v[0])-1)
            {
                char c=v[0][i].aa;
                vi srt;
                forj(0,n-1)
                {
                    if (c!=v[j][i].aa)
                    {
                        flag=0;
                        goto here;
                    }
                    else
                    {
                        srt.pb(v[j][i].bb);
                    }
                }
                sort(all(srt));
                if (sz(srt)%2==1)
                {
                    ans+=cost(srt,srt[sz(srt)/2]);
                }
                else
                {
                    int x=cost(srt,srt[(sz(srt))/2]);
                    int y=cost(srt,srt[(sz(srt)-1)/2]);
                    ans+=min(x,y);
                }
            }
        }
        here:
        cout<< "Case #"<<T-t<< ": ";
        if (flag) cout<<ans<<endl;
        else cout<< "Fegla Won"<<endl;
    }
    return 0;
}
