#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <fstream>

using namespace std;

int t,n;
int m[10005];

int main()
{
    int i,j,k,t1,t2,t3,ti,ni,re1,re2,b;
    long long l1,l2,l3,l4;
    ifstream in("B-large.in");
    ofstream out("out_b_large");
    in>>t;
    for (ti = 1; ti != t + 1; ++ti) {
        in>>n>>b;
        for (ni = 0; ni != n; ++ni) {
            in>>m[ni];
        }
        if (n >= b) {
            out<<"Case #"<<ti<<": "<<b<<endl;
            continue;
        }
        l1 = 0;
        l2 = 1000000000;
        l2 *= 100001;
        while (l1 < l2 - 1) {
            l3 = (l1 + l2) / 2;
            l4 = 0;
            for (i = 0;i != n; ++i) {
                l4 += l3 / m[i];
                ++l4;
            }
            if (l4 >= b) {
               l2 = l3;
            } else {
               l1 = l3;
            }
        }
        //cout<<l2<<endl;
        l4 = 0;
        for (i = 0; i != n; ++i) {
            l4 += l1 / m[i];
            ++l4;
        }        
        l4 = b - l4;
        l3 = 0;
        for (i = 0; i != n; ++i) {
            if (l2 % m[i] == 0) {
               ++l3;
               if (l3 == l4) {
                  out<<"Case #"<<ti<<": "<<i+1<<endl;
                  break;
               }
            }
        }
    }
    return 0;
}
