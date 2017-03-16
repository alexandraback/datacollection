#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

#define For(i,a,b) for(int i = a; i < b; i++)
#define rep(i,x) For(i,0,x)
#define foreach(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define TWO(x) (1LL<<(x))

using namespace std;

void count(int& n, int& score, int avail, int penalty)  {
    int x = std::min(n, avail);
    n -= x;
    score += x*penalty;
}

int doit(int freewall, int cornerwall, int badwall, int freecenter, int badcenter, int n, int tot) {

    std::cerr << freewall << " " << cornerwall << " " << badwall << " " << freecenter << " " << badcenter << std::endl;
    assert(freewall + cornerwall + badwall + freecenter + badcenter == tot);

    int score=0;
    count(n,score,freewall, 0);
    count(n,score,freecenter, 0);
    count(n,score,cornerwall, 2);
    count(n,score,badwall, 3);
    count(n,score,badcenter, 4);

    std::cerr << score << std::endl;
    
    return score;
}

int doline(int free, int extra, int bad, int n, int tot) {
    std::cerr << free << " " << extra << " " << bad << std::endl;
    assert(free + extra + bad == tot);
    
    int score = 0;
    count(n, score, free, 0);
    count(n, score, extra, 1);
    count(n, score, bad, 2);
    std::cerr << score << std::endl;
    return score;
}

int main() {
int nprob; cin >> nprob;
rep(tprob, nprob) {
    int r, c, n; cin>>r>>c>>n;

    std::cerr << "working on: " << r << " " << c << std::endl;

    int score;
    if(r == 1 || c == 1) {
        int dim = std::max(c,r);

        bool even = (dim % 2) == 0;

        int free = (dim + 1) / 2;
        int extra = even ? 1 : 0;
        int bad = dim - free - extra;

        score = doline(free, extra, bad, n, r*c);
    } else {
        bool reven = (r % 2) == 0;
        bool ceven = (c % 2) == 0;
        bool wierd = !reven && !ceven;

        int wall = 2*r + 2*c - 4;
        int center = std::max(0, (r-2)*(c-2));

        int freewall = wall/2;
        int cornerwall = wierd ? 0 : 2;
        int badwall = wall/2 - cornerwall;

        int freecenter = (center + 1) / 2;
        int badcenter = center - freecenter;

        score = doit(freewall, cornerwall, badwall, freecenter, badcenter, n, r*c);

        if(wierd) {
            cornerwall = 4;
            badwall = wall/2 - cornerwall;
            freecenter = (center) / 2;
            badcenter = center - freecenter;
            score = std::min(score, doit(freewall, cornerwall, badwall, freecenter, badcenter, n, r*c));
        }
    }
    

    cout << "Case #" << (tprob + 1) << ": " << score << std::endl;
} 
}
