#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*
long long n, x, y, z;
long long a[20], _10[20];
long long ans;
int w;

void init() {
	int tmp = 20;
	a[1] = 1;
	for (int i = 2; i <= 16; i++) {
		a[i] = a[i-1]+tmp-1;
		if (i % 2)
			tmp *= 10;
	}
	_10[0] =1;
	for (int i = 1; i <= 16; i++)
		_10[i] = _10[i-1]*10;
}

long long form(int tn) {
	long long ret;
	ret = (_10[tn/2]-1)*_10[tn-tn/2]+1;
	return ret;
}

int getW(long long n) {
	int ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

long long solve(long long n) {
	long long ret = 0;
	int p[20];
	x = n;
	for (int i = 0; i < w; i++) {
		p[i] = n % 10;
		n /= 10;
	}
	p[0] = 1;
	for (int i = 1; i < w/2; i++) {
		if (p[i])
			p[i] = 0;
	}
	y = 0;
	for (int i = w-1; i >= 0; i--) {
		(y *= 10) += p[i];
	}
	ret += (x - y);
	z = 0;
	for (int i = 0; i < w; i++) {
		(z *= 10) += p[i];
	}
	//cout << x << " " << y << " " << z << endl;
	//cout << "ret = " << ret << endl;
	if (z != y)
		ret++;
	//cout << "ret = " << ret << endl;
	if (w <= 2)
		ret += z;
	else
		ret += ((z-form(w-1))+a[w-1]);
	//cout << "form(w-1) = " << form(w-1) << endl;
	//cout << "a[w-1] = " << a[w-1] << endl;
	//cout << "ret = " << ret << endl;
	return ret;
}

int main(void) {

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int t;
	init();
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%I64d", &n);
		ans = 0;
		if (n % 10 == 0) {
			ans++;
			n--;
		}
		w = getW(n);
		if (w != 0) {
			ans += solve(n);
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}
*/
//============================================================================
// Name        : b.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

int n,m,l;
int vis[20];
int c[20][20];
int ans;

void put(int p){
    int x=p/m,y=p%m;
    c[x][y]=1;
}

void calc(){
    int i,j;
    memset(c,0,sizeof(c));
    for(i=0;i<n*m;i++){
        if(vis[i]){
            put(i);
        }
    }
    int cnt=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<m;j++){
            if(c[i][j]&&c[i][j+1]) cnt++;
            if(c[i][j]&&c[i+1][j]) cnt++;
        }
    }
    for(i=0;i<m;i++){
        if(c[n-1][i]&&c[n-1][i+1]) cnt++;
    }
    ans=min(ans,cnt);
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

    int T,ca=0;
    int i;
    scanf("%d",&T);
    while(T--){
        ca++;
        scanf("%d%d%d",&n,&m,&l);
        memset(vis,0,sizeof(vis));
        ans=n*m*4;
        int w=n*m;
        for(int s=0;s<(1<<w);s++){
            int cnt=0;
            memset(vis,0,sizeof(vis));
            for(i=0;i<w;i++){
                if(s&(1<<i)){
                    cnt++;
                    vis[i]=1;
                }
            }
            if(cnt==l){
                calc();
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
