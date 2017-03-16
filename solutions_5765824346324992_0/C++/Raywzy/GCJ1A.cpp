#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int T,counter=0;
int B,N;
int F[1005];
class Node
{
public:
	int now;
	int idx;
};
bool operator<(Node a,Node b)
{
	if(a.now==b.now)
		return a.idx>b.idx;
	return a.now>b.now;
}
int main()
{
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	int i,bei=1;
	int MOD,ans;
	scanf("%d",&T);
	while(T--)
	{
		priority_queue<Node> q;bei=1;MOD=0;counter++;
		scanf("%d%d",&B,&N);
		for(i=1;i<=B;i++)
			scanf("%d",&F[i]);
		Node temp,K;
		for(i=1;i<=B;i++)
		{
			if(bei%F[i]) bei*=F[i];
		}
		for(i=1;i<=B;i++)
			MOD+=bei/F[i];
		N%=MOD;if(N==0) N=MOD;
		for(i=1;i<=N;i++)
		{
			if(i<=B)
			{
				temp.idx=i;temp.now=F[i];ans=temp.idx;
				q.push(temp);
			}
			temp=q.top();
			K.idx=temp.idx;K.now=temp.now+F[K.idx];ans=K.idx;
			q.pop();q.push(K);
		}
		printf("Case #%d: %d\n",counter,ans);
	}
	return 0;
}
