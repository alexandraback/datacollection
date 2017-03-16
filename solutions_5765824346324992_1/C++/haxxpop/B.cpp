#include<stdio.h>
typedef long long ll;
ll time[100000];
ll n;
ll m;
ll gettime(){
	ll left = 0,right = m*time[0]*100;
	for(;left<right;){
		ll mid = (left+right)/2;
		ll sum = 0;
		for(ll i = 0 ; i < n ; i++ ){
			sum += mid/time[i]+1;
		}

		if( sum < m ){
			left = mid+1;
		}else{
			right=mid;
		}
		//if( left == right ) printf("res %lld\n",sum);
	}
	return left;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ;e++ ){
		scanf("%lld %lld",&n,&m);
		for(ll i = 0 ; i < n ; i++ ){
			scanf("%lld",&time[i]);
		}
		ll fin = gettime();
		ll sum = 0;
		for(ll i = 0 ; i < n ; i++ ){
			sum += fin/time[i];
			if( fin%time[i] != 0 ) sum++;
		}
		//printf("a %lld %lld\n",fin,sum);
		for(ll i = 0 ; i < n ; i++ ){
			if( fin%time[i] == 0 ) sum++;
			if( sum == m ){
				printf("Case #%d: %lld\n",e+1,i+1);
				break;
			}
		}
		//printf("c %d, %lld %lld\n",e+1,sum,m);
	}
}

