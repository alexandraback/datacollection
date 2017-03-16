#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define _D(p) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p)<<std::endl;
#define _D2(p,q) std::cout<<"L"<<__LINE__<<" : " #p " = "<<(p) << ", " #q " = "<<(q)<<std::endl;
#define _DN(v) std::cout<<"L"<<__LINE__<<" : " #v " = ["; rep(i,(v).size()) {std::cout<<v[i]<<(i==v.size()-1?"":", ");}std::cout<<"]"<<std::endl;
#define _DNN(v) std::cout<<"L"<<__LINE__<<" : " #v " = [" << std::endl; rep(i,(v).size()) {std::cout<<"    [";rep(j,(v)[0].size()){std::cout<<v[i][j]<<(j==v[0].size()-1?"":", ");}std::cout<<"],"<<std::endl;}std::cout<<"]"<<std::endl;
 
using namespace std;
 
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
 
const int INF=1<<29;
const double EPS=1e-9;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        vector<int> P;

        int x = 0;
        for (int i = 0; i < N; ++i) {
            int p;
            cin >> p;
            x += p;
            P.push_back(p);
        }
        vector<string> ans;
        if (x % 2 == 1) {
            int ma = -1;
            int mai;
            for (int i = 0; i < N; ++i) {
                if (ma < P[i]) {
                    ma = P[i];
                    mai = i;
                }
            }
            stringstream ss;
            char n = 'A' + mai;
            ss << n;
            ans.push_back(ss.str());
            P[mai]--;
            x--;
        }

        
        int count = 0;
        while(x != 0) {
            int ma = -1;
            int mai;
            for (int i = 0; i < N; ++i) {
                if (ma < P[i]) {
                    ma = P[i];
                    mai = i;
                }
            }
            P[mai]--;

            stringstream ss;
            char n = 'A' + mai;
            ss << n;

            
            x--;
            if (x == 0) {
                ans.push_back(ss.str());
                break;
            }

            ma = -1;
            for (int i = 0; i < N; ++i) {
                if (ma < P[i]) {
                    ma = P[i];
                    mai = i;
                }
            }
            P[mai]--;
            ss << (char)('A' + mai);
            x--;
            ans.push_back(ss.str());

            for (int i = 0; i < N; ++i) {
                if (P[i] * 2 > x) {
                    //cout << "dame: " << count << "," << i << endl;
                }
            }
            count++;
        }
        cout << "Case #" << test << ": ";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;


    }

    return 0;
}