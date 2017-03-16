#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n,a[30],sum;

void find_max(int &t1,int &t2){
	t1=t2=0;
	for (int i=1;i<=n;i++){
		if (a[i]>=a[t1]){
			t2=t1; t1=i;
		}
		else if (a[i]>a[t2]){
			t2=i;
		}
	}
}

bool check(){
	for (int i=1;i<=n;i++){
		if (a[i]>sum/2) return 0;
	}
	return 1;
}

int main(){

	int tt;
	char s[2005];
	cin>>tt;
	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d:",cs);
		scanf("%d",&n);
		sum=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		a[0]=-1;
		
		int t1,t2;
		while (sum>0){
			find_max(t1,t2);
			/*
			if (a[t1]>=2){
				a[t1]-=2;
				if (check()){
					continue;
				}
				a[t1]+=2;
			}
			*/
			if (a[t1]>=1){
				a[t1]--;
				sum--;
				if (check()){
					printf(" %c",t1+'A'-1);
					continue;
				}
				sum++;
				a[t1]++;
			}
			if (a[t1]>=1 && a[t2]>=1){
				a[t1]--;
				a[t2]--;
				sum-=2;
				if (check()){
					printf(" %c%c",t1+'A'-1,t2+'A'-1);
					continue;
				}
				a[t1]++;
				a[t2]++;
				sum+=2;				
			}
		}
		printf("\n");
		
	}

	return 0;
}