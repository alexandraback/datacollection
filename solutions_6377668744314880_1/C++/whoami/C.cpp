#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, print;
struct q{
	double gi;
	bool dir;
	int x,y;
	bool operator() (q a,q b){
		return a.gi<b.gi;
	}
}su[3001];
struct q2{
	int x,y;
}xy[3001];
inline bool issame(double a, double b){
	return fabs(a-b)<=1e-9;
}
void pro(int x,int y){
	int i, cnt=0, line=0, sum=0;
	for(i=0;i<n-1;i++){
		if(su[i].y==y){
			line++;
			sum+=!su[i].dir;
			continue;
		}
		cnt+=su[i].dir;
	}
	print = min(cnt,n-1-cnt-line);
	cnt+=sum;
	line=0;
	for(i=0;i<n-1;){
		if(su[i].gi>0 && !issame(0,su[i].gi)){
			line=0;
			int j,sum=0;
			for(j=i;j<n-1;j++){
				if(issame(su[i].gi,su[j].gi)){
					line++;
					cnt+=su[j].dir?-1:0;
					sum+=su[j].dir?0:1;
				}
				else break;
			}
			print = min(print, min(cnt,n-1-cnt-line));
			cnt+=sum;
			i=j;
		}
		else i++;
	}
	for(i=0;i<n-1;){
		if(su[i].gi<0 && !issame(0,su[i].gi)){
			line=0;
			int j,sum=0;
			for(j=i;j<n-1;j++){
				if(issame(su[i].gi,su[j].gi)){
					line++;
					cnt+=su[j].dir?-1:0;
					sum+=su[j].dir?0:1;
				}
				else break;
			}
			print = min(print, min(cnt,n-1-cnt-line));
			cnt+=sum;
			i=j;
		}
		else i++;
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);

	for(int test=1; test<=testt; test++){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&xy[i].x,&xy[i].y);
		}
		printf("Case #%d:\n",test);
		for(int i=0;i<n;i++){
			int c=0;
			print=n;
			for(int j=0;j<n;j++){
				if(i==j) continue;
				su[c].x=xy[j].x;
				su[c].y=xy[j].y;
				if(xy[j].x==xy[i].x){
					su[c].gi=1e10;
					su[c++].dir=xy[i].y<xy[j].y;
				}
				else if(xy[j].y==xy[i].y){
					su[c].gi=0;
					su[c++].dir=xy[i].x<xy[j].x;
				}
				else{
					su[c].gi=1.0*(xy[j].y-xy[i].y)/(xy[j].x-xy[i].x);
					su[c++].dir=xy[i].y<xy[j].y;
				}
			}
			std::sort(su,su+(n-1),q());
			pro(xy[i].x,xy[i].y);
			printf("%d\n",print);
		}
	}
	return 0;
}
