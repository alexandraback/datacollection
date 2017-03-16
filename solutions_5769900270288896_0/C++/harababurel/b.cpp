#include <iostream>
#define inf (1<<30)
using namespace std;

int t, tests, r, c, n, sol;
bool a[16][16];

int main() {
    cin>>tests;
    for(int t=1; t<=tests; t++) {
        cin>>r>>c>>n;
        sol = inf;

        for(int conf=0; (1<<(r*c)) >= conf; conf++) {

            int bits = 0;
            for(int i=0; i<r*c; i++) {
                if((1<<i) & conf) bits++;
                a[i/c][i%c] = (1<<i) & conf;
            }

            if(bits != n) continue;

            int shared = 0;
            for(int i=0; i<r; i++)
                for(int j=0; j<c-1; j++)
                    if(a[i][j] & a[i][j+1]) shared++;

            for(int i=0; i<r-1; i++)
                for(int j=0; j<c; j++)
                    if(a[i][j] & a[i+1][j]) shared++;

            sol = min(sol, shared);
        }
        cout<<"Case #"<<t<<": "<<sol<<"\n";
    }

    return 0;
}
