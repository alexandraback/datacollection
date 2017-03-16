#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "A.in"
#define FILEOUT "A.out"



int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
        int N;
        cin >> N;
        int A[N];
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            sum += A[i];
        }

        cout << "Case #" << _ << ": ";
        int steps = sum - 2;

        if (sum % 2 == 1) {
            int indexMax = -1;
            int maxValue = -1;
            for (int j = 0; j < N; ++j) {
                if (A[j] > maxValue) {
                    maxValue = A[j];
                    indexMax = j;
                }
            }
            A[indexMax]--;
            cout << char('A' + indexMax) << " ";
            sum--;
        }



        for (int i = 0; i < sum / 2; ++i) {
            int indexMax = -1;
            int maxValue = -1;
            for (int j = 0; j < N; ++j) {
                if (A[j] > maxValue) {
                    maxValue = A[j];
                    indexMax = j;
                }
            }
            A[indexMax]--;
            // cout << indexMax << endl;
            int indexMax2 = -1;
            maxValue = -1;
            for (int j = 0; j < N; ++j) {
                if (A[j] > maxValue) {
                    maxValue = A[j];
                    indexMax2 = j;
                }
            }
            A[indexMax2]--;
            cout << char('A' + indexMax) << char('A' + indexMax2);
            if (i + 1 < sum / 2) {
                cout << " ";
            }
        }

        // char r[2];
        // int count = 0;
        // for (int i = 0; i < N; ++i) {
        //     if (A[i] > 0) {
        //         r[count] = char('A' + i);
        //         count++;
        //     }
        // }

        // cout << r[0] << r[1];
        //Output answer
        

        cout << endl;
    }
    return 0;
}