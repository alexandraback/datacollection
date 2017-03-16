

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int __lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int main() {
    int TC;
    cin >> TC;
    for ( int tc=1 ; tc<=TC ; ++tc ) {
        int B, N;
        cin >> B >> N;
        vector<int> cut_time(B);
        for ( int i=0 ; i<B ; ++i ) {
            cin >> cut_time[i];
        }

        int gcd = cut_time[0];
        int lcm = cut_time[0];
        for ( int i=1 ; i<B ; ++i ) {
            gcd = __gcd(gcd, cut_time[i]);
            lcm = __lcm(lcm, cut_time[i]);
        }

        for ( int i=0 ; i<B ; ++i ) {
            cut_time[i] /= gcd;
        }

        int rep = 0;
        for ( int i=0 ; i<B ; ++i ) {
            rep += lcm / cut_time[i];
        }
        N %= rep;
        N += rep;

        vector<int> wait(B);
        int mini, minv;
        for ( int i=0; i<N ; ++i ) {
            mini = 0;
            minv = wait[0];
            for ( int j=0 ; j<wait.size() ; ++j ) {
                if ( minv > wait[j] ) {
                    mini = j;
                    minv = wait[j];
                }
            }
            for ( int j=0 ; j<wait.size() ; ++j ) {
                wait[j] -= minv;
            }
            wait[mini] = cut_time[mini];
        }

        int res = mini + 1;
        printf("Case #%d: %d\n", tc, res);
    }
}

