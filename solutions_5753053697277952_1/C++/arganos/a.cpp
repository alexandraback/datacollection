#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int t;


int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #"<<i<<":";
        int  n;
        pair<int, char> p[30];
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> p[i].first;
            p[i].second = 'A'+i;
        }

        sort(p, p+n,std::greater<pair<int, char> >() );

        while (p[0].first > 0) {
            if (n > 2 && p[0].first == 1 && p[1].first == 1 && p[2].first == 1) {
                 cout <<" "<<p[0].second ;
                p[0].first--;
            } else if (p[1].first > 0) {
                cout <<" "<<p[0].second <<p[1].second;
                p[0].first--;
                p[1].first--;
            }else{
                cout <<" "<<p[0].second ;
                p[0].first--;
            }
            
            sort(p, p+n,std::greater<pair<int, char> >() );
        }

        
    
        cout << endl;
    }

    return 0;
}
