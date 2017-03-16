#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
	long long x,y;
	node(long long _x=0,long long _y=0) : x(_x),y(_y) {}
	~node() {}
	node operator+(const node& rhs) const
	{
		return node(x+rhs.x,y+rhs.y);
	}
	node operator-(const node& rhs) const
	{
		return node(x-rhs.x,y-rhs.y);
	}
	long long operator*(const node& rhs) const
	{
		return x*rhs.x+y*rhs.y;
	}
	long long operator^(const node& rhs) const
	{
		return x*rhs.y-y*rhs.x;
	}
	bool operator==(const node& rhs) const
	{
		return x==rhs.x && y==rhs.y;
	}
}pos[3005],all[6005];

bool cmp(node a, node b)
{
	if((a.x>0 || (a.x==0 && a.y<0)) && b.x<0) return true;
	if((b.x>0 || (b.x==0 && b.y<0)) && a.x<0) return false;
	return (a^b)>0;
}


int main()
{
	freopen("C-large.in","r",stdin);
	freopen("pc.out","w",stdout);
	int cas;
	int n,n2;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%d",&n);
		n2=n*2;
		for(int i=0; i<n; i++){
			scanf("%I64d %I64d",&all[i].x,&all[i].y);
			pos[i]=all[i];
		}
		printf("Case #%d:\n",T);
		if(n==1){
			printf("0\n");
			continue;
		}
		for(int i=0; i<n; i++){
			for(int j=0,k=0; j<n; j++){
				if(j==i) continue;
				all[k++]=pos[j]-pos[i];
			}
			n--;
			n2=n*2;
			sort(all,all+n,cmp);
			for(int j=0; j<n; j++){
				all[j+n]=all[j];
			}
			queue<node> que;
			int ans=n+1;
			que.push(all[0]);
			for(int j=1; j<n2; j++){
				node tmp=que.front();
				if(tmp==all[j]){
					ans=0;
					break;
				}
				long long cross=tmp^all[j];
				if(cross>0 || (cross==0 && tmp*all[j]>0)){
					que.push(all[j]);
				}else{
					while(cross<0){
						que.pop();
						if(que.empty())
							break;
						tmp=que.front();
						cross=tmp^all[j];
					}
					while(cross==0 && tmp*all[j]<0){
						que.pop();
						if(que.empty())
							break;
						tmp=que.front();
						cross=tmp^all[j];
					}
					if(ans>que.size())
						ans=que.size();
					que.push(all[j]);
				}
			}
			n++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
