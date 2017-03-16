#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


#define ll long long


bool onBoundary(const vector<double>& X, const vector<double>& Y, int target, int mask) {
    // smallest.
    int idx = -1;
    int N = X.size();
    for (int i=0;i<N;++i) {
        if (mask & (1<<i)) continue;
        if (idx == -1 || X[i] < X[idx] || X[i] == X[idx] && Y[i] < Y[idx]) {
            idx = i;
        }
    }

    int start = idx;

    double angleOffset = 3 * M_PI / 2 - 1e-6;

    //printf("Target %d, maks %d\n", target, mask);
    do {
        if (idx == target) return true;

        double bestNextAngle = 1e99;
        int bestNext = -1;
        double bestNextDist = 1e99;
        for (int i=0;i<N;++i) {
            //printf("Trying %d\n", i);
            if (mask & (1<<i)) continue;
            if (i == idx) continue;

            double dx = X[i] - X[idx];
            double dy = Y[i] - Y[idx];
            double angle = -std::atan2(dy, dx) - angleOffset;
            //printf("Angle is %.2f %2.f: %.2f\n", dx, dy, angle);
            while (angle < 0) angle += 2 * M_PI;
            // printf("%d is at %.2f from %d\n", i, angle * 180 / M_PI, idx);

            double dist = dx*dx + dy*dy;
            if (angle < bestNextAngle || abs(angle - bestNextAngle) < 1e-9 && dist < bestNextDist) {
                bestNextAngle = angle;
                bestNext = i;
                bestNextDist = dist;
            }
        }
        //printf("At %d, next is %d at %.2f\n", idx, bestNext, bestNextAngle * 180 / M_PI);

        idx = bestNext;
        angleOffset = fmod(bestNextAngle + angleOffset - 1e-6, 2 * M_PI);

    } while (idx != start);

    return false;
}

int mem[1<<15];
int numCuts(int mask) {
    int &ans = mem[mask];
    if (ans != -1) return ans;
    ans = 0;
    while (mask) {
        if (mask & 1) {
            ans++;
        }
        mask >>=1;
    }
    return ans;
}

int main() {
    memset(mem,-1,sizeof(mem));
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int N;
        cin>>N;
        vector<double> X(N);
        vector<double> Y(N);
        for (int i=0;i<N;++i) {
            cin>> X[i] >> Y[i];
        }


        printf("Case #%d:\n", t);
        for (int j=0;j<N;++j) {
            int best = N;

            for (int i=0;i<(1<<N);++i) {
                if (i & (1<<j)) continue;
                bool good = onBoundary(X, Y, j, i);
                if (good) {
                    best = min(best, numCuts(i));
                }
            }

            printf("%d\n", best);
        }

    }
}
