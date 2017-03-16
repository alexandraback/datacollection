#include<bits/stdc++.h>
#define LL long long 
#define PI acos(-1)
#define x first
#define y second
#define PII pair<int,int>
#define F(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define pb push_back
#define mp make_pair
using namespace std;

int T,n,r,c,ans;
int w[20][20];

int bits(int x){
    int cnt = 0;
    while(x) {cnt += x&1; x>>=1;}
    return cnt;
}

void fill(int x){
    for(int i=0; x ; i++, x>>=1){
	if(x & 1){
	    w[i/c][i%c] = 1;
	}
    }
}

int check(){
    int ret = 0;
    for(int i=0; i<r;i++){
	for(int j=0; j<c;j++){
	    if(w[i][j] && w[i+1][j]) ret++;
	    if(w[i][j] && w[i][j+1]) ret++;
	}
    }
    return ret;
}

int main(){
    scanf("%d", &T);
    for(int qwe=1; qwe<=T;qwe++){
	scanf("%d%d%d", &r,&c,&n);	
	int S = r*c;
	ans = 1<<28;
	for(int i=0; i< (1<<S); i++){
	    if(bits(i) == n){
		memset(w,0,sizeof(w));
		fill(i);
		ans = min(ans, check());
	    }
	}

	printf("Case #%d: %d\n", qwe, ans);
    }
    return 0;
}
