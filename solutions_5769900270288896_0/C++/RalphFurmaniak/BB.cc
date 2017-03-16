#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

int comp(const vector<vector<int> >& board, int r, int c) {
    return board[r-1][c]+board[r+1][c] + board[r][c+1]+board[r][c-1];
}

int solve(int R, int C, int N) {
        if(N<=(R*C+1)/2) return 0;
        int n = R*C-N;
        int T = (R-1)*C + (C-1)*R;

        vector<vector<int> > board(R+2, vector<int>(C+2));
        fu(r,1,R+1) fu(c,1,C+1) board[r][c]=1;

        int best=10000000;
        fu(msk,0,(1<<(R*C))) {
            int msk2=msk;
            int cnt=0;
            fu(r,1,R+1) fu(c,1,C+1) {
                if(msk2&1) { board[r][c]=1; cnt++; }
                else board[r][c]=0;
                msk2>>=1;
            }
            if(cnt!=N) continue;
            int cur=0;
            fu(r,1,R+1) fu(c,1,C+1) cur += (board[r][c]&&board[r+1][c]);
            fu(r,1,R+1) fu(c,1,C+1) cur += (board[r][c]&&board[r][c+1]);
            best = min(best, cur);
        }

        return best;

}

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        int R,C,N;
        cin >> R >> C >> N;
        cout << solve(R,C,N) << endl;
	}
}
