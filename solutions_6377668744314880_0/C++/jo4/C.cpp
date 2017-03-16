#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

struct PT{
	int x,y,id;
	PT(int _x=0,int _y=0): x(_x),y(_y) {}
	PT operator -(const PT&b)const
	{
		return PT(x-b.x,y-b.y);
	}
	ll operator %(const PT&b)const // cross
	{
		return 1ll*x*b.y-1ll*y*b.x;
	}
	bool operator < (const PT&b)const
	{
		if(x!=b.x)
			return x<b.x;
		return y<b.y;
	}
}dot[100];

int ans[100];
int N;

vector<PT> use;
PT tmp[100],st[100];
int top;

void check()
{
	int num=0;
	for(PT x:use)
		tmp[num++]=x;
	assert(num==SZ(use));
	std::sort(tmp,tmp+num);
	top=-1;
	for(int i=0;i<num;i++)
	{
		while(top>=1 && ((st[top]-st[top-1])%(tmp[i]-st[top]))<0)
			top--;
		st[++top]=tmp[i];
	}
	for(int i=0;i<=top;i++)
		ans[st[i].id]=min(ans[st[i].id],N-num);
	top=-1;
	for(int i=num-1;i>=0;i--)
	{
		while(top>=1 && ((st[top]-st[top-1])%(tmp[i]-st[top]))<0)
			top--;
		st[++top]=tmp[i];
	}
	for(int i=0;i<=top;i++)
		ans[st[i].id]=min(ans[st[i].id],N-num);
}

void run(int l)
{
	if(l==N)
	{
		check();
		return;
	}
	run(l+1);
	use.pb(dot[l]);
	run(l+1);
	use.pop_back();
}

int main()
{
	int NumberOfTestcases;
	scanf("%d",&NumberOfTestcases);
	for(int CaseNumber=1;CaseNumber<=NumberOfTestcases;CaseNumber++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d%d",&dot[i].x,&dot[i].y),dot[i].id=i;
		fill(ans,ans+N,123456);
		use.clear();
		run(0);
		printf("Case #%d:\n",CaseNumber);
		for(int i=0;i<N;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
