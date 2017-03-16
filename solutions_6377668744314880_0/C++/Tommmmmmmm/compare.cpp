#include<bits/stdc++.h>
using namespace std;
const int Maxn=22;
typedef long long Int;
int n;
int rep[Maxn],xx[Maxn],yy[Maxn],sta[Maxn];
bool cmp(int a,int b)
{
	if(xx[a]!=xx[b])return xx[a]<xx[b];
	return yy[a]<yy[b];
}
int cross(int a,int b,int c)
{
	Int x11=xx[b]-xx[a],y11=yy[b]-yy[a];
	Int x22=xx[c]-xx[b],y22=yy[c]-yy[b];
	Int t=x11*y22-x22*y11;
	if(t>0)return 1;
	if(t<0)return -1;
	return 0;
}
void solve(int code)
{
	vector<int>V;
	for(int i=0;i<n;i++)
		if((code>>i)&1)
			V.push_back(i+1);
	if(V.size()<=3)
	{
		for(int i=0;i<V.size();i++)
			rep[V[i]]=min(rep[V[i]],n-(int)V.size());
		return ;
	}
	sort(V.begin(),V.end(),cmp);
	int top=0;
	for(int i=0;i<V.size();i++)
	{
		while(top>1&&cross(sta[top-1],sta[top],V[i])<0)top--;
		sta[++top]=V[i];
	}
	int k=top;
	for(int i=V.size()-1;i>=0;i--)
	{
		while(top-k>=1&&cross(sta[top-1],sta[top],V[i])<0)top--;
		sta[++top]=V[i];
	}
	for(int i=1;i<=top;i++)
		rep[sta[i]]=min(rep[sta[i]],n-(int)V.size());
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int _,cs=1;scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d",xx+i,yy+i),rep[i]=n-1;
		for(int i=1;i<(1<<n);i++)
			solve(i);
		printf("Case #%d:\n",cs++);
		for(int i=1;i<=n;i++)
			printf("%d\n",rep[i]);
	}
}
