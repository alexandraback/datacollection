#include <iostream>

using namespace std;

int main() {
    long long n, t;
    long long i, j;
    long long b, k;
    long long num[1001];
    t = 1;
    cin>>n;
    long long ans;
    long long p;
    double val = 0.0;
    long long maxnum;
    while (t<=n) {
        cin >> b >> k;
        val = 0.0;
        maxnum = -1;
        for (i=0; i<b; i++) {
            cin>>num[i];
            val += 1.0/num[i];
            if (maxnum < num[i])
                maxnum = num[i];
        }
        if ( k <= b)
            ans = k;
        else {
            k -= b;
            p = (long long)(k/val);
            maxnum = p + 2*maxnum;
            ans = 0;
            for (; p<=maxnum; p++) {
                long sum = 0;
                long cnt = 0;
                for (i = 0; i<b; i++) {
                    sum += p/num[i];
                    if (p%num[i] == 0)
                        cnt++;
                }
                if (sum >= k) {
                    j = k+cnt-sum;
                    for (i=0; i<b; i++) {
                        if (p%num[i] == 0) {
                            if (j==1) {
                                ans = i+1;
                                break;
                            }
                            j--;
                        }
                    }
                    break;
                }
            }
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
        t++;
    }
    return 0;
}
