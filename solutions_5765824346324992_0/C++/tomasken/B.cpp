#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

struct cmp {
    bool operator()(const ii& lhs, const ii &rhs){
        if(lhs.first != rhs.first) return lhs.first >= rhs.first;
        return lhs.second >= rhs.second;
    }
};

int main(){
    int T;
    int N;
    cin >> T;
    for(int t = 0; t < T; ++t){
        int B;
        cin >> B >> N;
        vi M(B);
        int mn = INF;
        for(int i = 0; i < B; ++i){
            cin >> M[i];
            mn = min(M[i], mn);
        }

        ll lo = 0,
            hi = 10000000000000000;
                //static_cast<ll>(mn)*static_cast<ll>(N);

        ll total = 0;
        ll result = -1,
           restot = 0;
        while(lo <= hi){
            //printf("%lld %lld\n", lo, hi);
            ll mid = lo + (hi - lo)/2;
            total = 0;

            for(int i = 0; i < B; ++i){
                total += mid / M[i];
                //if(mid % static_cast<ll>(M[i]) == 0){
                    //total++;
                //}
            }
            //printf("total: %d\n", total);

            if(total >= static_cast<ll>(N - 100)){
                hi = mid - 1;
                result = mid;
                restot = total;
            } else {
                lo = mid + 1;
            }
        }
        //cout << "blaa" << endl;

        //result = 0, restot = 0;
        priority_queue<ii,vii,cmp> Q;
        for(int i = 0; i < B; ++i){
            Q.push(ii(result - result % M[i], i));
        }
        for(int i = restot + 1; i < N; ++i){
            ii front = Q.top(); Q.pop();
            //printf("%d %d\n", front.first, front.second);
            front.first += M[front.second];
            Q.push(front);
        }
        printf("Case #%d: %d\n", t + 1, Q.top().second + 1);

        //printf("final %lld\n", result);
        //printf("restot %lld\n", restot);
        //if(lo > hi){
            //lo--;
        //}


        //total = 0;
        //for(int i = 0; i < B; ++i){
            //total += result / M[i] + 1;
        //}

        //int barb = -1;
            //mndiff = INF;
        //int seen = 0;
        //cout << total << endl;
        //vii bla;
        //for(int i = 0; i < B; ++i){
            //bla.push_back(ii(restot % M[i], i));
        //}
        //sort(bla.begin(), bla.end());

        //for(int i = B-1; i >= 0; --i){
           //if((restot-seen) == N){
                //barb = i + 1;
                //break;
            //}
            //if(restot % M[i] == 0){
                //seen++;
            //}
            ////if(M[i] <= mndiff){
                ////barb = i + 1;
                ////mndiff = M[i];
            ////}
        //}
        //assert(barb > 0);
        //printf("Case #%d: %d\n", t + 1, barb);
        //printf("Case #%d: %d\n", t + 1, bla[0].second + 1);
    }
}
