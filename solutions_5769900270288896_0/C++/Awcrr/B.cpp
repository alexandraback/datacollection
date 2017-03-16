#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int ret,r,c,n,T,tmp;

int cnt(int x){
	int ans = 0;
	while(x){
		if(x & 1) ++ ans;
		x >>= 1;
	}
	return ans;
}

int calc(int x){
	int ans = 0;
	for(int i = 0;i < r;++ i)
		for(int j = 0;j < c;++ j)
		if((x >> (i * c + j)) & 1){
			if(i > 0 && ((x >> ((i - 1) * c + j)) & 1))
				++ ans;
			if(j > 0 && ((x >> (i * c + j - 1)) & 1))
				++ ans;
		}
	return ans;
}

int main(){
	freopen("inputb","r",stdin); freopen("out1","w",stdout);
	scanf("%d",&T);
	for(int Cas = 1;Cas <= T;++ Cas){
		printf("Case #%d: ",Cas);
		scanf("%d%d%d",&r,&c,&n);
		ret = ~0U>>2;
		for(int i = 0,lim = (1 << (r * c));i < lim;++ i){
			if(cnt(i) == n && (tmp = calc(i)) < ret)
				ret = tmp;
		}
		printf("%d\n",ret);
	}
	return 0;
}
