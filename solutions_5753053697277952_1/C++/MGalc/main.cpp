#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <cstring>
#include <limits>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define lngth(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef vector<vector<char> > vcc;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

int largestt(vi& in) {
    int largest = 0;
    int indx = -1;
    rep(i, in.size()) {
        if (in[i] > largest) {
            largest = in[i];
            indx = i;
        }
    }
    return indx;
}

int N;
int main(int argc, char *args[]) {
    if (argc == 2 && strcmp(args[1], "small") == 0) {
        freopen("small.in","rt",stdin);
        freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("a.txt", "rt", stdin);
    }
    
    cin>>N;
    rep2(nn,1,N+1) {
        printf("Case #%d: ", nn);
        ///////////////////////start//////////////

        int nparties;
        cin >> nparties;
        vi parties(nparties);
        vi test(nparties);
        int total = 0;
        rep(i, nparties) {
            int in;
            cin >> in;
            test[i] = in;
            total += in;
        }

        bool done = false;
        bool first = true;
        while (!done) {
            int largest = largestt(test);
            if (largest == -1)
                break;
            if (!first)
                printf(" ");
            int firstout = largest;
            int secondout = -1;
            test[largest]--;
            total--;
            largest = largestt(test);
            if (largest == -1)
                break;
            if (test[largest] > total / 2) {
                secondout = largest;
                test[largest]--;
                total--;
            }
            char out1 = firstout + 'A';
            string out;
            out += out1;
            if (secondout != -1) {
                out += (char)(secondout + 'A');
            }
            cout << out;
            first = false;
        }
        

        ///////////////////////end////////////////
        cout<<endl;
    }
	
    return 0;
}
