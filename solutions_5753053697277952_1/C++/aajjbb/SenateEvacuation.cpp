#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T, N;
int P[30];

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        int all = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            
            all += P[i];
        }

        cout << "Case #" << t << ": ";
        
        while (all > 0) {
            int ca = -1;
            int cb = -1;
            int ia = -1;
            int ib = -1;
            
            for (int i = 0; i < N; i++) {
                if (P[i] > 0 && P[i] > ca) {
                    ca = P[i];
                    ia = i;
                }
            }

            P[ia] -= 1;
            
            for (int i = 0; i < N; i++) {
                if (P[i] > cb) {
                    cb = P[i];
                    ib = i;
                }
            }

            //cout << ia << " " << ib << endl;
            if (ib == -1) {
                all -= 1;
                cout << char('A' + ia) << " ";
            } else {
                P[ib] -= 1;
                all -= 2;
                
                bool valid = true;
                
                for (int i = 0; i < N; i++) {
                    if (P[i] > all - P[i]) {
                        valid = false;
                    }
                }

                if (!valid) {
                    P[ib] += 1;
                    all += 1;

                    cout << char('A' + ia) << " ";
                } else {
                    cout << char('A' + ia) << char('A' + ib) << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
