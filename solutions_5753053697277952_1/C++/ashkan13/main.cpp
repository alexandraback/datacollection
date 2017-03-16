// In the Name of Allah
// AD13

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/

pair<int, char> arr[1000];

/*_____________________________________________________________________________________*/

// check debug, read 2 times (until full!)
// think --> idea? --> really works?

int main() {
    //*
    freopen("aa.in", "r", stdin);
    freopen("aa.out", "w", stdout);
    //*/
    int T;
    cin >> T;
    For1 (tc, T) {
        //cerr << "--> " << tc << " / " << T << endl;
        int n;
        cin >> n;
        For (i, n) {
            cin >> arr[i].first;
            arr[i].second = 'A' + i;
        }

        cout << "Case #" << tc << ":";

        int last = n - 1;

        while (true) {
            sort (arr, arr + n);
            if (arr[last].first < 1) break;

            string res = " ";
            arr[last].first--;
            res += arr[last].second;

            sort (arr, arr + n);
            if (arr[last].first > 0 && arr[last].first > arr[last - 1].first) {
                arr[last].first--;
                res += arr[last].second;
            }

            cout << res;
        }

        cout << endl;
    }

    return 0;
}
/*

*/
