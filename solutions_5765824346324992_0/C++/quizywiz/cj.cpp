#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define lli long long int
int t,itt;
lli n,b;
lli a[1001];
bool cando(lli mid)
{
	if(mid==0)return b>=n;
	if(mid==-1)return false;
	lli num=0;
	for(int i=0;i<b;++i)
	{
		num++;
		num += mid/a[i];
	}
//	cout<<"num"<<" "<<num<<endl;
	return num>=n;
}
lli srch()
{
	lli low = 0, high = 100000ll*(n+1),mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		bool md = cando(mid);
		bool md1 = cando(mid-1);
	//	cout<<low<<" "<<mid<<" "<<high<<endl;
		if(md && !md1)return mid;
		else if(md && md1) high = mid-1;
		else low = mid + 1;
	}
	cout<<itt<<" "<<n<<endl;
	assert(false);
}
int main() {
	// your code goes here
	sc(t);
	rep(itt,1,t+1)
	{
		cout<<"Case #"<<itt<<": ";
		cin>>b>>n;
		repi(i,0,b)cin>>a[i];

		lli tim = srch();
		for(int i=0;i<b;++i)
		{
			n-= 1+(tim-1)/a[i];
		}
		for(int i=0;i<b;++i)
		{
			n-= (tim)/a[i] - (tim-1)/a[i] ;
			if(n<=0)
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}
	return 0;
}