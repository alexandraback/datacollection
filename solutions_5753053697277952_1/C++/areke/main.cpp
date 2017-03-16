#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

int main() {
    
    
    ifstream fin ("A-large.in");
    ofstream fout ("output.out");
    
    long long tests;
    fin >> tests;
    for (int test = 0; test < tests; test++) {
        
        long long n;
        fin >> n;
        long long x;
        fout << "Case #" << test+1 << ": ";
        vector<pair<long long, char> > v;
        for (int i = 0; i < n; i++) {
            fin >> x;
            v.push_back(make_pair(x, 'A'+i));
        }
        sort(v.begin(), v.end());
        while (v[n-1].first != v[n-2].first) {
            fout << v[n-1].second << " ";
            v[n-1].first--;
        }
        for (int i = 0; i < n-2; i++) {
            while (v[i].first > 0) {
                fout << v[i].second << " ";
                v[i].first--;
            }
        }
        while (v[n-1].first > 0) {
            fout << v[n-1].second << v[n-2].second;
            v[n-1].first--;
            if (v[n-1].first == 0) fout << endl;
            else fout << " ";
            
        }
        

        
        
        
        
        
    }
    
}