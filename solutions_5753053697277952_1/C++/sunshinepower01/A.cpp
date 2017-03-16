#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 26 + 1;

int findMax(int* p, int n) {
    int maxV = -1;
    int maxIndex = -1;
    
    for (int i=0;i<n;i++) {
        if (maxV < p[i]) {
            maxV = p[i];
            maxIndex = i;
        }
    }
    
    return maxIndex;
}

bool check(int* p, int n) {
    int maxV = -1;
    int sum = 0;
    
    for (int i=0;i<n;i++) {
        sum += p[i];
        maxV = max(maxV, p[i]);
    }
    
    return maxV * 2 <= sum;
}

int main() {
    int t;
    cin >> t;
    
    for (int x=0;x<t;x++) {
        int n, sum = 0;
        int p[MAX_N];
        
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> p[i];
            sum += p[i];
        }
        
        cout << "Case #" << x+1 << ": ";
        
        for (int i=0;i<sum;i++) {
            int maxIndex = findMax(p, n);
            p[maxIndex]--;
            if (!check(p, n)) {
                int maxIndex2 = findMax(p, n);
                p[maxIndex2]--;
                i++;
                cout << (char)('A' + maxIndex) << (char)('A' + maxIndex2) << " "; 
            } else {
                cout << (char)('A' + maxIndex) << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}