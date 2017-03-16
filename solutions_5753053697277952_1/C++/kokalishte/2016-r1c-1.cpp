//
//  main.cpp
//  codejam
//
//  Created by Todor Lyubomirov Bonchev on 1/1/16.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <limits>

using namespace std;

typedef unsigned long long ull;
const ull BIG = 18446744073709551614ULL;

void solve() {
    int N;
    int A[27];
    int total=0;
    cin>>N;
    for (int i=0;i<N;++i) {
        cin>>A[i];
        total+=A[i];
    }
    vector<string> plan;
    while(total>0) {
        string step;
        for (int i=0;i<N;++i) {
            if (A[i]>0) {
                A[i]--;
                total--;
                step+='A'+i;
                break;
            }
        }
        for (int i=0;i<N;++i) {
            if (A[i]>total/2){
                A[i]--;
                total--;
                step+='A'+i;
                break;
            }
        }
        plan.push_back(step);
    }
    for (int i=0;i<plan.size();++i) {
        if (i) cout << " ";
        cout << plan[i];
    }
    putchar('\n');
}

int main(int argc, const char * argv[]) {
    freopen("/XCodeProjects/codejam/codejam/in.txt", "r", stdin);
    freopen("/XCodeProjects/codejam/codejam/out.txt", "w", stdout);

    int tests;
    scanf("%d", &tests);
    for (int test=1;test<=tests;++test) {
        printf("Case #%d: ", test);
        solve();
    }

    return 0;
}
