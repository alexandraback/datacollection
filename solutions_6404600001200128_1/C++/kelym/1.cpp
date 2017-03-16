	#include <cstdio>
	int main(){
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
		int tt;
		scanf("%d",&tt);
		for(int _t=1;_t<=tt;++_t){
			int n,ins[1000],a=0,b=0,cc=0;
			scanf("%d",&n);
			for(int i=0;i<n;++i) scanf("%d",&ins[i]);
			for(int i=1;i<n;++i)
				if(ins[i]<ins[i-1]){
					int c = ins[i-1]-ins[i];
					a+=ins[i-1]-ins[i];
					if(c>cc) cc = c;
				}
			for(int i=0;i<n-1;++i){
				if(ins[i]<cc) b+=ins[i];
				else b+=cc;
			}
			printf("Case #%d: %d %d\n",_t,a,b);
		}
		return 0;
	}