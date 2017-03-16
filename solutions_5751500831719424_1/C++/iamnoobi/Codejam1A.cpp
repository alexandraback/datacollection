#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void print_vector(vector<char> v);
void print_array(int* array, int start, int end);

#define FOR(i,a,b) for (int i = (a),_b = (b); i < _b; i++)
#define DOW(i,b,a) for (int i = (b),_a = (a); i > _a; i--)
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ((n >> b) & 1)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()

#define INF 1e9
#define PI acos(-1.0)

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

int tc, cse = 1, n, counter[200][200], nchar;
char all[200][200];
vector<char> sequence;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    s(tc);
    while(tc--){
        s(n);
        FOR(i, 0, n){
            ss(all[i]);
        }
        sequence.clear();
        sequence.pb(all[0][0]);
        FOR(i, 1, strlen(all[0])){
            if(all[0][i] != all[0][i-1]) sequence.pb(all[0][i]);
        }
        nchar = SZ(sequence);
        bool solve = true;
        fill(counter, 0);
        FOR(i, 0, n){
            int pointer = 0;
            char current = sequence[pointer];
            FOR(j, 0, strlen(all[i])){
                if(all[i][j] == current) counter[i][pointer]++;
                else if (all[i][j] != current) {
                    pointer++;
                    current = sequence[pointer];
                    if(all[i][j] != current){
                        solve = false;
                        break;
                    } else {
                        counter[i][pointer]++;
                    }
                }
            }
        }
        // print_vector(sequence);
        // FOR(i, 0, n) print_array(counter[i], 0, nchar);

        FOR(i, 0, n) FOR(j, 0, nchar) if(counter[i][j] == 0){
            solve = false;
            break;
        }
        if(!solve){
            printf("Case #%d: Fegla Won\n", cse++);
        } else {
            int ans = 0;
            FOR(i, 0, nchar){
                int best = INF;
                FOR(j, 0, n){
                    int curres = 0;
                    int curr = counter[j][i];
                    FOR(k, 0, n){
                        curres += abs(curr - counter[k][i]);
                    }
                    best = min(best, curres);
                }
                ans += best;
            }
            printf("Case #%d: %d\n", cse++, ans);
        }

        
    }
    return 0;
}

void print_array(int* array, int start, int end){
  printf("[");
  FOR(i, start, end){
    printf("%d ", array[i]);
  }
  printf("]");
  printf("\n");
}

void print_vector(vector<char> v){
  printf("[");
  FOR(i, 0, v.size()){
    printf("%c ", v[i]);
  }
  printf("]");
  printf("\n");
}