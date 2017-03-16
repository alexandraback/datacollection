//
//  A.cpp
//  CODE
//
//  Created by Vikas Yadav on 29/10/14.
//  Copyright (c) 2014 Vikas Yadav. All rights reserved.
//

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <memory.h>
#include <cassert>

using namespace std;

#define pll pair < long long,long long >
#define pb push_back
#define mp make_pair
#define gc getchar_unlocked
#define F first
#define S second

#define MOD 1000000007
#define INF 999999
#define N 1123456
#define NN 212
#define VAL 20000
#define LN 18

long long r,c,n;
int dp[N];

int findScore(int no){
	int temp,answer = 0;
	while(no>0){
		temp = no;
		no = no>>c;
		for(int a=0;a<c-1;a++){
			if((((temp>>a)^(temp>>(a+1)))&1)==0 && ((temp>>a)&1))			answer++;
		}
		for(int a=0;a<c;a++){
			if((((temp>>a)^(no>>a))&1)==0 && ((temp>>a)&1))			answer++;
		}
	}
	return answer;
}

int noofbits(int no){
	int ans = 0;
	while(no>0){
		ans += no%2;
		no /= 2;
	}
	return ans;
}

void build(){
	dp[0] = 0;
	for(int a=1;a<(1<<(r*c));a++){
		dp[a] = findScore(a);
	}
}

int findAns(){
	int ans = 99999999;
	for(int a=0;a<(1<<(r*c));a++){
		if(noofbits(a)==n)		ans = min(ans,dp[a]);
	}
	return ans;
}

int main(){
	freopen("B-small.in", "r", stdin);
	freopen("B-out.out", "w", stdout);
	int t,ttt = 0;
	cin>>t;
	while(t--){
		long long temp,temp2,answer = 0;
		cin>>r>>c>>n;
		temp = min(r,c);
		c = max(r,c);
		r = temp;
		build();
		cout<<"Case #"<<++ttt<<": "<<findAns()<<endl;
	}
	return 0;
}