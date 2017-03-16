#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <array>
#include <tuple>
#include <utility>
#include <cctype>
#include <typeinfo>
using namespace std;

#define pp make_pair
#define len(x)  (int((x).size()))
#define append push_back
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define ii(n)    ff(i, n)
#define kk(n)    ff(k, n)
#define mm(n)    ff(m, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define iii(a, b) fff(i, a, b)
#define kkk(a, b) fff(k, a, b)
#define mmm(a, b) fff(m, a, b)
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }

using LL = long long;
using pii = pair<int, int>;


const int INF = 2147483647;

struct xy {
    double x, y;
    //xy(double x1, double y1) : x(x1), y(y1) { }
    double size() {
        return hypot(x, y);
    }
};
xy mxy(double x, double y) {
    xy rr;
    rr.x = x;
    rr.y = y;
    return rr;
}
xy operator-(xy a, xy b) { return mxy(a.x - b.x, a.y - b.y); }
xy operator+(xy a, xy b) { return mxy(a.x + b.x, a.y + b.y); }
double operator* (xy a, xy b) { return a.x*b.x + a.y*b.y; }
xy operator*(double a, xy b) { return mxy(a*b.x, a*b.y); }


double dist2line(xy &pt, xy &pt_on_line, xy &dir) {
    xy tocentre = pt - pt_on_line;
    double along_dir = tocentre * dir;
    xy orth_to_centre = tocentre - (along_dir * dir);
    return orth_to_centre.size();
}


int solve(int tr, vector<xy> &trees, vector<vector<int> > &clusters,
vector<double> &cluster_radii) {
    xy here = trees[tr];
    int rr = INF;
    ii (len(trees)) {
        if (tr == i)
            continue;
        //if( 4 ==tr ) printf("\n\nOther tree %d\n", i);
        xy other = trees[i];

        xy dir = other - here;
        dir = (1.0 / dir.size()) * dir;
        xy odir = mxy(-dir.y, dir.x);
        int right = 0;
        int left = 0;
        kk (len(clusters)) {
            xy centre = trees[clusters[k][0]];
            if (dist2line(centre, here, dir) > cluster_radii[k] + 0.1) {
                //if (4 == tr) printf("Cluster %d ok\n", k);
                if ((centre-here) * odir > 0)
                    left += len(clusters[k]);
                else
                    right += len(clusters[k]);
                continue;
            }

            mm (len(clusters[k])) {
                xy there = trees[clusters[k][m]];
                double d = dist2line(there, here, dir);
                if (abs(d) < 1e-8)
                    continue;
                //if (4 == tr) printf("Cluster %d broken with %d at %g\n", k, m, d);
                if ((there-here) * odir > 0)
                    left += 1;
                else
                    right += 1;
            }

        }
        //if (4 == tr) printf("l r %d %d\n", left, right);
        rr = min(rr, min(left, right));
    }
    return rr;
}


int main() {

    int T;
    cin >> T;

    fff (icase, 1, T+1) {
        int N;
        cin >> N;
        vector<xy> trees(N);
        ii (N)
            cin >> trees[i].x >> trees[i].y;

        if (N <= 3) {
            printf("Case #%d:\n", icase);
            ii (N)
                printf("0\n");
            continue;
        }

        int cluster_size = int(sqrt(N));
        vector<vector<int> > clusters;
        vector<double> cluster_radii;
        vector<int> clustered(N, 0);

        int remaining = N;
        mm (11) {
            int allocated = 0;
            if (remaining < cluster_size)
                break;
            vector<vector<pair<double, int> > > dists(remaining, 
                   vector<pair<double, int> >(remaining));
            vector<pair<double, int> > neardists(remaining);
            int ir = -1;
            ii (N) {
                if (clustered[i])
                    continue;
                ++ir;

                int kr = -1;
                kk (N) {
                    if (clustered[k])
                        continue;
                    ++kr;

                    dists[ir][kr] = pp((trees[i] - trees[k]).size(), k);
                }
                sort(all(dists[ir]));
                neardists[ir] = pp(dists[ir][cluster_size-1].xx, ir);
            }
            sort(all(neardists));
            ff (ir, remaining) {
                int clust_cand_index = neardists[ir].yy;
                bool fail = false;
                kk (cluster_size) {
                    if (clustered[dists[clust_cand_index][k].yy]) {
                        fail = true;
                        break;
                    }
                }
                if (fail) continue;
                vector<int> cluster;
                kk (cluster_size) {
                    int ind = dists[clust_cand_index][k].yy;
                    clustered[ind] = 1;
                    ++allocated;
                    cluster.append(ind);
                }
                clusters.append(cluster);
                cluster_radii.append(
                    dists[clust_cand_index][cluster_size-1].xx);
            }
            remaining -= allocated;
        }

        ii (N) {
            if (clustered[i])
                continue;
            vector<int> cluster(1, i);
            clusters.append(cluster);
            cluster_radii.append(0.1);
        }

        /*
        ii (len(clusters)) {
            printf("clust %d %g: ", i, cluster_radii[i]);
            kk (len(clusters[i]))
                printf("%d ", clusters[i][k]);
            printf("\n");
        }
        */

        printf("Case #%d:\n", icase);
        ii (N)
            printf("%d\n", solve(i, trees, clusters, cluster_radii));
        
    }
    
    return 0;
}




