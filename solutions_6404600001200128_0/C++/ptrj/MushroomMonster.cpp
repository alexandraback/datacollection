//==============================================================================
// Round 1A 2015
// Problem A. Mushroom Monster
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

using sol_type = pair<int, int>;

void read_data();
sol_type find_solution();

vector<long long> pancakes;

int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        read_data();
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << solution.first << " " << solution.second << endl;
    }
    return 0;
}

void read_data(){
    int N;
    cin >> N;
    pancakes.resize(N);
    for(int i=0; i<N; ++i)
        cin >> pancakes[i];
}

sol_type find_solution(){
    vector<long long> diff (pancakes.size());
    adjacent_difference(pancakes.begin(), pancakes.end(), diff.begin(),
                        [](long long x, long long y) {return max(y-x,0ll);});
    auto fi = accumulate(diff.begin()+1, diff.end(), 0ll);
    auto mx = *max_element(diff.begin()+1, diff.end());
    auto se = accumulate(pancakes.begin(), pancakes.end()-1, 0ll,
                         [mx](long long x, long long y) {return x + min(mx, y);});
    return make_pair(fi, se);
}
