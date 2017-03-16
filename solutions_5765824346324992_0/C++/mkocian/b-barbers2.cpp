#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<iostream>
#include<iomanip>
#include<time.h>
#include<sstream>
#include<fstream>
#include<string>
#include<string.h>
#include<algorithm>
#include<queue>

#define nl printf("\n")

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int B;
        scanf("%d", &B);
        int N;
        scanf("%d", &N);

        priority_queue<pair<int, int>> Q;

        int LCM = 1;
        vector<int> barbers(B, 0);
        for (int k = 0; k < B; k++) {
            int Mk;
            scanf("%d", &Mk);
            barbers[k] = Mk;

            LCM = lcm(LCM, Mk);
            Q.push(make_pair(-0, -k));
        }

        int sum = 0;
        for (int k = 0; k < B; k++) {
            sum += LCM / barbers[k];
        }
        //printf("sum %d LCM %d\n", sum, LCM);

        N = 1 + (N-1) % sum;

        int barber;
        for (int n = 0; n < N; n++) {
            auto a = Q.top();
            barber = -a.second;
            Q.pop();

            Q.push(make_pair(a.first - barbers[barber], -barber));

        }

        printf("Case #%d: %d\n", t, barber+1);
    }
}

