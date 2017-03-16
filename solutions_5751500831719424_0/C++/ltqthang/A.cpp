//-----------------------------------------
// Le Truong Quoc Thang
// ltqthang@gmail.com
// Problem:
// ----------------------------------------

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define write(a) printf("%d", a)
#define writes(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define read(a) scanf("%d", &a)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define mii map <int, int>
#define INF 2000000000
#define maxN 105

int TC, n;
string s[maxN], convert[maxN];
int cnt[maxN][maxN];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d ", &TC);
    fr(caseNo, 1, TC){
        scanf("%d ", &n);
        rep(i, maxN) rep(j, maxN) cnt[i][j] = 1;
        rep(i, n){
            getline(cin, s[i]);
            convert[i] = " ";
            rep(k, s[i].size()){
                if (s[i][k] != convert[i][convert[i].size() - 1])
                    convert[i] += s[i][k];
                else{

                }
            }
            int pos = 0;
            rep(k, convert[i].size()){
                while (pos < s[i].size() && s[i][pos++] == convert[i][k]){
                    cnt[i][k]++;
                }
            }
            //cout << convert[i] << endl;
            //rep(k, convert[i].size()) cout << cnt[i][k]; cout << endl;
        }

        bool flag = false;
        rep(i, n) rep(j, n) if (convert[i] != convert[j]) flag = true;
        printf("Case #%d: ", caseNo);
        if (flag){
            puts("Fegla Won");
            continue;
        }
        ll res = 0;
        fr(j, 1, convert[0].size()){
            ll minChange = INF;
            fr(k, 0, 100){
                ll cur = 0;
                rep(i, n){
                    cur += (int) abs(cnt[i][j] - k);
                }
                minChange = min(minChange, cur);
            }
            res += minChange;
        }
        cout << res << endl;

    }

    return 0;
}
