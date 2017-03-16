#include <iostream>

using namespace std;

int T;

int r,c;
int n;

int dp[17][16][17];

int bits(int a, int b) {
    int ret = 0;
    while(a && b) {
        if((a%2) && (b%2)) ret++;
        a>>=1;
        b>>=1;
    }
    return ret;
}

int bitc(int a) {
    int ret = 0;
    while(a) {
        if(a%2) ret++;
        a>>=1;
    }
    return ret;
}

int main()
{
    for(int i=0; i<16; i++) {
        for(int j=0; j<=16; j++) {
            dp[0][i][j] = 1<<30;
        }
    }
    dp[0][0][0] = 0;

    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> r >> c >> n;

        if(c < r) { swap(r,c); }

        for(int i=1; i<=c; i++) {
            for(int l=0; l<=n; l++) {
                for(int j=0; j<1<<r; j++) {
                    int bbit = bitc(j);
                    dp[i][j][l] = 1<<30;
                    if(l < bbit) continue;
                    int np = 0;
                    for(int k=0; k<r-1; k++) {
                        if(((1<<k) & j) && ((1<<(k+1)) & j)) np++;
                    }
                    for(int k=0; k<1<<r; k++) {
                        dp[i][j][l] = min(dp[i][j][l], np+dp[i-1][k][l-bbit]+bits(j,k));
                    }

                    //cerr << dp[i][j][l] << " ";
                }
                //cerr << endl;
            }
            //cerr << endl;
        }

        int sol = 1<<30;
        for(int i=0; i<1<<r; i++) {
            sol = min(sol,dp[c][i][n]);
        }
        //cerr << endl;

        cout << "Case #" << t << ": " << sol << endl;
    }

    return 0;
}
