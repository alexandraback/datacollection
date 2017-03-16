#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;

#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double


inline int getCnt(int r, int c, int n){
    int y = INF, x, i, j, k, m, cnt, b[16][16], i2, j2;
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    for(m = (1<<(r * c)) - 1; m >= 0; m--){
        cnt = 0;
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                b[i][j] = (m & (1<<(i * c + j)));
                if(b[i][j] > 0){
                    b[i][j] = 1;
                }
                cnt += b[i][j];
            }
        }
        //cout<<m<<" "<<cnt<<endl;
        if(cnt == n){
            x = 0;
            for(i = 0; i < r; i++){
                for(j = 0; j < c; j++){
                    //cout<<b[i][j]<<" ";
                    for(k = 0; k < 4; k++){
                        i2 = i + di[k];
                        j2 = j + dj[k];
                        if(i2 >= 0 && i2 < r && j2 >= 0 && j2 < c){
                            if(b[i][j] && b[i2][j2]){
                                x++;
                            }
                        }
                    }
                }
                //cout<<endl;
            }
           // cout<<endl;
            x /= 2;
            y = min(x, y);
        }
    }
    return y;
}

int main(){
    freopen("in.in", "r", stdin);
    freopen("op.txt", "w", stdout);
	int t, cs = 1;
	sd(t);
	while(t--){
        int r, c, n;
        sd(r); sd(c); sd(n);
        printf("Case #%d: %d\n", cs, getCnt(r, c, n));
        cs++;
	}
	return 0;
}
