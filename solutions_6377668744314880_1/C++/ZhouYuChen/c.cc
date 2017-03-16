#include<bits/stdc++.h>
using namespace std;
struct pt{
	int x,y;
	void read(){scanf("%d%d",&x,&y);}
};

vector<int> solve(vector<pt>& a){
	int n=a.size();
	if(n==1)return {0};
	int x[3072],y[3072],z[3072];
	for(int i=0;i<n;++i){
		x[i]=a[i].x;
		y[i]=a[i].y;
		z[i]=9999;
	}
	for(int i=0;i<n;++i){
		int ox=x[i],oy=y[i];
		for(int j=0;j<n;++j){
			x[j]-=ox;y[j]-=oy;
		}
		for(int j=i+1;j<n;++j){
			int a=0,b=0;
			for(int k=0;k<n;++k){
				long long t=(long long)x[j]*y[k]-(long long)x[k]*y[j];
				if(t>0)++a;
				if(t<0)++b;
			}
			a=min(a,b);
			z[i]=min(a,z[i]);
			z[j]=min(a,z[j]);
		}
	}
	return vector<int>(z,z+n);
}
int main(){
	int T;cin >>T;
	vector<int> a[100];
	vector<pt> input[100];
	for(int i=0,n;i<T;++i){
		scanf("%d",&n);
		input[i].resize(n);
		for(int j=0;j<n;++j)
			input[i][j].read();
	}
	#pragma omp parallel for
	for(int i=0;i<T;++i){
		cerr << i << " started" << endl;
		a[i]=solve(input[i]);
		cerr << i << " ended" << endl;
	}
	for(int i=0;i<T;++i){
		printf("Case #%d:\n",i+1);
		for(int x:a[i])printf("%d\n",x);
	}
}
