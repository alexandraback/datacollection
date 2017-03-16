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
int vis[10005];
int c[10005];
int d[10005];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool used(int x,int y){
    if(x<0||x>=n||y<0||y>=m) return false;
    int p=x*m+y;
    if(c[p]) return true;
    return false;
}

void rs(int s){
    int i,j;
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    //for(i=s;i<n*m;i+=2){
    //    c[i]=1;
    //    d[i]=1;
    //}
    for(i=0;i<n;i++){
        int t;
        if(i&1){
            t=s;
        }
        else{
            t=1-s;
        }
        for(j=t;j<m;j+=2){
            c[i*m+j]=1;
            d[i*m+j]=1;
        }
    }
    for(i=0;i<n*m;i++){
        if(!c[i]){
            int cnt=0;
            int x=i/m,y=i%m;;
            for(j=0;j<4;j++){
                int tx=x+dx[j],ty=y+dy[j];
                if(used(tx,ty)){
                    cnt++;
                }
            }
            c[i]=1;
            d[i]=cnt;
        }
    }
}

int calc(){
    int i,j;
    int cnt=0;
    /*for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int p=i*m+j;
            printf("%d ",vis[p]);
        }
        printf("\n");
    }*/
    for(i=0;i<n-1;i++){
        for(j=0;j<m;j++){
            int p1=i*m+j;
            int p2=(i+1)*m+j;
            int p3=i*m+j+1;
            int t=0;
            if(vis[p1]&&vis[p2]){
                cnt++;
                t++;
            }
            if(j<m-1&&vis[p1]&&vis[p3]){
                cnt++;
                t++;
            }
            //printf("%d ",t);
        }
        //cout<<endl;
    }
    for(i=0;i<m-1;i++){
        int p1=(n-1)*m+i;
        int p2=(n-1)*m+i+1;
        if(vis[p1]&&vis[p2]) cnt++;
    }
    return cnt;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

    int T,ca=0;
    int i,j;
    scanf("%d",&T);
    while(T--){
        ca++;
        scanf("%d%d%d",&n,&m,&l);
        int tl=l;
        int ans=0;
        rs(0);
        /*for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                int p=i*m+j;
                printf("%d ",d[p]);
            }
            printf("\n");
        }
        cout<<endl;*/
        memset(vis,0,sizeof(vis));
        for(i=1;i<=4;i++){
            if(!l) break;
            for(j=0;j<n*m;j++){
                if(!l) break;
                if(d[j]==i){
                    l--;
                    vis[j]=1;
                }
            }
        }
        ans=calc();
        rs(1);
        /*for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                int p=i*m+j;
                printf("%d ",d[p]);
            }
            printf("\n");
        }
        cout<<endl;*/
        memset(vis,0,sizeof(vis));
        l=tl;
        for(i=1;i<=4;i++){
            if(!l) break;
            for(j=0;j<n*m;j++){
                if(!l) break;
                if(d[j]==i){
                    l--;
                    vis[j]=1;
                }
            }
        }
        ans=min(ans,calc());
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
