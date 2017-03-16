#include <bits/stdc++.h>
#define mpr std::make_pair
typedef long long ll;
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
string s[400];
string s1[400];
vector<int> v[400];
int d[400];
int abs(int i)
{
    if(i>=0)return i;
    return -i;
}
void get(int i)
{
    s1[i].push_back(s[i][0]);
    v[i].push_back(1);
    for(int j=1;j<s[i].size();j++)
    {
        if(s[i][j] != s1[i][s1[i].size()-1])
        {s1[i].push_back(s[i][j]);v[i].push_back(1);}
        else
        {
            v[i][v[i].size()-1]++;
        }
    }
}
int main()
{
    freopen("out.txt","w",stdout);
    int i,j,k;
    int t,r;
    int n;
    r=1;
    bool f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            s1[i].clear();
            v[i].clear();
            get(i);
        }
        f=true;
        for(i=1;i<n;i++)
        {
            if(s1[i]!=s1[0])
            {
                f=false;
                break;
            }
        }
        cout<<"Case #"<<r<<": ";
        r++;
        if(f==false)
        {
            cout<<"Fegla Won\n";
            continue;
        }
        int x,y,ans;
        ans = 0;
        for(i=0;i<v[0].size();i++)
        {
            y=1000000;
            for(j=1;j<=100;j++)
            {
                x=0;
                for(k=0;k<n;k++)
                {
                    x+=abs(j-v[k][i]);
                }
                if(x<y){
                    d[i]=j;
                    y=x;
                }
            }
            ans+=y;
        }
//        for(i=0;i<v[0].size();i++)
//        {
//            cout<<v[0][i]<<' ';
//        }
//        cout<<endl;
//        for(i=0;i<v[1].size();i++)
//        {
//            cout<<v[1][i]<<' ';
//        }
//        cout<<endl;
//        for(i=0;i<v[0].size();i++)
//        {
//            cout<<d[i]<<' ';
//        }
//        cout<<endl;
       cout<<ans<<endl;

    }
}

/*
100
2
xxolyhttosszmssotttozlqjszizzuwbllnnuvvkiigipczjdlcrgvhhffggzraaazaxxxxddikqcchdmmqneeummnn
xoolyhtoszmsottoozlqqjsziizuwblnnuvkigipczjdllcrrgggvhfgzraazaaxxxdikqchdmqneummnn


*/
