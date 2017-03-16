#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxN (3005)
using namespace std;

typedef long long LL;
struct Tnode{
	int x,y,id,ans;
}a[maxN];

int N,limit;
int ans[maxN];
bool exist[maxN];
vector<int>stack;

bool cmp(Tnode a,Tnode b){
	if (a.x==b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}
bool valid(int i,int j,int k){
	int x1=a[j].x-a[i].x;
	int y1=a[j].y-a[i].y;
	int x2=a[k].x-a[i].x;
	int y2=a[k].y-a[i].y;
	return (LL)x1*y2-(LL)x2*y1<=0;
}
void update(int i){
	for (;;){
		int l=stack.size();
		if (l-limit>=2 && !valid(stack[l-2],stack[l-1],i)>0)
			stack.pop_back();
		else
			break;
	}
	stack.push_back(i);
}
void graham(){
	stack.clear();
	limit=0;
	for (int i=0;i<N;i++){
		if (!exist[i]) continue;
		update(i);
	}	
	limit=stack.size()-1;
	for (int i=N-2;i>=0;i--){
		if (!exist[i]) continue;
		update(i);
	}
//	int l=stack.size();
//	for (int i=0;i<l;i++)
//		printf("%d %d\n",a[stack[i]].x,a[stack[i]].y);
}
int main(){
	freopen("i.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int testcase=1;T--;testcase++){
		printf("Case #%d:\n",testcase);
		scanf("%d",&N);
		for (int i=0;i<N;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].id=i;
			a[i].ans=-1;
		}
		sort(a,a+N,cmp);
		memset(exist,true,sizeof(exist));
		graham();
		memset(ans,-1,sizeof(ans));
		int l=stack.size();
		for (int i=0;i<l;i++){
			a[stack[i]].ans=0;
		}
		for (int i=0;i<N;i++){
			if (a[i].ans!=-1) continue;
			int opt;
			for (int j=1;j<1<<N;j++){
				if (j&(1<<i)) continue;
				int tmp=0;
				for (int k=0;k<N;k++){
					if (j&(1<<k)) {
						exist[k]=false;
						tmp++;
					}
				}
				graham();
				int l=stack.size();
				bool ok=false;
				for (int k=0;k<l && !ok;k++)
					if (stack[k]==i) 
						ok=true;
				if (ok){
					if (a[i].ans==-1 || a[i].ans>tmp){
						a[i].ans=tmp;
						opt=j;
					}
				}
				for (int k=0;k<N;k++){
					if (j&(1<<k))
						exist[k]=true;
				}
			}
//			printf("%d %d\n",i,opt);
		}
		for (int i=0;i<N;i++)
			ans[a[i].id]=a[i].ans;
		for (int i=0;i<N;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
