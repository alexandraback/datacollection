#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define pii pair<long long, long long>
#define xx first
#define yy second
#define pb push_back
#define mp make_pair


int T, n;
long long m;
long long cross(pii O,pii A,pii B){ // O is first point, A is contested point, B is certain point
    return (A.xx-O.xx)*(B.yy-O.yy)-(A.yy-O.yy)*(B.xx-O.xx); // RETURNS >0 IF Angle(OAB) IS COUNTER-CLOCKWISE
}


vector<pii > convexhull(vector<pii> points){
    vector<pii > hull;
    sort(points.begin(), points.end());
    //printf("**** DEBUGGERY ****\n");
	for (long long i = 0; i<points.size(); i++){ // LOWER HULL
        while (hull.size()>1 && cross(hull[hull.size()-2], hull[hull.size()-1], points[i])<0) {
            hull.erase(hull.begin()+hull.size()-1);
        }
        hull.pb(points[i]);
	}
	//printf("**** HALF-TIME ****\n");
	long long j = hull.size();
	for (long long i = points.size()-2; i>=0; i--){ // UPPER HULL
        while (hull.size()>j && cross(hull[hull.size()-2], hull[hull.size()-1], points[i])<0) {
            hull.erase(hull.begin()+hull.size()-1);
        }
        hull.pb(points[i]);
	}
	hull.erase(hull.begin()+hull.size()-1);
	return hull;
}

void recurse(long long x){

}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



    cin >> T;
    for (int q = 1; q<=T; q++){
        printf("Case #%d:\n", q);
        long long best[1000] = {0};
        long long x, y;
        cin >> n;
        vector<pii > points, hull;
        for (long long i = 0; i<n; i++){
            cin >> x >> y;
            points.pb(mp(x,y));
        }

        if (n==1) cout << "0" << endl;
        else if (n==2) cout << "0" << endl << "0" << endl;
        else{

            long long upper = 1<<n;
            long long maxsize = 1;
            for (long long i = 0; i<upper; i++){
                //cout << "bitmap = " << i << endl;
                vector<pii > run;
                for (long long j = 0; j<n; j++){
                    //cout << "j = " << j << endl;
                    if ((i&(1<<j)) > 0){
                        run.pb(points[j]);
                    }
                }

                long long sz = run.size();
                //cout << "size = " << sz << endl;
                if (sz<2) continue;
                hull = convexhull(run);
                //cout << "Hull found!" << endl;
                for (long long j = 0; j<n; j++){
                    for (long long k = 0; k<hull.size(); k++){
                        if (points[j].xx == hull[k].xx && points[j].yy == hull[k].yy){
                            best[j] = max(best[j], sz);
                        }
                    }
                }
            }
            /*
            for (long long i = 0; i<hull.size(); i++){
                printf("%d %d\n", hull[i].xx, hull[i].yy);
            }
            */


            for (long long i =0; i<n; i++){
                cout << n - best[i] << endl;
            }

        }

    }


}
