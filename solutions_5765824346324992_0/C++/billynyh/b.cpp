#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

#define MAX_M 100010l
//#define MAX_M 30

int DEBUG = 0;

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int B, N; scanf("%d%d", &B, &N);
        long long a[B];
        for (int i=0;i<B;i++) {
            scanf("%lld", &a[i]);
        }

        int ans = 0;
        if (B >= N) {
            ans = N;
        } else {
            N -= B;
            // b search on time
            long long l = 0, r = N * MAX_M;
            long long ansT = 0;
            //printf("%lld %lld\n", l, r);
            while (l < r) {
                long long m = (l+r)/2;
                // check served how many customer
                long long served = 0;
                for (int i=0;i<B;i++) {
                    served += m / a[i];
                }
                if (DEBUG) printf("lr %lld %lld\n", l, r);
                if (DEBUG) printf("~ %lld %lld\n", m, served);
                if (served >= N) {
                    r = m;
                    ansT = m;
                } else {
                    l = m + 1;
                }
            }
            // find (N-last_served)th availabe in time = l
            long long last_served = 0;
            for (int i=0;i<B;i++) {
                last_served += (ansT - 1) / a[i];
            }
            long long target = N - last_served;

            if (DEBUG) printf("!! ansT:%lld, last_served:%lld target:%lld\n", ansT, last_served, target);

            int count = 0;
            for (int i=0;i<B;i++) {
                if (ansT % a[i] == 0) {
                    count ++;
                    if (count == target) {
                        ans = i + 1;
                    }

                } 
            }

            if (ans == 0) {
                printf("ERROR\n");
                printf("!! ansT:%lld, last_served:%lld target:%lld\n", ansT, last_served, target);
            }
        
        }

        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
    
}
