#include <iostream>
#include <bitset>
#include <sstream>
#include <memory>
#include <limits>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    multimap<int, char> party2count;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        party2count.insert({v, 'A' + i});
    }
    
    while (party2count.size() > 2) {
        multimap<int, char>::iterator it = party2count.end();
        it--;
        
        int val = it->first;
        int party = it->second;
        
        cout << it->second << " ";
        
        party2count.erase(it);
        
        if (val - 1 > 0) {
            party2count.insert({val - 1, party});
        }
    }
    
    int count = party2count.begin()->first;
    
    for (int i = 0; i < count; ++i) {
        map<int, char>::iterator it = party2count.end();
        it--;
        cout << party2count.begin()->second << it->second << " ";
    }
}

int main() {
    std::cout.precision(15);
    std::ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <=t ; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
    
    return 0;
}