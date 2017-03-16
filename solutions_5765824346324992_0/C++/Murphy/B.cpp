#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main(){
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
    REP(caseN, caseNumber) {
        cerr<<caseN<<endl;
        int B, N;
        cin>>B>>N;
        vector<int> X(N, 0);
        REP(i, B) cin>>X[i];
        LL l = 0, r = (LL)1e15;
        int wait;
        while (l != r) {
            LL m = (l + r)/ 2;
            LL sum = 0;
            wait = -1;
            REP(i, B) {
                sum += m / X[i];
                if (m / X[i] * X[i] == m)
                    if (wait == -1)
                        wait = i;
            }
            // cout<<m<<' '<<l<<' '<<r<<' '<<sum<<' '<<wait<<endl;
            if (sum < N) l = m + 1;
            else //if (sum > N)
                r = m;
        }
        priority_queue<pair<LL, int> > PQ;
        LL m = max(0LL, l - 200000);
        LL sum = 0;
        if (N < 100)
            REP(i, B) PQ.push(make_pair(0, -i));
        else
        REP(i, B) {
            if (m / X[i] * X[i] == m) {
                sum += m / X[i] + 1;
                PQ.push(make_pair(-(m + X[i]), -i));
            }
            else {
                sum += m / X[i] + 1;
                PQ.push(make_pair(-(m / X[i] * X[i] + X[i]), -i));
            }
        }
        while (1) {
            pair<LL, int> k = PQ.top(); PQ.pop();
            wait = -k.second;
            sum++;
            // cout<<sum<<' '<<wait<<' '<<k.first<<endl;
            if (sum == N) break;
            PQ.push(make_pair(k.first - X[wait], -wait));
            // sum++;
        }
    	printf("Case #%d: %d\n", caseN + 1, wait + 1);
    }
    return 0;
}