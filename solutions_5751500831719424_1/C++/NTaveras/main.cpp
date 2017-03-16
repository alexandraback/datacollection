#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long llong;

int cnt[150];
int curid[150];
int freq[150][55];
string arr[150];
string func(string A, int idx){
    string res;
    for(int i = idx; i < A.size(); ++i)
        res += A[i];
    return res;
}

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; ++t){

        memset(cnt, 0, sizeof(cnt));
        memset(curid, 0, sizeof(curid));
        memset(freq, 0, sizeof(freq));
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < arr[i].size(); ++j)
                freq[i][arr[i][j] - 'a']++;
        }
        int f = 0;
        for(int i = 0; i < n; ++i){
            int got = 0;
            int dont = 0;
            for(int j = 0; j <= 30; ++j){
                if(freq[i][j] == 0)
                    dont++;
                else
                    got++;
            }
            if( (got > 0 && dont == 0) || (dont > 0 && got == 0)  ) f = 1;
        }

        int ans = 0;
        while(!f){

            memset(cnt, 0, sizeof(cnt));

            int saw = 0;
            set<char> s;
            for(int i = 0; i < n; ++i){
                if(curid[i] < arr[i].size()){
                    saw++;
                    s.insert(arr[i][curid[i]]);
                }
            }
            if(saw == 0) break;
            if(saw < n){
                f = 1;
                break;
            }
            if(s.size() > 1){
                f = 1;
                break;
            }

            for(int i = 0; i < n; ++i){
                if(curid[i] < arr[i].size()){
                    int cur = curid[i];
                    char first = arr[i][curid[i]];
                     while( cur < arr[i].size() && arr[i][cur] == first )
                        cur++, cnt[i]++;
                    curid[i] = cur;
                }
            }

            int ma = 0;
            int mi = 1000;
            for(int i = 0; i < n; ++i){
                ma = max(ma, cnt[i]);
                mi = min(mi, cnt[i]);
            }
            ans += abs(ma - mi);

        }
        if(f > 0){
            cout << "Case #" << t + 1 << ": Fegla Won" << endl;
        }else{
            cout << "Case #" << t + 1 << ": " << ans << endl;
        }
    }
    return 0;
}
