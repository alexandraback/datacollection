#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 30;
//#define LOACL
int n,m,s;
int a[N];
typedef pair<int,int> pi;

int check(){
	for(int i=0;i<=n;i++){
		if (a[i]*2>s) return 0;
	}
	return 1;
}

int find_one(){
	int tt=m+1;
	s--;
	for(int i=0;i<n;i++)
		if (a[i]>0) {
			a[i]--;
			if (check())
				return i;
			a[i]++;
		}
	s++;
	return -1;
}

 pi find_two(){
 	s-=2;
 	for(int i=0;i<26;i++)
 	if (a[i]>0)	for(int j=0;j<26;j++)
 		if ((i!=j && a[j]>0) || (i==j && a[j]>1)){
 			a[i]--; a[j]--;
 			if (check()) return make_pair(i,j);
 			a[i]++; a[j]++;
 		}
 	s+=2;
 	return make_pair(-1,-1);
}

int main(){
	#ifdef LOACL
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	s = 0;
	for(int times=1;times<=T;times++){
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%d",a+i);
			s += a[i]; 
		}
		m = 0;
		printf("Case #%d:",times);
		while(s){
			if (s>1 && s!=3) {
				pi pp = find_two();
				if (pp.first != -1){
					printf(" %c%c",pp.first + 'A', pp.second + 'A');
					continue;
				} 
			}
				
			int k = find_one();
			printf(" %c",k+'A');
			
			
		}
		puts("");
	}
	return 0;
}
