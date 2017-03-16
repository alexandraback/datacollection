#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>

using namespace std;

ofstream fout ("A0.txt");
ifstream fin ("A-small-attempt0.in.txt");

int t, mx, n;
vector<int> v;

int main() {
    
    fin >> t;
    
    for(int z = 0 ; z < t ; z++) {
        int cnt1 = 0, cnt2 = 0;
        v.clear();
        mx = 0;
        fin >> n;
        for(int i = 0 ; i < n ; i++) {
            int k;
            fin >> k;
            v.push_back(k);
        }
        
        for(int i = 0 ; i < n-1 ; i++) {
            if(0 < v[i] - v[i+1]) {
                cnt1 += v[i] - v[i+1];
            }
        }
        
        for(int i = 0 ; i < n-1 ; i++) {
            if(mx < v[i] - v[i+1]) {
                mx = v[i] - v[i+1];
            }
        }
        
        for(int i = 0 ; i < n-1 ; i++) {
            cnt2 += (mx > v[i] ? v[i] : mx);
        }
        
        fout << "Case #" << (z+1) << ": " << cnt1 << " " << cnt2 << endl;
    }
}