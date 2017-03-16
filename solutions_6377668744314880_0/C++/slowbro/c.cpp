#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

typedef long long LL;
vector<pair<LL, LL>> trees;
vector<pair<LL, LL>> shift_trees;

#define MAX_TREES 3001

LL calc_dp(const pair<LL, LL>& a, const pair<LL, LL>& b){
    return a.first*b.first + a.second*b.second;
}

int solve_j(int treej, int parent){
    if(shift_trees[parent].first != 0 || shift_trees[parent].second != 0)
        throw;
    pair<LL, LL> perp = make_pair(shift_trees[treej].second, -shift_trees[treej].first);
    
    int num_zero = 1;
    int num_pos = 0;
    int num_neg = 0;
    
    int dp;
    for(int ii=0; ii < shift_trees.size(); ++ii){
        if(ii == treej || ii == parent){
            continue;
        }
        dp = calc_dp(perp, shift_trees[ii]);
        if(dp < -0.000000001){
            num_neg++;
        }
        else if(dp > 0.000000001){
            num_pos++;
        }
        else{
            num_zero++;
        }
    }
    return min(num_neg, num_pos);
}


int solve_i(int treei){
    shift_trees = trees;
    for(auto& t: shift_trees){
        t.first -= trees[treei].first;
        t.second -= trees[treei].second;
    }

    int min_cut = MAX_TREES;
    int cur_cut;
    for(int ii=0; ii< shift_trees.size(); ++ii){
        if(ii != treei){
            cur_cut = solve_j(ii, treei);
            if(cur_cut < min_cut)
                min_cut = cur_cut;
        }
    }
    return min_cut;
}

void solve(int case_num){
    printf("Case #%d: \n", case_num);
    int N;
    trees.clear();
    shift_trees.clear();
    cin >> N;
    LL x,y;
    for(int ii = 0; ii< N; ++ii){
       cin >> x >> y;
       trees.push_back(make_pair(x, y));
    }
    
    int ret;
    for(int ii=0; ii< N; ++ii){
        if(N <= 3){
            ret = 0;
        }
        else
            ret = solve_i(ii); 
        cout << ret << endl;
    }
}

int main(){
    int num_cases;
    cin >> num_cases;
    for(int ii=1; ii <= num_cases; ++ii)
        solve(ii);
    return 0;
}
