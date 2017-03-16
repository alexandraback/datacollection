#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[110][110];
char zm[110][110];
int num[110][110];
int tt[110];
int bb[110];
int main(){
	int T,n;
	int cnt = 0;
	cin>>T;
	while(T--){
		cnt++;
		cin>>n;
		for(int i=1; i<=n; i++){
			scanf("%s",str[i]);
		}
		memset(num,0,sizeof(num));
		memset(tt,0,sizeof(tt));
		for(int i=1; i<=n; i++){
			int len = strlen(str[i]);
			if(len>0){
				zm[i][++tt[i]] = str[i][0];
				num[i][tt[i]] = 1;
			}else{
				continue;
			}
			for(int j=1; j<len; j++){
				if(str[i][j]==str[i][j-1]){
					num[i][tt[i]]++;
				}else{
					zm[i][++tt[i]] = str[i][j];
					num[i][tt[i]] = 1;
				}
			}
		}
		int ans = 0;
		bool flag = true;
		for(int i=1;i<n;i++){
			if(tt[i]!=tt[i+1]){
				flag = false;
				break;
			}
		}
		printf("Case #%d: ",cnt);
		if(!flag){
			cout<<"Fegla Won"<<endl;
			continue;
		}
		for(int j=1;j<=tt[1];j++){
			int sum = 0;
			for(int i=1;i<n;i++){
				if(zm[i][j]!=zm[i+1][j]){
					flag=false;
					break;
				}
			}

//			ans += abs(num[1][j]-num[2][j]);
			if(!flag) break;
		}
		if(!flag){
			cout<<"Fegla Won"<<endl;
			continue;
		}
		for(int j=1;j<=tt[1];j++){
			memset(bb,0,sizeof(bb));
			for(int i=1;i<=n;i++){
				bb[i-1] = num[i][j];
			}
			sort(bb,bb+n);
			for(int i=0;i<n;i++){
				ans += abs(bb[n/2] - bb[i]);
			}
		}
		cout<<ans<<endl;
		//for(int i = 1; i <= n; i++){
		//	cout<<str[i];
		//}
	}
	return 0;
}
