#include<stdio.h>
#include<vector>
#include<cmath>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAX=3005;
struct point
{
	int x,y,id;     
};
point points[MAX],res[MAX],cp[MAX];

bool mult(const point sp,const point ep,const point op)
{
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);     
}
bool mult3(const point sp,const point ep,const point op)
{
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y) + 0.0000001;     
}
bool mult1(const point sp,const point ep,const point op)
{
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y) - 0.0000001;     
}
bool mult2(const point sp,const point ep,const point op)
{
	return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y) - 0.0000001 && (sp.x-op.x)*(ep.y-op.y)<=(ep.x-op.x)*(sp.y-op.y) + 0.0000001;     
}

bool operator < (const point &l, const point &r)
{
	return l.y<r.y||(l.y==r.y&&l.x>r.x);
}

long long dis(point a, point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int graham(point pnt[], int n, point res[])
{
	int i,len,k=0,top=1;
	sort(pnt, pnt+n );
	if(n==0)return 0; res[0]=pnt[0];
	if(n==1)return 1; res[1]=pnt[1];
	if(n==2)return 2; 
	bool ch[3100] = {0,};
	for(i=2; i<n; i++)
	{
		while(top&&mult3(pnt[i],res[top],res[top-1])){
			ch[res[top].id] = false;
			top--;
		}
		res[++top]=pnt[i];
		ch[res[top].id] = true;
	}
	len=top;  res[++top]=pnt[n-2];
	for(i=n-2; i >=0; i--){
		if(pnt[i].y != pnt[i+1].y) break;
	}
	for(; i>=0; i--)
	{
		while(top!=len&&mult(pnt[i],res[top],res[top-1]))
			top--;
		res[++top]=pnt[i];
	}
	return top;
}
int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		int n;
		int ans[3100]={0,};
		memset(res, 0, sizeof(res));
		memset(points, 0, sizeof(points));
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%ld%d", &points[i].x, &points[i].y);
			points[i].id = i;
			cp[i] = points[i];
		}
		printf("Case #%d:\n", tc);

		int top=graham(points, n, res);

		for(int i = 0; i < n; i++){
			int min = 987654321;
			if(points[i].id == 5)
				i=i;
			for(int j = 0; j < top; j++){
				bool flag = false;
				for(int k = 0; k < top; k++){
					if(mult2(res[(k+1)%top], points[i], res[k])){
						flag = true;
						break;
					}
				}
				if(flag){
					min = 0;
					break;
				}

				int lj = (j+1)%top;
				for(int k = j+2; k < j+top; k++){
					int kk = k%top;
					if(mult(res[j], points[i], res[kk])){
						break;
					}
					lj = kk;
				}
				vector<int> list;
				if(j <= lj) {
					for(int k = j; k <=lj; k++)
						list.push_back(res[k].id);
				}
				else{
					for(int k = j; k < top; k++)
						list.push_back(res[k].id);
					for(int k = 0; k <= lj; k++)
						list.push_back(res[k].id);
				}
				list.push_back(points[i].id);
				int len = (int)list.size()-1;
				int cut=0;
				for(int k = 0; k < n; k++){
					for(int l = 0; l < len; l++){
						if(!mult1(cp[list[l]], cp[list[l+1]], cp[k])){
							cut++;
							break;
						}
					}
				}
				if(min > cut) min = cut;
			}
			ans[points[i].id] = min;
		}
		for(int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
		//printf("%d %d %d %d\n", res[ii].x, res[ii].y, res[jj].x, res[jj].y);
		//printf("Case #%d: %d %d\n", tc, c1, c2);
	}

	return 0;
}

