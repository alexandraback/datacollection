#include <stdio.h>
#include <algorithm>
#include <vector>

#define TEST_NUM 5

char inname[100];
char outname[100];

struct pos
{
	int x;
	int y;
	int t;
	bool operator <(const pos& a) const
	{
		return x!=a.x?x<a.x:y<a.y;
	}
};

typedef std::vector<pos> V;

inline long long cro(pos a,pos b,pos c)
{
	return 1LL*(b.x-a.x)*(c.y-a.y)-1LL*(c.x-a.x)*(b.y-a.y);
}

bool ltn(pos a,pos b,pos c)
{
	return cro(a,b,c)>0;
}

V make_con(V &arr)
{
	int s,i;
	V res;
	std::sort(arr.begin(),arr.end());
	res.push_back(arr[0]);
	res.push_back(arr[1]);
	for(i=2;i<arr.size();i++)
	{
		while(res.size()>=2&&ltn(res[res.size()-2],res[res.size()-1],arr[i]))
			res.pop_back();
		res.push_back(arr[i]);
	}
	res.push_back(arr[arr.size()-2]);
	s=res.size();
	for(i=arr.size()-3;i>=0;i--)
	{
		while(res.size()>=s&&ltn(res[res.size()-2],res[res.size()-1],arr[i]))
			res.pop_back();
		res.push_back(arr[i]);
	}
	res.pop_back();
	return res;
}

pos ori[15];
V sta,tmp;

int res[15];

int n;

void f(int x)
{
	if(x==n)
	{
		if(sta.size()<3)
			return;
		tmp=sta;
		tmp=make_con(tmp);
		int r=n-sta.size(),i;
		for(i=0;i<tmp.size();i++)
			res[tmp[i].t]=r<res[tmp[i].t]?r:res[tmp[i].t];
		return;
	}
	sta.push_back(ori[x]);
	f(x+1);
	sta.pop_back();
	f(x+1);
}

void process()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&ori[i].x,&ori[i].y);
		ori[i].t=i;
	}
	if(n<=3)
	{
		for(i=0;i<n;i++)
			printf("\n0");
		return;
	}
	for(i=0;i<n;i++)
		res[i]=n-3;
	f(0);
	for(i=0;i<n;i++)
		printf("\n%d",res[i]);
}

void pre_process()
{
}

int main()
{
	sprintf(inname,"%d.in",TEST_NUM);
	sprintf(outname,"%d.out",TEST_NUM);
	freopen(inname,"r",stdin);
	freopen(outname,"w",stdout);
	int tn,ti;
	scanf("%d",&tn);
	pre_process();
	for(ti=1;ti<=tn;ti++)
	{
		printf("Case #%d: ",ti);
		process();
		printf("\n");
	}
	return 0;
}