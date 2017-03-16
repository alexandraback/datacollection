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
const int N = 1e4;
const int INF = 1e9;

struct pnt {
    long long x, y; 
    pnt () { }
    pnt (long long x, long long y): x(x), y(y) { }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    long long operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    long long operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    long long len2() {
        return x * x + y * y;
    }
    bool operator < (pnt A) {
        //this->Epr();
        //A.Epr();
        int part1 = (y > 0 || (y == 0 && x > 0));
        int part2 = (A.y > 0 || (A.y == 0 && A.x > 0));
        if (part1 == part2) 
            return (*this) * A > 0;
        return part1 < part2;
    }
    bool operator == (pnt A) {
        int part1 = (y > 0 || (y == 0 && x > 0));
        int part2 = (y > 0 || (y == 0 && x > 0));
        return part1 == part2 && (*this) * A == 0;
    }
    pnt rotate() {
        return pnt(-y, x);
    }
    void Epr() {
        cerr << "x y: " << x << " " << y << endl;
    }
};

struct event {
    pnt A;
    int type;
    event() { }
    event(pnt A, int type): A(A), type(type) { }
    bool operator == (event other) {
        return A == other.A && type == other.type;
    }
    void Epr() {
        cerr << "type x y: " << type << " " << A.x << " " << A.y << endl;
    }
};

pnt p[N];
event b[N];
int n;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld%lld", &p[i].x, &p[i].y);
}

bool cmpE(event x, event y) {
    return x.A < y.A || (x.A == y.A && x.type < y.type);
}

vector < int > solve() {
    vector < int > answer(n, INF);
    if (n <= 2) {
        answer.assign(n, 0); 
        return answer;
    }
    for (int i = 0; i < n; i++) {
        //db(i);
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            b[cur++] = event(p[j] - p[i], -1);
            b[cur++] = event(p[i] - p[j], 1);
        }
        sort(b, b + cur, cmpE);
        //for (int j = 0; j < cur - 1; j++)
            //assert(b[j].A < b[j + 1].A);
        //for (int j = 0; j < cur; j++)
            //b[j].Epr();
        //assert(cmpE(b[0], b[3]) == 1);
        //assert(b[0].A < b[3].A);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            pnt A = (p[j] - p[i]);
            cnt += A.y < 0 || (A.y == 0 && A.x < 0);
        }
        int res = cnt;
        for (int i = 0; i < cur; ) {
            int j = i;
            for (; i < cur && b[j] == b[i]; i++)
                cnt += b[i].type;
            res = min(cnt, res);
        } 
        res = max(res, 0);
        //assert(res >= 0);
        answer[i] = min(answer[i], res);
    }
    return answer; 
}

void printAns(vector < int > a) {
    for (auto x: a)
        printf("%d\n", x);
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
            //cerr << "tt: " << tt << endl;
            printf("Case #%d:\n", tt + 1);
            read();
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}

