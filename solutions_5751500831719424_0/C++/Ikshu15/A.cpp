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
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m,t;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("OutA.txt","w",stdout);
    cin>>t;
    int T=t;
    while(t--)
    {
        string a,b;
        cin>>n>>a>>b;
        vector<pair<char,int> > v1=rle(a),v2=rle(b);
        //fori(0,sz(v1)-1) cout<<v1[i].aa<< " "<<v1[i].bb<<endl;
        //fori(0,sz(v2)-1) cout<<v2[i].aa<< " "<<v2[i].bb<<endl;
        int flag=1;
        int ans=0;
        if (sz(v1)!=sz(v2))
        {
            flag=0;
            goto here;
        }
        else
        {
            fori(0,sz(v1)-1)
            {
                if (v1[i].aa!=v2[i].aa)
                {
                    flag=0;
                    goto here;
                }
                else ans+=abs(v1[i].bb-v2[i].bb);
            }
        }
        here:
        cout<< "Case #"<<T-t<< ": ";
        if (flag) cout<<ans<<endl;
        else cout<< "Fegla Won"<<endl;
    }
    return 0;
}
