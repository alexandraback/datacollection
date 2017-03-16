#include <iostream>


using namespace std;

long long int N, X;
long long int a[1005];

long long int serviced;
long long int available;
bool y[1005];
void check(long long int t) {
    serviced = 0;
    available = 0;
    if(t == 0) {
        available = N;
    } else {
        for(long long int i = 1; i <= N; i++) {
            serviced += t/a[i];
            if(t%a[i] == 0) {
                available++;
                y[i] = true;
            } else {
                serviced++;
                y[i] = false;
            }
        }
    }
//    cout << "Served " << serviced << ", availble " << available << "\n";
}

int main() {
    long long int T;
    cin >> T;
    for(long long int t = 1; t <= T; t++) {
        cin >> N >> X;
        for(long long int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        long long int l = 0;
        long long int r = 1e14;
        while(l != r) {
            long long int m = (l+r)/2;
            check(m);
            bool works = serviced + available >= X;
            if(works) {
                r = m;
            } else {
                l = m+1;
            }
        }
        check(l);
//        cout << "Answer is " << l << "\n";
//        cout << "Serviced " << serviced << " available " << available << "\n";
        X -= serviced;
        long long int ans = -1;
        for(long long int i = 1; i <= N; i++) {
            if(y[i]) {
                X--;
                if(X == 0) {
                    ans = i;
                    break;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
