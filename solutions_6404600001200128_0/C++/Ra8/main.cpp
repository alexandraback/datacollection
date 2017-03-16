#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;
int mush[1010];
int N;
int method1(){
    int tot=0;
    for(int i=1;i<N;i++){
        if(mush[i]<mush[i-1]){
            tot=tot+mush[i-1]-mush[i];
        }
    }
    return tot;
}
ll method2(){
    ll mn=1000000000;
    for(ll mps=0;mps<=10000;mps++){
        ll tot=0;
        for(int i=1;i<N;i++){
            if(mush[i-1]-mps<=mush[i]){
                tot=tot+min(mps,(ll)(mush[i-1]));
            } else {
                tot=tot+1000000000;break;
            }
        }
        mn=min(tot,mn);
    }
    return mn;
}
int main()
{
    freopen("txt.in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> mush[i];
        }
        cout << "Case #" << (t+1) <<": "<< method1() << " " << method2() << endl;
    }
    return 0;
}
