#include <bits/stdc++.h>      
using namespace std;  

int m[10010];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	int x=0;
	while(t--){
		x++;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&m[i]);
		}
		int y=0;
		int MAX_speed=0;
		for(int i=2;i<=n;i++){
			if(m[i]<m[i-1]){
				y+=m[i-1]-m[i];
				if(m[i-1]-m[i]>MAX_speed){
					MAX_speed=m[i-1]-m[i];
				}
			}
		}
		int z=0;
		
		for(int i=1;i<n;i++){
			if(m[i]<MAX_speed){
				z+=m[i];
			}else{
				z+=MAX_speed;
			}
		}
		printf("Case #%d: %d %d\n",x,y,z);
	}
	return 0;
}
