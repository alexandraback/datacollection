#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int a[30];
int n;

int finished(){
	for (int i=0;i<n;++i)
		if (a[i]>0) return 0;
	return 1;
}

int main(){
	int T=0;
	scanf("%d", &T);
	for (int t=1; t<=T; ++t){
		printf("Case #%d:", t);
		scanf("%d", &n);
		int s=0;
		for (int i=0; i<n; ++i)
			scanf("%d", a+i);
		while (! finished()){
			int m=0;
			for (int i=0; i<n; ++i) if (a[i]>0) ++m;
			if (m==2){
				int t1=-1,t2=-1;
				for (int i=0; i<n; ++i)
					if (a[i]>0){
						if (t1==-1) t1=i; else t2=i; m=a[i];	
					}
				for (int i=0;i<m;++i)
					printf(" %c%c", 'A'+t1,'A'+t2);
				break;
			} else {
				m=0;
				for (int i=0; i<n; ++i) if (a[i]>a[m]) m=i;
				--a[m];
				printf(" %c", 'A'+m);
			}
		}
		cout<<endl;
	}
}
