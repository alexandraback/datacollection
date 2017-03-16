
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#define MAXN 1024
#define EPS 1e-9

using namespace std;

int N;
int gx[MAXN], gy[MAXN];

int n;
int x[MAXN], y[MAXN];

double dist(int i, int j)	{
	double dx = x[i] - x[j], dy = y[i] - y[j];
	return sqrt(dx * dx + dy * dy);
}

double cosine(int i, int j, int k)	{
	double A = dist(j, k), B = dist(k, i), C = dist(i, j);
	return (C * C + A * A - B * B) / (2 * C * A);
}

int findNext(int prev, int cur)	{
    int next = -1;
    double bestCos = 1.1;
    for (int i = 0; i < n; i++)	{
        if (i == prev || i == cur)
            continue;
        double curCos = cosine(prev, cur, i);
        if (curCos < bestCos - EPS
                || (fabs(curCos - bestCos) < EPS
                    && dist(cur, i) < dist(cur, next)))
            bestCos = curCos, next = i;
    }
    assert(next != -1);
    return next;
}

vector <int> getHull(const vector <int> &pts) {
    n = 0;
    for (int i : pts)
        x[n] = gx[i], y[n] = gy[i], n++;

    vector <int> hull;

    int first = 0;
    for (int i = 0; i < n; i++)
        if (x[i] < x[first] || (x[i] == x[first] && y[i] < y[first]))
            first = i;
    hull.push_back(first);

    int next = -1;
    for (int i = 0; i < n; i++)	{
        if (i == first)
            continue;
        if (x[i] == x[first] && (next == -1 || y[i] < y[next]))
            next = i;
    }
    if (next == -1)	{
        double bestSlope = -1e9;
        for (int i = 0; i < n; i++)	{
            if (i == first)
                continue;
            double slope = 1.0 * (y[i] - y[first]) / (x[i] - x[first]);
            if (slope > bestSlope + EPS ||
                    (fabs(slope - bestSlope) < EPS
                     && (next == -1 || dist(i, first) < dist(next, first))))
                bestSlope = slope, next = i;
        }
    }
    assert(next != -1);
    hull.push_back(next);

    int cur = first;
    while (next != first) {
        int prev = next;
        next = findNext(cur, next);
        hull.push_back(next);
        cur = prev;
    }
    hull.pop_back();
    return hull;
}

void solve() {
    vector <int> r(N);
    for (int i = 0; i < N; i++)
        r[i] = max(N - 3, 0);
    for (int mask = 1; mask < (1 << N); mask++) {
        vector <int> pts;
        for (int i = 0; i < N; i++)
            if (mask & (1 << i))
                pts.push_back(i);
        if (pts.size() <= 3)
            continue;

        /*
        cerr << "pts: ";
        for (int i : pts)
            cerr << i << " ";
        cerr << endl;
        */

        vector <int> hull = getHull(pts);
        for (int i : hull) {
            int j = pts[i];
            //cerr << j << " ";
            r[j] = min(r[j], N - (int) pts.size());
        }
        //cerr << endl;
    }
    for (int i = 0; i < N; i++)
        cout << r[i] << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> gx[i] >> gy[i];
        cout << "Case #" << t << ":" << endl;
        solve();
    }
}

