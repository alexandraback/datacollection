//==============================================================================
// Round 1B 2015
// Problem B small
//
//==============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using sol_type = int;

int R, C, N;
vector<vector<char>> B;
void clearB();
int countB();

void read_data();
sol_type find_solution();


int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        read_data();
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << solution << endl;
    }
    return 0;
}

void read_data(){
    cin >> R >> C >> N;
    B = vector<vector<char>> (R+2, vector<char> (C+2));
}

sol_type find_solution(){
    vector<char> m (R*C);
    auto count = N;
    for(auto it = m.rbegin(); count; --count, ++it)
        *it = 1;
    int best = 1e6;
    do {
        clearB();
        int cnt = 0;
        for(int i=1; i<= R; ++i)
            for(int j=1; j<=C; ++j) {
                B[i][j] = m[cnt++];
            }
        auto res = countB();
        best = min(best, res);
    } while(next_permutation(m.begin(), m.end()));
    return best;
}

void clearB() {
    fill(B.begin()+1, B.end(), B[0]);
}

int countB() {
    int count = 0;
    for(int i=1; i<=R; ++i)
        for(int j=1; j<= C; ++j)
            if(B[i][j] != 0) {
                if(B[i-1][j] != 0)
                    ++count;
                if(B[i][j-1] != 0)
                    ++count;
            }
    return count;
}
