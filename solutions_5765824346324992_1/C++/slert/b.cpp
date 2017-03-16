#include <cstdio>
#include <iostream>

using namespace std;

int a[1010];

int main(){
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		int b,n;
		scanf("%d%d",&b,&n);
		for(int i = 0; i < b; i++){
			scanf("%d", &a[i]);
		}

		long long l=0,r=1e16;
		while(l<=r){
			long long m = (l+r)/2;
			long long s = 0;
			for(int i = 0; i < b; i++){
				s+= m/a[i]+1;
			}
			// cout << m << ' ' << s<< endl;
			if(s>=n)r=m-1;
			else l=m+1;
		}
		// cout << l << ' ' << r << endl;
		if(l==0){
			printf("Case #%d: %d\n", ti, n);
		}
		else{
			long long s = 0;
			for(int i = 0; i < b; i++){
				s+= (l-1)/a[i]+1;
			}
			// cout << n<< ':' <<s << endl;
			for(int i = 0; i < b; i++){
				if(l%a[i]==0){
					s++;
					if(s==n){
						printf("Case #%d: %d\n", ti, i+1);
						break;
					}
				}
			}
		}

		
	}
	return 0;
}