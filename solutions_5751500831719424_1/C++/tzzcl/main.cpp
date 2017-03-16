#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
const int inf=1e9+7;
const long long linf=1e18;
const double pi=acos(-1.0);
typedef long double lf;
typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
template <class T> T sqr(T x){return x*x;}
const double eps = 1e-10;//µÈÓÚ0
#define N 122
char a[N][N],b[N][N];
int cnt[N][N],l[N];
int n;
int gao()
{
    for(int i=1;i<=n;i++)
    {
        b[i][l[i]=1]=a[i][0];
        cnt[i][l[i]]=1;
        for(int j=1;a[i][j];j++)
            if(a[i][j]==a[i][j-1])
                cnt[i][l[i]]++;
            else
            {
                b[i][++l[i]]=a[i][j];
                cnt[i][l[i]]=1;
            }
    }
    for(int i=1;i<n;i++)
    {
        if(l[i]!=l[i+1])
            return -1;
        for(int j=1;j<=l[i];j++)
            if(b[i][j]!=b[i+1][j])
                return -1;
    }
    int ans=0;
    for(int j=1;j<=l[1];j++)
    {
        int t=inf;
        for(int k=1;k<=100;k++)
        {
            int s=0;
            for(int i=1;i<=n;i++)
                s+=abs(cnt[i][j]-k);
            t=min(t,s);
        }
        ans+=t;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;cin>>t;
	for (int tt=1;tt<=t;tt++){
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		cout<<"Case #"<<tt<<": ";
		int f=gao();
		if (f<0) cout<<"Fegla Won"<<endl;
		else cout<<f<<endl;
	}
	//system("pause");
	return 0;
}