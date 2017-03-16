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
	ll operator *(const PT&b)const // dot
	{
		return 1ll*x*b.x+1ll*y*b.y;
	}
	ll len2()const
	{
		return x*x+y*y;
	}
}dot[30000];

int N;
const PT stu=PT(1,0);
bool cmp(const PT &pa,const PT &pb)
{
//	PT pa=a-mid, pb=b-mid;
	if(stu%pa>0 && stu%pb<0)
		return 1;
	if(stu%pa<0 && stu%pb>0)
		return 0;
	if(stu%pa==0 && stu*pa>0)
	{
		if(!(stu%pb==0 && stu*pb>0))
			return 1;
		return stu*pa<stu*pb;
	}
	if(stu%pb==0 && stu*pb>0)
		return 0;
	if(pa%pb!=0)
		return pa%pb>0;
	return pa.len2()<pb.len2();
}

vector<PT> use;

int main()
{
	int NumberOfTestcases;
	scanf("%d",&NumberOfTestcases);
	for(int CaseNumber=1;CaseNumber<=NumberOfTestcases;CaseNumber++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d%d",&dot[i].x,&dot[i].y),dot[i].id=i;
		printf("Case #%d:\n",CaseNumber);
		if(N==1)
		{
			puts("0");
			continue;
		}
		for(int i=0;i<N;i++)
		{
			int ans=123456;
			use.clear();
			for(int j=0;j<N;j++)
			{
				if(j==i)
					continue;
				use.pb(dot[j]-dot[i]);
			}
			sort(use.begin(),use.end(),cmp);
			assert(SZ(use)==N-1);
			for(int i=0;i<N-1;i++)
				use.pb(use[i]);
			int l=0,r=0;
			for(;l<N-1;l++)
			{
				if(r<=l)
					r=l+1;
				while(r<l+N-1 && (use[l]%use[r]>0 || (use[l]%use[r]==0 && use[l]*use[r]>0 && use[l].len2()<use[r].len2()) ))
					r++;
				ans=min(ans,r-l-1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
