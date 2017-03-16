#include <iostream>
#include <vector>

using namespace std;

bool solvable(vector<int> vec, int p){
    for(int i = 1; i < vec.size(); ++i){
        if(vec[i-1]-vec[i] > p){
            return false;
        }
    }
    return true;
}

int bsearch(vector<int> vec, int minv, int maxv){
    if(maxv - minv <= 1){
        return maxv;
    }
    int mid = (minv + maxv)/2;
    if(solvable(vec, mid)){
        return bsearch(vec, minv, mid);
    } else {
        return bsearch(vec, mid, maxv);
    }
}

int solve2(vector<int> vec){
    int dist = bsearch(vec, -1, 10000);
    int ans = 0;
    for(int i = 0; i < vec.size()-1; ++i){
        ans += min(vec[i], dist);
    }
    return ans;
}

int solve1(vector<int> vec){
    int ans = 0;
    for(int i = 1; i < vec.size(); ++i){
        ans += max(0, vec[i-1] - vec[i]);
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; ++i){
        cin >> n;
        auto vec = vector<int>();
        int x;
        for(int j = 0; j < n; ++j){
            cin >> x;
            vec.push_back(x);
        }
        int y = solve1(vec);
        int z = solve2(vec);
        cout << "Case #" << (i+1) << ": " << y << " " << z << endl;
    }
}
