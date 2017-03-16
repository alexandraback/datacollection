#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<ext/hash_map>
#include<ext/hash_set>
#include<set>
#include<string>
#include<assert.h>
#include<vector>
#include<time.h>
#include<queue>
#include<deque>
#include<sstream>
#include<stack>
#include<sstream>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.0000000001
#define Pi 3.1415926535897932384626433832795
using namespace std;
using namespace __gnu_cxx;
const long long  MO=1000000000+7;
const int INF=1000000000+7;
int n,m,i,j,k,A,l[1000],r,B,a[1000];
string s[1000];
int sol()
{
    string c,cc;
    c.clear();
    for (i=0;i<s[0].size();i++)
        if (i==s[0].size()-1 || s[0][i]!=s[0][i+1]) c+=s[0][i];
    for (j=1;j<n;j++){
    cc.clear();
    for (i=0;i<s[j].size();i++)
        if (i==s[j].size()-1 || s[j][i]!=s[j][i+1]) cc+=s[j][i];
    if (c!=cc) return -1;
    }
    int AN=0;
    for (i=0;i<n;i++) l[i]=0;
    while (l[0]<s[0].size())
    {
        for (i=0;i<n;i++)
        {
            r=l[i];
            l[i]++;
            while (l[i]<s[i].size() && s[i][l[i]]==s[i][l[i]-1]) l[i]++;
            a[i]=l[i]-r;
            }
        sort(a,a+n);
        for (i=0;i<n;i++)
            AN+=AB(a[i]-a[n/2]);
    }
    return AN;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("text.txt","w",stdout);
    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
            cin>>n;
    for (i=0;i<n;i++) cin>>s[i];
    k=sol();
    cout<<"Case #"<<tt<<": ";
    if (k==-1) cout<<"Fegla Won"<<endl; else cout<<k<<endl;
    }
    return 0;
}
