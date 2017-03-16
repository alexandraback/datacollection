#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1000 + 10;
const long long INF = 2e15;

int b[N];
int n, k;

void read() {
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; i++)
        scanf("%d", &b[i]);
}

long long check(long long t) {
    long long cnt = 0;
    for(int i = 0; i < k; i++) {
        cnt += t / b[i] + 1;
    }
    return cnt;
}


int solve() {
    long long l = -1;
    long long r = INF;
    while (r - l > 1) {
        if (check((l + r) / 2) >= n)
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    //db(r);
    long long tmp = n - check(r - 1); 
    //db(tmp);
    assert(tmp >= 0);
    for (int i = 0; i < k; i++)
        if (r % b[i] == 0) {
            tmp--;
            if (tmp == 0) {
                return i;
            }
        }
    assert(false);
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            //return 0;
            read();
            printf("%d\n", solve() + 1);
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}

