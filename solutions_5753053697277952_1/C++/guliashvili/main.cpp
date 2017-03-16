#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include<cassert>
using namespace std;

void check(set<pair<int,char> > ss){

    int sum = 0;
    int mx = 0;
    char name;
    for(pair<int,char> a : ss){
        sum += -a.first;
        if(-a.first > mx){
            mx = -a.first;
            name = a.second;
        }
    }
    if(2*mx > sum){
        cout<<"ERROR"<<endl;
        cout<<sum<<endl<<mx<<endl<<name<<endl;
        exit(0);

    }

}

void solve(){
    int n;cin>>n;
    set<pair<int,char> > ss;

    for(int a = 'A'; a < 'A' + n; a++){
        int x;cin>>x;
        ss.insert(make_pair(-x, (char)a));
    }
    while(ss.size() > 1){
        check(ss);
        pair<int,char> p1 = *ss.begin();
        ss.erase(ss.begin());
        pair<int,char> p2 = *ss.begin();
        ss.erase(ss.begin());

        if(!(ss.size()==0 && p1.first == p2.first)){
            cout<<p1.second<<' ';
            p1.first += 1;
        }else{
            cout<<p1.second<<p2.second<<' ';
            p1.first++;
            p2.first++;
        }

        if(p1.first != 0) ss.insert(p1);
        if(p2.first != 0) ss.insert(p2);
        //fflush(stdout);
    }
    assert(ss.size() == 0);


}

int main(){
    freopen("/Users/gguliash/ClionProjects/untitled1/a.txt", "r", stdin);
    freopen("/Users/gguliash/ClionProjects/untitled1/w.txt", "w", stdout);

    int t;cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<endl;
    }


    return 0;
}
