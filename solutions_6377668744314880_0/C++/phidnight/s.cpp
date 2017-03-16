#include <cstdio>
#include <cstdlib>

int T,N,centerid;
int xs[3008];
int ys[3008];
int incl[3008];
int query[8008];
int pos_type(int vx,int vy) {
	if(vx>0&&vy<0) return 4;
	if(vy<0) return 3;
	if(vx<0) return 2;
	return 1;
}
int cmp(const void *ka,const void *kb) {
	int a=*(int *)ka;
	int b=*(int *)kb;
	int a_dx,a_dy,b_dx,b_dy;
	if(a<0) {
		a_dx=xs[centerid]-xs[-a];
		a_dy=ys[centerid]-ys[-a];
	} else {
		a_dx=xs[a]-xs[centerid];
		a_dy=ys[a]-ys[centerid];
	}
	if(b<0) {
		b_dx=xs[centerid]-xs[-b];
		b_dy=ys[centerid]-ys[-b];
	} else {
		b_dx=xs[b]-xs[centerid];
		b_dy=ys[b]-ys[centerid];
	}
	if(pos_type(a_dx,a_dy)!=pos_type(b_dx,b_dy)) return pos_type(a_dx,a_dy)-pos_type(b_dx,b_dy);
	if((long long)b_dx*a_dy-(long long)a_dx*b_dy!=0) {
		if((long long)b_dx*a_dy-(long long)a_dx*b_dy>0) return 1;
		return -1;
	}
	return a-b;
}
int main() {
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		printf("Case #%d:\n",tn);
		scanf("%d",&N);
		for(int i=1;i<=N;i++) scanf("%d%d",&xs[i],&ys[i]);
		for(int center=1;center<=N;center++) {
			int ttl=0;
			for(int i=1;i<=N;i++) {
				incl[i]=0;
				if(i!=center) {
					query[ttl++]=i;
					query[ttl++]=-i;
				}
			}
			centerid=center;
			qsort(query,ttl,sizeof(int),cmp);
			int sum=0;
			for(int i=0;i<ttl;i++) {
				if(query[i]>0) {
					incl[query[i]]=1;
					sum++;
				} else {
					if(incl[-query[i]]) {
						incl[-query[i]]=0;
						sum--;
					}
				}
			}
			int sol=N-1;
			for(int i=0;i<ttl;i++) {
				if(sol>sum) sol=sum;
				if(query[i]>0) {
					incl[query[i]]=1;
					sum++;
				} else {
					if(incl[-query[i]]) {
						incl[-query[i]]=0;
						sum--;
					}
				}
			}
			printf("%d\n",sol);
		}
	}
	return 0;
}
