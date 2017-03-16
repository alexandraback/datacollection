#include <iostream>

using namespace std;

typedef unsigned int uint;

void run();
long long gcd(long long, long long);

int main()
{
    uint T;
    cin >> T;
    for(uint i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        run();
        cout << endl;
    }
    return 0;
}

void run() {
    int B, N;
    cin >> B >> N;
    int* m = new int [B];
    int* status = new int [B];
    long long gT = 1;
    for(int i = 0; i < B; ++i) {
        cin >> m[i];
        status[i] = 0;
        if (gT <= N)
            gT = gT * m[i] / gcd(gT, m[i]);
    }
    int mod = 0;
    for(int i = 0; i < B; ++i) {
        mod += gT / m[i];
    }

    N %= mod;
    if(!N) N = mod;
    if(N <= B) {
        cout << N;
        return;
    }
    int ans = 0;
    for(int cnt = 0; cnt < N; ++cnt) {
        int minV = 1000000;
        for(ans = 0; ans < B; ++ans) {
            if(!status[ans]) {
                status[ans] = m[ans];
                break;
            } else {
                if(minV > status[ans]) minV = status[ans];
            }
        }
        if(ans == B) {
            bool flag = true;
            for(int i = 0; i < B; ++i) {
                status[i] -= minV;
                if(!status[i]) {
                    if(flag) {
                        ans = i;
                        flag = false;
                    }
                }
            }
            status[ans] = m[ans];
        }
    }
    cout << ans + 1;
}

long long gcd (long long a, long long b)
{
    long long c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}
