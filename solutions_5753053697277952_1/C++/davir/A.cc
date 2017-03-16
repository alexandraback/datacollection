#include <iostream>

using namespace std;

void solve()
{
    unsigned int S[32];
    unsigned int n;
    cin >> n;
    unsigned int count = 0;
    for(auto i = 0u; i < n; i++) {
        cin >> S[i];
        count += S[i];
    }
    while(count) {
        unsigned int max = 0;
        unsigned int jmax = 0;
        for(auto j = 0u; j < n; j++) {
            if(S[j] > max) {
                max = S[j];
                jmax = j;
            }
        }
        if((max == 1) and (count > 2)) {
            for(auto j = 0u; j < n; j++) {
                if(S[j] == max) {
                    cout << ' ' << char('A' + jmax);
                    S[jmax]--;
                    count--;
                    break;
                }
            }
        } else {
            bool done = false;
            for(auto j = 0u; j < n; j++) {
                if((S[j] == max) and (j != jmax)) {
                    cout << ' ' << char('A' + jmax);
                    cout << char('A' + j);
                    S[jmax]--;
                    S[j]--;
                    count -= 2;
                    done = true;
                    break;
                }
            }
            if(!done) {
                cout << ' ' << char('A' + jmax);
                S[jmax]--;
                count--;
            }
        }
    }
}

int main()
{
    unsigned int cases;
    cin >> cases;
    for(auto i = 1u; i <= cases; i++) {
        cout << "Case #" << i << ":";
        solve();
        cout << endl;
    }
    return 0;
}
