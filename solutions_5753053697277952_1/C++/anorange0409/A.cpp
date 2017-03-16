#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    int num;
    int id;
    node(){}
    node(int x, int y ){
        num=x;id = y;
    }
} A[27];
bool cmp(node a, node b) {
    return a.num > b.num;
}
bool ok(int x, int y) {
    return x*2<=y;
}
int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T, N;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        cin >> N;
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i].num;
            A[i].id = i;
            total += A[i].num;
        }
        printf("Case #%d:",o);
        while (total > 0) {
            sort(A,A+N,cmp);
            if (ok(A[0].num-1, total-1) && ok(A[1].num, total - 1)) {
                A[0].num-=1;
                total--;
                printf(" %c", A[0].id + 'A');
            } else {
                total -= 2;
                A[0].num-=1;
                A[1].num-=1;
                printf(" %c%c", A[0].id + 'A', A[1].id + 'A');
            }
        }
        printf("\n");
    }
}
