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


int main(){
    int T, N;
    cin >> T;
    for(int t = 0; t < T; ++t){
        cin >> N;
        vi n(N);
        for(int i = 0; i < N; ++i){
            cin >> n[i];
        }

        int first = 0;
        for(int i = 1; i < N; ++i){
            first += max(0, n[i-1] - n[i]);
        }

        int secondrate = 0,
            second = 0;
        for(int i = 1; i < N; ++i){
            secondrate = max(secondrate, n[i-1] - n[i]);
        }

        //second = min(n[0], secondrate);
        //second = min(n[0], secondrate);
        for(int i = 0; i < N - 1; ++i){
            //if(n[i] <= secondrate){
                //second += n[i];
            //} else if(n[i+1] > {
                
            //}

            //if(secondrate > n[i]-n[i-1]){
                //printf("Round %d: eats by rate %d\n", i, secondrate);
            //} else {
                //printf("Round %d: eats by rate %d\n", i, n[i]-n[i-1]);
            //}
            //printf("Round %d: eats %d\n", i, min(n[i]-n[i-1], secondrate));
            second += min(n[i], secondrate);
        }

        printf("Case #%d: %d %d\n", t+1, first, second);
    }
}
