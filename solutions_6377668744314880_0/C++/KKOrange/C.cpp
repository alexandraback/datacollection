#include <iostream>
#include <vector>
using namespace std;

const long long int INF = 1e8;

struct point {
    long long int x, y;
};

int N;

point a[3005];
point orig[3005];

bool ccw(point a, point b, point c) {
    point v1 = {b.x - a.x, b.y - a.y};
    point v2 = {c.x - a.x, c.y - a.y};
    //cout << v1.x << " " << v1.y << "\n";
    //cout << v2.x << " " << v2.y << "\n";
    if(v2.x == 0 && v2.y == 0) {
        return false;
    }
    long long int res = v1.x*v2.y - v1.y*v2.x;
    //cout << res << "\n";
    if(res == 0) {
        if(v1.x*v2.x >= 0 && v1.y*v2.y >= 0) {
            // same direction
            //cout << "same\n";
            long long int dist1 = v1.x*v1.x + v1.y*v1.y;
            long long int dist2 = v2.x*v2.x + v2.y*v2.y;
            return dist1 > dist2;
        } else {
            // Opposite way
            //cout << "diff\n";
            return false;
        }
    } else {
        return res > 0;
    }
}

long long int ccw2(point a, point b, point c) {
    point v1 = {b.x - a.x, b.y - a.y};
    point v2 = {c.x - a.x, c.y - a.y};
    long long int res = v1.x*v2.y - v1.y*v2.x;
    return res;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        point cur = {INF, INF};
        for(int i = 1; i <= N; i++) {
            cin >> a[i].x >> a[i].y;
            if(a[i].x < cur.x) {
                cur = a[i];
            }
            orig[i] = a[i];
        }
        vector<point> hull;
        hull.push_back(cur);
        // Gift wrapping
        cur = hull[0];
        do {
            point next = cur;
            int id = -1;
            for(int i = 1; i <= N; i++) {
                if(a[i].x == INF) {
                    continue;
                }
                if((cur.x == next.x && cur.y == next.y) || ccw(cur, next, a[i])) {
                    next = a[i];
                    //cout << "Next choice " << next.x << " " << next.y << "\n";
                    id = i;
                }
            }
            a[id].x = INF;
            a[id].y = INF;
            hull.push_back(next);
            //cout << "Next choice " << next.x << " " << next.y << "\n";
            cur = next;
        } while(hull[0].x != cur.x || hull[0].y != cur.y);
        hull.erase(--hull.end());

        //cout << "Hull is " << "\n";
        for(int i = 0; i < hull.size(); i++) {
            //cout << hull[i].x << " " << hull[i].y << "\n";
        }


        // Found the hull, restore originals
        for(int i = 1; i <= N; i++) {
            a[i] = orig[i];
        }

        cout << "Case #" << t << ":\n";
        if(N <= 3) {
            for(int i = 1; i <= N; i++) {
                cout << "0\n";
            }
        } else {
            for(int i = 1; i <= N; i++) {
                cur = a[i];
                int fewest = INF;
                ////cout << "Looking at " << cur.x << " " << cur.y << "\n";
                for(int j = 0; j < hull.size(); j++) {
                    if(hull[j].x == cur.x && hull[j].y == cur.y) {
                        fewest = 0;
                    }
                }
                if(fewest != 0) {
                for(int j = 0; j < hull.size(); j++) {
                    for(int k = j+1; k < hull.size(); k++) {
                        if(j != k) {
                            long long int dir = ccw2(hull[j], hull[k], cur);
                            ////cout << "Going from " << j << " to " << k << " gives dir " << dir << "\n";
                            if(dir > 0) {
                                ////cout << "Cost is " << k-j-1 << "\n";
                                fewest = min(fewest, k-j-1);
                            } else if(dir < 0) {
                                ////cout << "Cost is " << (int)hull.size()-(k-j-1) << "\n";
                                fewest = min(fewest, (int)hull.size()-(k-j+1));
                            } else {
                                ////cout << "Cost is " << k-j-1 << " or ";
                                ////cout << (int)hull.size()-(k-j-1) << "\n";
                                fewest = min(fewest, k-j-1);
                                fewest = min(fewest, (int)hull.size()-(k-j+1));
                            }
                        }
                    }
                }
                }
                cout << fewest << "\n";
            }
        }
    }
    return 0;
}
