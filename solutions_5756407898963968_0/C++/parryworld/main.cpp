#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#define mp make_pair
#define pb push_back
#define SCAN(n) scanf("%d",&n)
#define SCAN2(a,b) scanf("%d%d",&a,&b)
#define SCANS(a) scanf("%s",a)
#define PRINT(n) printf("%d\n",n)
#define sqr(a) ((a)*(a))
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N=1200010;
const int M=3000010;
const int INF=1e9;
const int MOD=1e9+7;
const double eps=1e-6;

int a[5][5],b[5][5];
int vis[20];

void solve(){
	int t;
	cin>>t;
	for(int cs=1;cs<=t;cs++){
		int x1,x2;
		cin>>x1;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++) cin>>a[i][j];
		cin>>x2;
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++) cin>>b[i][j];
		CLR(vis,0);
		for(int i=1;i<=4;i++){
			vis[a[x1][i]]++;
			vis[b[x2][i]]++;
		}
		int num=0,ans;
		for(int i=1;i<=16;i++)
			if(vis[i]==2){
				num++;
				ans=i;
			}
		cout<<"Case #"<<cs<<": ";
		if(num==0) cout<<"Volunteer cheated!"<<endl;
		else if(num>1) cout<<"Bad magician!"<<endl;
		else cout<<ans<<endl;
	}
}

int main()
{
   	freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    //ios :: sync_with_stdio(false);
    solve();
    return 0;
}
