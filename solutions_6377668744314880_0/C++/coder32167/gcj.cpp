#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <string.h>
#include <math.h>
#include <stdlib.h>  
#include <stack>   
using namespace std;  

const int MOD = 100007;

struct Node {
    long long x;
    long long y;
    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
};

int N, B, K, Q;
Node node[3005];

int result_cut[3005];

long long direction(Node p1, Node p2, Node p3)
{
    return (p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x);
}

bool mult(Node sp, Node ep, Node op){
    return (sp.x - op.x) * (ep.y - op.y)
        >= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const Node &l, const Node &r){
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(Node pnt[], int n, Node res[]){
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && mult(pnt[i], res[top], res[top-1])) {
            top--;
        }
        res[++top] = pnt[i];
    }
    len = top; res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) {
    while (top!=len && mult(pnt[i], res[top],
    res[top-1])) top--;
    res[++top] = pnt[i];
    }
    return top; // 返回凸包中点的个数
}

int test_run(int key)
{
    Node pnt[1000];
    Node res[1000];

    int pnt_num = 0;

    for(int i = 0; key > 0; ++i) {
        if(key % 2 == 1) {
            pnt[pnt_num++] = node[i];
        }
        key /= 2;
    }
    int res_num = graham(pnt, pnt_num, res);
    for(int i = 0; i < res_num; ++i) {
        for(int j = 0; j < N; ++j) {
            if(0 == direction(node[j], res[i], res[(i + 1)%res_num])) {
                result_cut[j] = min(result_cut[j], N - pnt_num);
            }
        }
    }
    return 0;
}

int run()
{
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        cin >> node[i].x >> node[i].y;
        //scanf("%lld%lld", &(node[i].x), &(node[i].y));
        result_cut[i] = N;
    }

    int max_test_num = (1 << N);
    for(int i = 1; i < max_test_num; ++i) {
        test_run(i);
    }

    for(int i = 0; i < N; ++i) {
        cout << result_cut[i] << endl;
    }

    return 0;
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        printf("Case #%d:\n", t);
        run();
    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

