#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void solve(int N, int state[], int& m1, int& m2){
    m1 = 0;
    m2 = 0;
    int sp = 0;
    for(int i = 1; i < N; i++) {
        if(state[i] < state[i-1]) {
            //method1
            m1 += state[i-1] - state[i];
            //method2
            if(state[i-1] - state[i] > sp) {
                sp = state[i-1] - state[i];
            }
        }
    }
    for(int i = 0; i + 1 < N; i++){
        m2 += (sp < state[i] ? sp: state[i]);
    }
} 

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
//    freopen("data.in", "r", stdin);
    int T;
    long long X;
    int N;
    int state[10024];
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", state+i);
        }
        int a,b;
        solve(N, state, a, b);
        printf("Case #%d: %d %d\n", i, a, b);
    }
    return 0;
}
