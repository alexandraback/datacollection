#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

class Barber {
public:
    long long finish;
    int id;

};

bool operator< (Barber a, Barber b) {
    if( a.finish == b.finish )
        return a.id > b.id;
    return a.finish > b.finish;
}

priority_queue<Barber, vector<Barber> > barbers;
vector<Barber> vec;

int t[1010];
//int c[1000000010];

void solve() {
    int b, n;
    cin >> b >> n;

    while (!barbers.empty()) {
        barbers.pop();
    }
    vec.clear();

    for (int i=0; i<b; i++) {
        cin >> t[i];
        Barber barber;
        barber.id = i;
        barber.finish = 0;
        barbers.push(barber);
    } 

    int max = 0;
    int i=0;
    vector<int> vec;
    for (; i<n; i++) {
        Barber barber = barbers.top();
        barbers.pop();
        //printf ("        get id %d finish %d\n", barber.id, barber.finish);
        if (barber.id==0 && barber.finish==max && barber.finish>0) {
            break;
        }
        vec.push_back(barber.id);
        barber.finish += t[barber.id];
        if (barber.finish > max) {
            max = barber.finish;
        }
        barbers.push(barber);
        //printf ("        put id %d finish %d\n", barber.id, barber.finish);
    }

    /*
    for (int i=0; i<b; i++) {
        for (int j=0; j<=max/t[i]; j++) {
            if (j*t[i] == max && i>0) {
                continue;
            }
            Barber b;
            b.id = i;
            b.finish = j * t[i];
            vec.push_back(b);
        }
    }
    sort(vec.begin(), vec.end());
    */

    //printf("    max %d\n", max);

    int index = (n-1) % vec.size();
    //printf("    index %d\n", max);
    int ret = vec[index];
    cout << ret+1 << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
