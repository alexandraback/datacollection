#include <iostream>

using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int n;
		scanf("%d",&n);
		int m[n];
		for(int j=0; j<n; j++){
			scanf("%d",m+j);
		}
		int ans1 = 0, max = 0, ans2 = 0;
        for(int j=0; j<n-1; j++){
            if(m[j] > m[j+1])
                ans1 += m[j]-m[j+1];
            if(m[j]-m[j+1] > max)
                max = m[j]-m[j+1];
        }
        for(int j=0; j<n-1; j++){
            if(m[j] > max)
                ans2 += max;
            else
                ans2 += m[j];
        }
		printf("Case #%d: %d %d\n",i+1,ans1,ans2);
	}
	return 0;
}
