#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <bitset>
#include <vector>
#include <set>

using namespace std;
#define pb push_back
#define ll long long
const int maxn = 210;
struct Node{
    string str;
    vector<int> cont;
    Node(){str=""; cont.clear();}
}v[maxn];
int n;
string tmp;

int solve(){
    int len = v[0].str.size();
    int res = 0;
    for(int i = 0; i < len; ++i){
        int sum = 0;
        vector<int> occur;
        for(int j = 0; j < n; ++j)
            occur.pb( v[j].cont[i] );
        sort(occur.begin(), occur.end() );
        for(int be = 0, ed = n - 1; be <= ed; be++, ed--){
            sum += occur[ed] - occur[be];
        }
        res += sum;
    }
    return res;
}

bool legal(){
    for(int i = 1; i < n; ++i)
        if( v[i].str != v[0].str )
            return false;
    return true;
}
int main(){
//    freopen("in.txt", "r", stdin );
//    freopen("A0.in", "r", stdin );
//    freopen("A0.out", "w", stdout );
    freopen("A1.in", "r", stdin );
    freopen("A1.out", "w", stdout );
    int tcase;
    cin>>tcase;
    int tno = 0;
    while( tcase-- ){
        cin>>n;
        for(int i = 0; i < n; ++i){
            cin>>tmp;
            Node node;
            node.str = tmp[0];  node.cont.pb( 1 );
            for(int j = 1; j < tmp.size(); ++j){
                if( tmp[j] == node.str[ node.str.size() - 1] ){
                    node.cont[ node.cont.size() - 1]++;
                }else{
                    node.cont.pb( 1 );
                    node.str.append(1, tmp[j] );
                }
            }
            v[i] = node;
        }
        if( legal() ){
            int res = solve();
            printf("Case #%d: %d\n", ++tno, res);
        }else
            printf("Case #%d: Fegla Won\n", ++tno);

    }
    return 0;
}
