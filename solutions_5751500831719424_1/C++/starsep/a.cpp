#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#define scanf(args...) scanf(args) ? : 0
using namespace std;
const int MAX=112;
queue<char> S[MAX];
char s[MAX][MAX];
long long w;
int n;
int abs(int x)
{
	if(x<0)return -x;
	return x;
}
int check()
{
	bool emt=false;
	for(int i=0;i<n;i++)
		emt|=S[i].empty();
	if(!emt)return 1;
	for(int i=0;i<n;i++)
		if(!S[i].empty())
			return -1;
	return 0;
}
int make_move()
{
	int t=check();
	if(t<1)return t;
	vector<int> V(n);
	char c=S[0].front();
	S[0].pop();
	V[0]=1;
	while(!S[0].empty() && S[0].front()==c)
	{
		S[0].pop();
		V[0]++;
	}
	for(int i=1;i<n;i++)
	{
		if(S[i].front()!=c)return -1;
		V[i]=0;
		while(!S[i].empty() && S[i].front()==c)
		{
			S[i].pop();
			V[i]++;
		}
	}
	int q=1e9;
	int qq;
	for(int i=0;i<n;i++)
	{
		qq=0;
		for(int j=0;j<n;j++)
			qq+=abs(V[i]-V[j]);
		if(qq<q)
			q=qq;
	}
	w+=q;
	return 1;
}
void clear()
{
	for(int i=0;i<n;i++)
		while(!S[i].empty())
			S[i].pop();
}
void solve()
{
	scanf("%d",&n);
	clear();
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		int m=strlen(s[i]);
		for(int j=0;j<m;j++)
			S[i].push(s[i][j]);
	}
	w=0;
	int t=1;
	while(t>0)
		t=make_move();
	if(t==-1)
		printf("Fegla Won\n");
	else printf("%lld\n",w);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}