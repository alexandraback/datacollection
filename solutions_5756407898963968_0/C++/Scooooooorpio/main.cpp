#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
using namespace std;




void work();

int main(int argc, char *argv[])
{

#if 1
auto t1 = freopen("1.in","r",stdin);
if (t1== nullptr) {
    cerr <<"no file"<<endl;
    return 0;
}
auto t2 = freopen("output.txt","w",stdout);
#endif



    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cout<<"Case #"<<i+1<<": ";
        work();
        cout<<endl;
    }



}


void work() {
    int row;
    int flag[20];
    fill(flag,flag+20,0);
    cin>>row;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int t;
            cin >>t;
            if (i==row-1) flag[t]++;
        }
    }
    cin>>row;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int t;
            cin >>t;
            if (i==row-1) flag[t]++;
        }
    }
    int re = 0;
    int tot = 0;
    for (int i=0;i<17; i++) {
        if (flag[i]==2) {
            re = i;
            tot++;
        }
    }
    if (tot==0) {
        cout<<"Volunteer cheated!";
    }
    else if (tot>1) {
        cout<<"Bad magician!";
    }
    else cout<<re;
}
