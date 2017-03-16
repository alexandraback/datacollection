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
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        int R, C, N;
        cin >> R >> C >> N;

        int n1 = N,
            n2 = N;

        int one = 0,
            two = 0;

        //n1 -= (C / 2 + C % 2)*(R / 2 + R % 2) + (C / 2)*(R / 2);
        //n2 -= (C / 2)*(R / 2 + R % 2) + (C / 2 + C % 2)*(R / 2);

        vi  n1set = vi(5, 0),
            n2set = vi(5, 0);

        n1set[0] = (C / 2 + C % 2)*(R / 2 + R % 2) + (C / 2)*(R / 2);
        n2set[0] = (C / 2)*(R / 2 + R % 2) + (C / 2 + C % 2)*(R / 2);

        //if(R == 1){
            //n1set[1] = 1 - (C % 2);
            //n1set[2] = (C - 1) / 2;

            //n2set[1] = 1 + (C % 2);
            //n2set[2] = (C / 2) - 1;
        //} else if(C == 1){
            //n1set[1] = 1 - (R % 2);
            //n1set[2] = (R - 1) / 2;

            //n2set[1] = 1 + (R % 2);
            //n2set[2] = (R / 2) - 1;
        //} else 
        //if(C * R <= 4){
            //continue;
        //}

        if(C*R == 1){
            printf("Case #%d: %d\n", t+1, 0);
            continue;
        }

        if(C < R) swap(R, C);

        if(R == 1){
            n1set[1] = 1 - C % 2;
            n2set[1] = 1 + C % 2;

            n1set[2] = C / 2 - 1 + (C % 2);
            n2set[2] = (C - 1) / 2 - 1 + (C - 1) % 2;
        } else if(R % 2 == 0){
            n1set[2] = 2;
            n2set[2] = 2;

            if(R == 2){
                if(C > 2){
                    n1set[3] = C - 2;
                    n2set[3] = C - 2;
                }
            } else if(C == 2){
                if(R > 2){
                    n1set[3] = R - 2;
                    n2set[3] = R - 2;
                }
            } else {
                n1set[3] = C - 2 + R - 2;
                n2set[3] = C - 2 + R - 2;
            }
        } else if(C % 2 == 0){
            n1set[2] = 2;
            n2set[2] = 2;

            if(C == 2){
                n1set[3] = R - 2;
                n2set[3] = R - 2;
            } else {
                n1set[3] = C - 2 + R - 2;
                n2set[3] = C - 2 + R - 2;
                //n2set[3] = ((C - 2)/2 + (C - 2) % 2)*2;
            }
        } else {
            n1set[2] = 0;
            n2set[2] = 4;

            n1set[3] = ((C - 2)/2 + 1)*2 + ((R - 2)/2 + 1)*2;
            n2set[3] = (C - 3) + (R - 3);
        }

        //if(R > 2 && C > 2){
            //n1set[3] = C - 2 + R - 2;
            //n2set[3] = C - 2 + R - 2;

            ////C--, R--;
            ////n1set[4] = (C / 2 + C % 2)*(R / 2 + R % 2) + (C / 2)*(R / 2);
            ////n2set[4] = (C / 2)*(R / 2 + R % 2) + (C / 2 + C % 2)*(R / 2);
        //} else if(R == 2){
            //if(C > 2){
                //n1set[3] = C - 2;
                //n2set[3] = C - 2;
            //}
        //} else if(C == 2){
            //if(R > 2){
                //n1set[3] = R - 2;
                //n2set[3] = R - 2;
            //}
        //}
        n1set[4] = (C*R) - n1set[0] - n1set[1] - n1set[2] - n1set[3];
        n2set[4] = (C*R) - n2set[0] - n2set[1] - n2set[2] - n2set[3];

        //printf("First:");
        //for(int i = 0; i < 5; ++i){
            //printf(" %d", n1set[i]);
        //}
        //printf("\n");

        //printf("Second:");
        //for(int i = 0; i < 5; ++i){
            //printf(" %d", n2set[i]);
        //}
        //printf("\n");

        for(int i = 0; i < 5; ++i){
            if(n1 >= n1set[i]){
                one += n1set[i]*i;
                n1 -= n1set[i];
            } else {
                one += n1 * i;
                n1 = 0;
            }

            if(n2 >= n2set[i]){
                two += n2set[i]*i;
                n2 -= n2set[i];
            } else {
                two += n2 * i;
                n2 = 0;
            }
        }
        printf("Case #%d: %d\n", t+1, min(one, two));

    }
}
