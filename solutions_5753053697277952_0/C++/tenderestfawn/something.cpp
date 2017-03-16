#include <set>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <utility>
#include <map>
#include <sstream>
#include <queue>

using namespace std;

typedef long long ll;
#define MAXN 30
#define MAXD 50
#define MOD 1000000007

pair<ll, ll> pt[MAXN];

ll t, n, sen[MAXN];


int main(){

    cin >> t;
    for (int cse = 1; cse <= t; cse++){
        cin >> n;
        ll tot = 0;
        string res = "";
        for (int i = 0; i < n; i++){
            cin >> sen[i];
            tot += sen[i];
        }
        while (tot > 0){
            res += " ";
            int mx = max_element(sen, sen+n) - sen;
            sen[mx]--;
            tot--;
            res += char('A'+mx);

            if (tot > 0){
                int next = max_element(sen, sen+n) - sen;
                if (sen[next]*2 > tot){
                    sen[next]--;
                    tot--;
                    res += 'A' + next;
                }
            }
        }
        cout << "Case #" << cse << ":" << res << endl;





    }

    return 0;

}


