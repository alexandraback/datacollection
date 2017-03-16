#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;

int di[4] = {0,1,0,-1};
int dj[4] = {1,0,-1,0};

int main()
{
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++)
    {
        int r, c, n;
        cin >> r >> c >> n;
//         VI v (r * c,0);
//         fi (n) v[i] = 1;
//         sort(v.begin(),v.end());
//         int ans = r * c * 20;
//         do
//         {
//             VVI mat (r, VI (c));
//             fi (r * c)
//             {
//                 mat[i/c][i%c] = v[i];
//             }
//             int sm = 0;
//             fi (r)
//             {
//                 fj(c)
//                 {
//                     if (not mat[i][j]) continue;
//                     fk(4)
//                     {
//                         int ni = i + di[k];
//                         int nj = j + dj[k];
//                         if (ni < 0 or ni >= r or nj < 0 or nj >= c)
//                             continue;
//                         sm += mat[ni][nj];
//                     }
//                 }
//             }
//             ans = min (ans, sm);
//         }while (next_permutation(v.begin(),v.end()));
        if (n * 2 <= r * c)
        {
            cout << "Case #" << caso << ": " << 0  << endl;
            continue;
        }
        ll ans = c * r * 20;
        for (int color = 0; color < 2; color++)
        {
            VI val;
            int qd = n;
            fi (r)
            {
                fj (c)
                {
                    if ((i+j) % 2 != color) qd --;
                    else
                    {
                        int ld = 4;
                        if (i == 0) ld --;
                        if (i == r-1) ld --;
                        if (j == 0) ld --;
                        if (j == c-1) ld --;
                        val.push_back(ld);
                    }
                }
            }
            sort(val.begin(),val.end());
            ll sm = 0;
            fi(qd) sm += val[i];
            ans = min(ans, sm);
        }
        cout << "Case #" << caso << ": " << ans << endl;
    }
}