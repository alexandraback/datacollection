#include<iostream>
#include<map>
#include<cstring>
using namespace std;


class State {
public:
    int remain, row, mask;
    
    State(){}
    State(int remain, int row, int mask):
        remain(remain), row(row), mask(mask){}
    
    bool operator< (const State &opp) const {
        if (remain != opp.remain) return remain < opp.remain;
        if (row != opp.row) return row < opp.row;
        return mask < opp.mask;
    }
};


int R, C, N;

void read() {
    cin >> R >> C >> N;
}


int rec(int remain, int row, int mask, map<State, int> &dp) {
    if (row == R)
        return remain == 0 ? 0 : 1 << 20;
    
    if (dp.count(State(remain, row, mask)))
        return dp[State(remain, row, mask)];
    
    int ret = 1 << 20;
    for (int nexMask = 0; nexMask < (1 << C); ++nexMask) {
        int nPut = __builtin_popcount(nexMask);
        if (nPut > remain)
            continue;
        
        int cost = 0;
        for (int i = 0; i < C; ++i) {
            if ((mask & (1 << i)) && (nexMask & (1 << i))) {
                ++cost;
            }
            if (i + 1 < C && (nexMask & (1 << i)) && (nexMask & (1 << (i + 1)))) {
                ++cost;
            }
        }
        
        ret = min(ret, rec(remain - nPut, row + 1, nexMask, dp) + cost);
    }

    return dp[State(remain, row, mask)] = ret;
}


void work(int cases) {
    map<State, int> dp;
    
    cout << "Case #" << cases << ": " << rec(N, 0, 0, dp) << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
