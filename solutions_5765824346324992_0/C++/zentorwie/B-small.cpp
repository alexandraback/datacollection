#include <bits/stdc++.h>

using namespace std;


struct node {
    int t, id;
    node() {}
    node(int a, int b): t(a), id(b) {}
    bool operator < (const node& b) const {
        if (t != b.t) return t > b.t;
        return id > b.id;
    }
};


int B, N, M[1010];
int A[1010];

priority_queue<node> q;

bool check() {
    // printf("checking...");
    // for (int i = 1; i <= B; i++) printf("%d ", A[i]);
    // printf("\n");
    for (int i = 2; i <= B; i++) {
        if (A[i] != A[i-1]) return false;
    }
    return true;
}

int rec[100000000];

int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        while (!q.empty()) q.pop();
        scanf("%d%d", &B, &N);
        memset(A, 0, sizeof(A));
//        for (int i = 1; i <= N; i++) rec[i] = 0;
        for (int i = 1; i <= B; i++) scanf("%d", &M[i]);
        for (int i = 1; i <= B; i++) {
            q.push(node(0, i));
        }
        node p;
        int pr = 0;
        for (int i = 1; i < N; i++) {
            p = q.top(); q.pop();
//            printf("(%d, %d)\n", p.t, p.id);
            p.t += M[p.id];
            rec[i] = p.id;
            A[p.id] += M[p.id];
            q.push(p);
//            printf("i = %d\n", i);
            if (!pr && check()) {
                pr = i;
                break;
            }
        }
        int ans = 0;
        rec[0] = rec[pr];
//         for (int i = 1; i <= pr; i++) {
// //            printf("rec[%d] = %d\n", i, rec[i]);
//         }
        if (pr) {
            ans = rec[N%pr];
        }
        else {
            p = q.top();
            q.pop();
            ans = p.id;
        }
        printf("Case #%d: %d\n", kase, ans);
    }
        
    return 0;
}
    

