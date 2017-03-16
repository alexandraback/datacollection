#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
} 

int simulate(int B, int m[], int res){
    int* remain = new int[B];
    for(int i = 0; i < B; i++) {
        remain[i] = 0;
    }
    int ansIdx = B - 1;
    for(int i = 0; i < res; i++) {
        int leastIdx = B;
        for(int i = 0; i < B; i++) {
            if(remain[i] == 0) {
                leastIdx = i;
                break;
            }
        }
        ansIdx = leastIdx;
        remain[leastIdx] = m[leastIdx];
        int minLeft = 1000000;
        for(int i = 0; i < B; i++) {
            if(remain[i] < minLeft) {
                minLeft = remain[i];
            }
        }
        for(int i = 0; i < B; i++) {
            remain[i] -= minLeft;
        }

    }
    delete remain;
    return ansIdx;
}

int solve(int B, int m[], long N){
   int lcm = m[0];
   for(int i = 1; i < B; i++) {
       int g = gcd(m[i], lcm);
       lcm = lcm * m[i] / g;
   } 
//   printf("lcm=%d\n", lcm);
   int* num = new int[B];
   int total = 0;
   for(int i = 0; i < B; i++) {
       num[i] = lcm / m[i];
       total += num[i];
   }
//   printf("total=%d\n", total);
   int res = N % total;
   if(res == 0) res = total;
//   printf("res=%d\n", res);
   int ans = simulate(B, m, res);
   delete num;
   return ans;
} 


int main() {
    freopen("B-small-attempt1.in", "r", stdin);
//    freopen("A-large.in", "r", stdin);
//    freopen("data.in", "r", stdin);
    int T;
    int B;
    long N;
    int state[10024];
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d %ld", &B, &N);
        for(int j = 0; j < B; j++){
            scanf("%d", state+j);
        }
        int res = solve(B, state, N);
        printf("Case #%d: %d\n", i, res + 1);
    }
    return 0;
}
