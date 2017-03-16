#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <float.h>
#include <climits>

using namespace std;

void printFalse(){
    cout << "Fegla Won";
}

int bestOper(const vector<int> & vec){
    int res = INT_MAX;
    int last_res = INT_MAX;
    int k=1;
    while(res <= last_res){
        int sum = 0;
        for(int i=0; i<vec.size(); ++i){
            sum += abs(vec[i] - k);
        }
        last_res = res;
        res = sum;
        k++;
    }
    return last_res;
}

void solve(){
    int N;
    cin >> N;
    string baseString;
    vector<string> words;
    vector<vector<int>> nums;
    for(int i=0; i<N; ++i){
        string s;
        cin >> s;
        words.push_back(s);
    }
    bool wasFirst = false;
    for(string s : words){
        if(s.size() == 0) continue;
        vector<int> num;
        string res;
        char last = s[0];
        int count = 1;
        for(unsigned i=1; i<s.size(); ++i){
            if(last == s[i]) count++;
            else{
                num.push_back(count);
                res.push_back(last);
                last = s[i];
                count = 1;
            }
        }
        res.push_back(last);
        num.push_back(count);
        nums.push_back(num);

        if(wasFirst){
            if(baseString != res){
                printFalse();
                return;
            }
        }
        else{
            baseString = res;
            wasFirst = true;
        }
    }
    int res = 0;
    for(int i=0; i<nums[0].size(); ++i){
        vector<int> col;
        for(int j=0; j<nums.size(); ++j){
            col.push_back(nums[j][i]);
        }
        res += bestOper(col);
        //cout << res << '\n';
    }
    cout << res;
    /*
    cout << '\n';
    for(int i=0; i<nums.size(); ++i){
        for(int j=0; j<nums[i].size(); ++j){
            cout << nums[i][j] << ", ";
        }
        cout << '\n';
    }
    cout << '\n';
    */

}

int main(){
    //vector<int> a{1, 4, 1};
    //cout << bestOper(a) << '\n';
    // cout.precision(7);
    // cout << fixed;
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << '\n';
    }
}
