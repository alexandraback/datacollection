#include <cstdio>
#include <queue>
#define MAXN 10
using namespace std;

// GCD
int gcd(int a,int b)
{
	if(!a) return b;
	if(!b) return a;
	if(a>b) return gcd(a%b,b);
	return gcd(a,b%a);
}

// LCM
int lcm(int a,int b)
{
	int gg;
	gg=gcd(a,b);
	return (a/gg)*b;
}

struct NODE{
  int id, t, plus;
  bool operator<(const NODE& y)const
  {
    // Compare cp1 than cp2
    if(this->t==y.t) return this->id>y.id;
    return this->t>y.t;
  }
};
priority_queue<NODE>minHeap;

// Barbers
int bar[MAXN];

// Main
int main(void)
{
	int tc, cs, B, N, i, L, tot;
	NODE tmp, head;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d%d",&B,&N);
		for(i=0;i<B;i++)
			scanf("%d",&bar[i]);

		// Output
		printf("Case #%d: ",cs);

		// N<=B
		if(N<=B) printf("%d\n",N);
		else
		{
			L=bar[0];
			for(i=1;i<B;i++)
				L=lcm(bar[i],L);
			tot=0;
			for(i=0;i<B;i++)
				tot+=(L/bar[i]);
			N=(N-1)%tot;
			// Simulate
			for(i=0;i<B;i++)
			{
				tmp.id=i+1;
				tmp.t=0;
				tmp.plus=bar[i];
				minHeap.push(tmp);
			}
			for(i=0;i<N;i++)
			{
				head=minHeap.top();
				minHeap.pop();
				head.t+=head.plus;
				minHeap.push(head);
			}
			head=minHeap.top();
			printf("%d\n",head.id);
			// Clear
			while(!minHeap.empty()) minHeap.pop();
		}
	}
	return 0;
}