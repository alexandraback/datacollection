#include<cstdlib>
#include<cstdio>
#include<vector>
typedef long long ll;
using namespace std;	
struct point{
	ll x, y;
	point(ll xx,ll yy){
		x = xx;y=yy;
	}
	point(){}
}tree[4000];

int cross(const point &a, const point &b, const point &c){
	point t1 = point(b.x-a.x,b.y-a.y),t2=point(c.x-a.x,c.y-a.y);
	ll t= t2.y*t1.x - t1.y*t2.x;
	if(t>0)
		return 1;
	if(t < 0)
		return -1;
	return 0;
}
int ans[5000],n;
void work()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%lld%lld",&tree[i].x,&tree[i].y);
	for(int i = 0; i < n; i++){
		ans[i]= n;
		for (int j = 0; j < n;j++){
			if(j ==i)
				continue;
			int pos = 0, neg = 0;
			for (int k = 0; k < n; k++){
				if(k==i ||k==j)
					continue;
				int t = cross(tree[i],tree[j],tree[k]);
				if (t>0)pos++;
				if (t < 0)neg++;
			}
			//printf("%d %d\n",pos,neg);
			if(ans[i] > pos) ans[i]=pos;
			if (ans[i] > neg)ans[i] = neg;
		}
	}
	printf("\n");
	if(n==1)ans[0]=0;
	for(int i =0; i < n;i++)printf("%d\n",ans[i]);
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i = 1; i <=T; i++){
		printf("Case #%d:", i);
		work();		
	}
	return 0;
}