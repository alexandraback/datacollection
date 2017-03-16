#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<ll> pnt;

const int MAXN = 3005;

int n, x[MAXN], y[MAXN], ind[MAXN], sze, curn;
pnt pnts[MAXN];

bool cmp(int a, int b) {
    return atan2(y[a]-y[curn], x[a]-x[curn]) < atan2(y[b]-y[curn], x[b]-x[curn]);
}

ll cross(pnt p1, pnt p2) { return imag(conj(p1) * p2); }

void go(int casenum) {
    printf("Case #%d:\n", casenum);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
        pnts[i] = pnt(x[i], y[i]);
    }

    bool good = 0;
    for (int i=0; i<n-2; i++)
        if (cross(pnts[i+1]-pnts[i], pnts[i+2]-pnts[i]) != 0)
            good = 1;

    if (!good) {
        for (int i=0; i<n; i++) cout << "0\n";
        return;
    }

    for (curn=0; curn<n; curn++) {
        pnt p = pnts[curn];
        int ans = n-1;
        sze = 0;
        for (int i=0; i<n; i++)
            if (i!=curn) ind[sze++] = i;

        sort(ind, ind+sze, cmp);
        int p1 = 0, p2 = 0, q1 = 0, q2 = 0;
        while (p1<sze) {
            p2 = p1;
            while (cross(p-pnts[ind[p2]], pnts[ind[p1]]-p) == 0) p2=(p2+1)%sze;
            q1 = p2;
            while (cross(p-pnts[ind[q1]], pnts[ind[p1]]-p) > 0) q1=(q1+1)%sze;
            q2 = q1;
            while (q2 != p1 && cross(p-pnts[ind[q2]], pnts[ind[p1]]-p) == 0) q2=(q2+1)%sze;
            ans = min(ans, (q1+sze-p2)%sze);
            ans = min(ans, (p1+sze-q2)%sze);

            int p0 = p1;
            while (p1<sze && cross(p-pnts[ind[p1]], pnts[ind[p0]]-p) == 0) p1++;
        }

        printf("%d\n", ans);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) go(i);
}
