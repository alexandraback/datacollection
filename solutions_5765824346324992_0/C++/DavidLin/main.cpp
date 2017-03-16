#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    //freopen("/Users/linsina/Downloads/A.txt", "r", stdin);
    //freopen("/Users/linsina/Downloads/A-large.in", "r", stdin);
    freopen("/Users/linsina/Downloads/B-small-attempt1.in", "r", stdin);
    freopen("/Users/linsina/Downloads/A.out", "w", stdout);
    
    int n;
    cin >> n;
    for (int k = 0; k < n; k++) {
        int r;
        int b, nth;
        cin >> b >> nth;
        if (b > nth) r = nth;
        else {
            vector<int> m(b);
            double dd = 0;
            for (int i = 0; i < b; i++) {
                cin >> m[i];
                dd += 1 / double(m[i]);
            }
            long long start = long((nth - b) / dd);
            double end = ((nth) / dd) + 1;
            
            for (long long s = start; s < end; s++) {
                r = 0;
                int num = 0;
                int numr = 0;
                
                for (int j = 0; j < b; j++) {
                    if (s % m[j] == 0) numr++;
                    num += (s + m[j] - 1) / m[j];
                }
                if (num + numr >= nth) {
                    for (int j = 0; j < b; j++) {
                        if (s % m[j] == 0) {
                            num++;
                            if (num == nth) {
                                r = j + 1;
                                break;
                            }
                        }

                    }
                    
                }
                if (num == nth) break;
            }
        
        }
        
        cout << "Case #" << k + 1 << ": " << r << endl;
    }
    
    return 0;
}


/*
 
 
 int r1 = 0, r2 = 0;
 int m;
 int ma = 0;
 cin  >> m;
 vector<int> mu(m);
 for (int i = 0; i < m ; i++) {
 cin >> mu[i];
 }
 for (int i = 1; i < m; i++) {
 r1 += max(0, mu[i - 1] - mu[i]);
 ma = max(ma, mu[i - 1] - mu[i]);
 }
 for (int i = 0; i < m - 1; i++) {
 r2 += min(ma, mu[i]);
 }
 */