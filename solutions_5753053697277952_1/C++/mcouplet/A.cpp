#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MAX_N 26

typedef pair<int, int> ii;
typedef long long ll;

int N; int P[MAX_N];
int sum;

bool valid() {
    for(int i = 0; i < N; ++i)
        if(P[i] > sum/2)
            return false;
    return true;
}

int main() {
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        printf("Case #%d: ", tc);
        scanf("%d", &N);
        sum = 0;
        int distinct = N;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &P[i]);
            sum += P[i];
        }
        while(distinct != 2 || sum%2 != 0) {
            int iMax, Max = 0;
            for(int i = 0; i < N; ++i) {
                if(P[i] > Max) {
                    Max = P[i];
                    iMax = i;
                }
            }
            P[iMax]--;
            if(P[iMax] == 0)
                distinct--;
            printf("%c%c", 'A'+iMax, (sum == 1) ? '\n' : ' ');
            sum--;

            if(!valid())
                printf("INVALID\n");
        }
        int a = -1, b;
        for(int i = 0; i < N; ++i) {
            if(P[i]) {
                if(a == -1)
                    a = i;
                else
                    b = i;
            }
        }
        while(P[a]--)
            printf("%c%c%c", 'A' + a, 'A' + b, (P[a] == 0) ? '\n' : ' ');
    }
}

