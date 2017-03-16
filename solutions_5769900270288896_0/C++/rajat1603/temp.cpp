#include <bits/stdc++.h>
using namespace std;

#define N 17
#define POWN (1 << 17)

int dp[POWN], r, c, k;


int main(){

	int t, ans, temp, tot;
	cin>>t;
	for(int big = 1; big <= t; big++){
		ans = INT_MAX;
		temp = 0;
		memset(dp, -1, sizeof(dp));
		cin>>r>>c>>k;
		tot = r*c;
		for(int i = 0; i < (1 << tot); i++){
			temp = 0;
			int count = 0;
			for(int j = 0; j < tot; j++){
				if(i&(1 << j))	count++;
			}

			if(count == k){
				for(int j = 0; j < tot; j++){
					if(i&(1 << j)){
						if((j%c) != 0 && j - 1 >= 0){
							if(i&(1 << (j - 1)))	temp++;	
						}
						if(j - c >= 0){
							if(i&(1 << (j - c)))	temp++;
						}
					}
				}
				ans = min(ans, temp);
			}
		}
		cout<<"Case #"<<big<<": "<<ans<<endl;
	}

	//system("pause");
	
	return 0;
}