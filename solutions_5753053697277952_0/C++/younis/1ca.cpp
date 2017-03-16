#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
    int id,p;
    bool operator<(const node &rhs)const{
        return p<rhs.p;
    }
};
int main(){
	freopen("A-small-attempt0.bin","r",stdin);
	freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	int n,i,sum;
	node u,v;
	priority_queue<node>pq;
	for(int cas=1;cas<=t;cas++){
        scanf("%d",&n);
        while(!pq.empty())pq.pop();
        sum=0;
        for(i=0;i<n;i++){
            u.id=i;
            scanf("%d",&u.p);
            sum+=u.p;
            pq.push(u);
        }
        printf("Case #%d:",cas);
        while(sum){
            u=pq.top();
            pq.pop();
            v=pq.top();
            pq.pop();
            if(v.p*2<=sum-1){
                sum--;
                printf(" %c",'A'+u.id);
                u.p--;
            }
            else{
                sum-=2;
                printf(" %c%c",'A'+u.id,'A'+v.id);
                u.p--;v.p--;
            }
            pq.push(u);pq.push(v);
        }
        printf("\n");
	}
	return 0;
}
