#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int Inf=1<<30,S=20,x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,r,c,ans=Inf,a[S][S]={};
void init()
{
	cin>>r>>c>>n;
	ans=Inf;
}
int calc()
{
	int sum=0;
	for(int i=1;i<=r;++i)
		for(int j=1;j<=c;++j)
			for(int k=0;k<4;++k)
				sum+=a[i][j]*a[i+x_[k]][j+y_[k]];
	return sum/2;
}
void tryy(int x,int y,int t)
{
	if(t==0)
		ans=min(ans,calc());
	if(t==0 || x>r)
		return;
	a[x][y]=1;
	if(y==c)
		tryy(x+1,1,t-1);
	else
		tryy(x,y+1,t-1);
	a[x][y]=0;
	if(y==c)
		tryy(x+1,1,t);
	else
		tryy(x,y+1,t);
}
int main()
{	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase)
	{
		init();
	tryy(1,1,n);
		cout<<"Case #"<<testcase<<": "<<ans<<endl;
	}
	return 0;
}
