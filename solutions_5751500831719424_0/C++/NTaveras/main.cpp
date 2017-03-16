#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long llong;

int fa[55];
int fb[55];
string func(string A, int idx){
    string res;
    for(int i = idx; i < A.size(); ++i)
        res += A[i];
    return res;
}

int main(int argc, char* argv[]) {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int tc;
    cin >> tc;
    string A, B;
    for(int i = 0; i < tc; ++i){
        memset(fa, 0, sizeof(fa));
        memset(fb, 0, sizeof(fb));
        int n;
        cin >> n;
        cin >> A >> B;
        int idxa = 0;
        int idxb = 0;

        for(int j = 0; j < A.size(); ++j) fa[A[j] - 'a']++;
        for(int j = 0; j < B.size(); ++j) fb[B[j] - 'a']++;
        int f = 0;
        for(int j = 0; j <= 30; ++j) {
            if( (fa[j] == 0 && fb[j] > 0) || (fb[j] == 0 && fa[j] > 0) )
                f = 1;
        }
        int ans = 0;
        while(A.size() > 0 || B.size() > 0){
            int cnta = 0, cntb = 0;
            int cur = 0;
            if(A[0] != B[0]){
                f++;
                break;
            }
            while( cur < A.size() && A[cur] == A[0] )
                cur++, cnta++;
            A = func(A, cur);
            cur = 0;
            while( cur < B.size() && B[cur] == B[0] )
                cur++, cntb++;
            B = func(B, cur);
            if(cnta == cntb) continue;
            ans += abs(cnta - cntb);
        }
        if(f > 0){
            cout << "Case #" << i + 1 << ": Fegla Won" << endl;
        }else{
            cout << "Case #" << i + 1 << ": " << ans << endl;
        }
    }
    return 0;
}
