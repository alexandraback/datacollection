//==============================================================================
// Round 1A 2015
// Problem B. Haircut
//
//==============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

using sol_type = int;
using ll = long long;

void read_data();
sol_type find_solution();

ll N;
vector<ll> barbers;

int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        read_data();
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << solution << endl;
    }
    return 0;
}

void read_data(){
    int B;
    cin >> B >> N;
    barbers.resize(B);
    for(int i=0; i<B; ++i)
        cin >> barbers[i];
}


sol_type find_solution(){
    auto ext_it = minmax_element(barbers.begin(), barbers.end());
    ll lo = 0;
    ll up = *ext_it.second*N/barbers.size()+1;

    while(lo + 1 < up) {
        auto mid = (lo+up)/2;
        auto served = accumulate(barbers.begin(), barbers.end(), 0ll,
                              [mid](ll x, ll y) {return x + ceil(mid*1.0/y);});
        if(served < N)
            lo = mid;
        else
            up = mid;
    }

    auto qu = N - accumulate(barbers.begin(), barbers.end(), 0ll,
                                [lo](ll x, ll y) {return x + ceil(lo*1.0/y);});

    int pos = 0;
    for(pos=0; ; ++pos) {
        if(lo%barbers[pos] ==0)
            --qu;
        if(qu==0)
            break;
    }

    return pos+1;
}

