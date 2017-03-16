#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y){
    return x == 0 ? y : gcd(y%x, x);
}

int lcm(int x, int y){
    return x*y/gcd(x,y);
}

int lcm(vector<int> vec){
    int ret = 1;
    for(int i = 0; i < vec.size(); ++i){
        ret = lcm(vec[i], ret);
    }
    return ret;
}

int loopn(vector<int> vec, int l){
    int ret = 0;
    for(auto it = vec.begin(); it != vec.end(); ++it){
        ret += l/(*it);
    }
    return ret;
}

int solve(vector<int> vec, int n){
    int circ = loopn(vec, lcm(vec));
    int loop = (n + circ- 1)%circ;
    //cout << "lcm = " << lcm(vec) << endl;
    //cout << "loop = " << loop << endl;
    auto bs = vector<int>(vec.size(), 0);
    for(int i = 0; i < loop; ++i){
        bool flag = false;
        int next = 0;
        for(int j = 0; j < bs.size(); ++j){
            if(bs[j] == 0){
                bs[j] = vec[j];
                flag = true;
                break;
            }
            if(bs[next] > bs[j]){
                next = j;
            }
        }
        if(!flag){
            int v = bs[next];
            for(int j = 0; j < bs.size(); ++j){
                bs[j] -= v;
            }
            bs[next] = vec[next];
        }
    }
    int mini = 0;
    for(int i = 0; i < bs.size(); ++i){
        if(bs[mini] > bs[i]){
            mini = i;
        }
    }
    return mini+1;
}

int main(){
    int t;
    cin >> t;
    int n, m;
    for(int i = 0; i < t; ++i){
        cin >> m >> n;
        auto vec = vector<int>();
        int x;
        for(int j = 0; j < m; ++j){
            cin >> x;
            vec.push_back(x);
        }
        cout << "Case #" << (i+1) << ": " << solve(vec, n) << endl;
    }
}
