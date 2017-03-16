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
    int i,j,k,t1,t2,t3,ti,ni,re1,re2;
    ifstream in("A-large.in");
    ofstream out("out_large");
    //scanf("%d", &t);
    in>>t;
    for (ti = 1; ti != t + 1; ++ti) {
        //scanf("%d", &n);
        in>>n;
        t1 = 0;
        t2 = 0;
        re1 = 0;
        re2 = 0;
        for (ni = 0; ni != n; ++ni) {
            //scanf("%d", &m[ni]);
            in>>m[ni];
            if (ni > 0 && m[ni] < m[ni-1]) {
               re1 += (m[ni-1] - m[ni]);
            }
            if (ni > 0 && m[ni] < m[ni-1] && m[ni-1] - m[ni] > t1) {
               t1 = m[ni-1] - m[ni];
            }
        }
        for (i = 0; i < n - 1; ++i) {
            if (m[i] < t1) {
                re2 += m[i];
            } else {
                re2 += t1;
            }
        }
        //printf("Case #%d: %d %d\n", ti, re1, re2);
        out<<"Case #"<<ti<<": "<<re1<<" "<<re2<<endl;
    }
    return 0;
}
