#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve(int case_num){
    printf("Case #%d: ", case_num);
    int N;
    vector<int> mushrooms;
    cin >> N;
    int input;
    for(int ii=0; ii<N; ++ii){
        cin >> input;
        mushrooms.push_back(input);
    }

    //method 1
    int prev = 0;
    int diff;
    int ret1 = 0;
    int max_diff = 0;
    for(auto mi: mushrooms){
        diff = mi - prev; 
        if(diff < 0){
            ret1 -= diff;  
        }
        if(diff < -max_diff){
            max_diff = -diff;
        }
        prev = mi;
    }

    //method 2
    int mush_left = 0;
    int ret2 = 0;
    int eaten;
    for(int ii = 0; ii < N-1; ++ii){
        eaten = min(mushrooms[ii], max_diff);
        ret2 += eaten;
    }

    cout << ret1 << " " << ret2 << endl;
}

int main(){
    int num_cases;
    cin >> num_cases;
    for(int ii=1; ii <= num_cases; ++ii)
        solve(ii);
    return 0;
}
