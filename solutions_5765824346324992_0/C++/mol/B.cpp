#include <stdio.h>

int gcm(int a, int b){
    while(a != b){
        if(a < b)
            b = b%a;
        if(a > b)
            a = a%b;
        if(a == 0)
            return b;
        if(b == 0)
            return a;
    }
}

int lcm(int a, int b){
    return a*b/gcm(a,b);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int b, n;
		scanf("%d%d",&b,&n);
		int m[b], max = 0;
		for(int j=0; j<b; j++){
			scanf("%d",m+j);
            if(m[j] > max)
                max = m[j];
		}
        int t[b];
		for(int j=0; j<b; j++){
            t[j] = 0;
		}
        int cnt = 0;
        while(true){
            int flg = 1;
            for(int j=0; j<b; j++){
                t[j] += max;
                t[j] = t[j]%m[j];
                if(t[j] > 0)
                    flg = 0;
            }
            cnt++;
            if(flg == 1)
                break;
        }
        int a[b], sum = 0;
		for(int j=0; j<b; j++){
            a[j] = max*cnt/m[j];
            sum += a[j];
		}
        n = (n-1)%sum+1;
        int ans = -1, k = 0, tt = 0;
        while(k < n){
            for(int j=0; j<b; j++)
                if(tt%m[j] == 0){
                    k++;
                    if(k == n){
                        ans = j;
                        break;
                    }
                }
            if(ans >= 0)
                break;
            tt++;
        }
		printf("Case #%d: %d\n",i+1,ans+1);
	}
	return 0;
}
