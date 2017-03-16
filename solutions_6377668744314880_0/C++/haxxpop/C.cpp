#include<stdio.h>
#include<algorithm>
using namespace std;
int tabx[100000];
int taby[100000];

int xx[10000];
int yy[10000];
int tx[10000];
int ty[10000];
int num;
int ind[1000];
int st[1000];
int top;
int base;
int crossL(int xb,int yb,int x1,int y1,int x2,int y2){
	return (x1-xb)*(y2-yb)-(x2-xb)*(y1-yb);
}
int cmp(int a,int b){
//	return (xx[a]-xx[base])*(yy[b]-yy[base])
//				-(xx[b]-xx[base])*(yy[a]-yy[base]) > 0;
	return crossL(xx[base],yy[base],xx[a],yy[a],xx[b],yy[b]) > 0 ;
}
int convexhull(){
	top = -1;
	for(int i = 0 ;i< num ;i++ ) ind[i] = i;
	int pos = 0;
	int minn = yy[0];
	for(int i = 0 ; i < num ; i++ ){
		if( yy[i] < minn ){
			minn = yy[i];
			pos = i;
		}
	}
	base = pos;
	ind[0] = base;
	ind[base] = 0;
	sort(ind+1,ind+num,cmp);
	for(int i = 0; i < num ; i++ ){
		tx[i] = xx[ind[i]];
		ty[i] = yy[ind[i]];
	}
	tx[num] = tx[0];
	ty[num] = ty[0];
	num++;
	/*printf("--\n");
	for(int i = 0 ; i<num ; i++ ){
		printf("%d %d\n",tx[i],ty[i]);
	}
	printf("\n");*/
	for(int k = 0 ; k < num ; k++ ){
		for(; top >=1 ; ){
			if( crossL(tx[st[top-1]],ty[st[top-1]],tx[st[top]],ty[st[top]],tx[k],ty[k])	>= 0 ){
				break;	
			}else{
				//printf("del %d %d\n",st[top],k);
				top--;
			}
		}
		top++;
		st[top] = k;
	}
	/*
	for(int i = 0; i <= top ; i++ ){
		printf("c %d %d\n",tx[st[i]],ty[st[i]]);
	}
	printf("\n");
	*/
}

int n;
int tmp[1000];
int must ;
int minn = 1000;
int rec(int k){
	if( k == n ){
		num = 0;
		for(int i = 0 ;i< n ;i++ ){
			if( tmp[i] == 1 ){
				xx[num] = tabx[i];
				yy[num] = taby[i];
				num++;
			}
		}
		convexhull();
		int chk = 0;
		for(int i = 0 ; i < top ; i++ ){
			if( tabx[must] == tx[st[i]] && taby[must] == ty[st[i]] ) chk = 1;
			if( crossL(tabx[must],taby[must],tx[st[i]],ty[st[i]],tx[st[i+1]],ty[st[i+1]]) == 0 ) chk = 1;
		}
		int cur = 0;
		for(int i = 0 ;i < n ; i++ ){
			if( tmp[i] == 0 ) cur++;
		}
		if( cur == 0 && must == 3 ){
			//for(int i = 0 ;i <= top ; i++ ) printf("%d %d\n",tx[st[i]],ty[st[i]]);
		}

		if( chk == 1 ){
			if( cur < minn ) minn = cur;
		}
		return 0;
	}

	tmp[k] = 0;
	if( k == must );
	else rec(k+1);
	tmp[k] = 1;
	rec(k+1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ;e< t ; e++){
		scanf("%d",&n);
		for(int i = 0 ;i < n ; i++ ) scanf("%d %d",&tabx[i],&taby[i]);

		printf("Case #%d:\n",e+1);
		for(int k = 0 ; k < n ; k++ ){
			must = k;
			minn = 1000;
			rec(0);
			printf("%d\n",minn);
		}



		for(int i = 0; i <n ; i++ ){
			xx[i] = tabx[i];
			yy[i] = taby[i];
		}
		num= n;
		convexhull();
		/*printf(" end\n");
		for(int i = 0 ; i<=top ;i++ ) printf("%d %d\n",tx[st[i]],ty[st[i]]);*/
	}
}
