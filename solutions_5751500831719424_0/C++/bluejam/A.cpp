#include <string> 
#include <algorithm> 
#include <cfloat> 
#include <climits> 
#include <cmath> 
#include <complex> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <functional> 
#include <iostream> 
#include <map> 
#include <memory> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <utility> 
#include <vector> 

#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(x) (x).begin(),(x).end() 
using namespace std;
const double eps = 1e-10;

//input data
int N;
string ss[110];

int calc(int b, vector<int> &v){
    int res = 0;
    EACH(i, v){
        res += abs(*i - b);
    }
    return res;
}
void solve(int caseNum){
    //solve problem here
    vector<char> vc;
    vector<int> vcnt[110];
    vc.push_back(ss[0][0]);
    vcnt[0].push_back(0);
    for(int i = 0; i < ss[0].size(); ++i){
        int t = vc.size() - 1;
        if(vc[t] != ss[0][i]){
            vc.push_back(ss[0][i]);
            ++t;
            vcnt[t].push_back(1);
        }
        else{
            vcnt[t][0] += 1;
        }
    }
    for(int i = 1; i < N; ++i){
        int s = 0;
        if(ss[i][0] != vc[0]){
            cout << "Case #" << caseNum << ": Fegla Won" << endl;
            return;
        }
        vcnt[s].push_back(0);
        for(int j = 0; j < ss[i].size(); ++j){
            if(ss[i][j] != vc[s]){
                ++s;
                if(vc[s] != ss[i][j]){
                    cout << "Case #" << caseNum << ": Fegla Won" << endl;
                    return;
                }
                vcnt[s].push_back(1);
            }
            else{
                vcnt[s][i] += 1;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < vc.size(); ++i){
        if(vcnt[i].size() != N){
            cout << "Case #" << caseNum << ": Fegla Won" << endl;
            return;
        }
        sort(ALL(vcnt[i]));
        if(N % 2 == 0){
            res += min(calc(vcnt[i][N / 2], vcnt[i]), calc(vcnt[i][N/2-1], vcnt[i]));
        }
        else{
            res += calc(vcnt[i][N / 2], vcnt[i]);
        }
    }
    cout << "Case #" << caseNum << ": " << res << endl;
}

int main(){
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        cin >> N;
        for(int i = 0; i < N; ++i){
            cin >> ss[i];
        }
        solve(t);
    }
    return 0;
}
