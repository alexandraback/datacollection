/// in the name of ALLAH

///#include <bits\stdc++.h>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <sstream>
#include <string>
#include <fstream>
#include <utility>
#include <cstring>

#define bits(a) __builtin_popcount(a)
#define ll long long
int dx[] = {1 , -1 , 0 , 0 };
int dy[] = {0 ,  0 , 1 , -1};
const int mod = (int)1e9 + 7;
const int oo = 1<<30;
const ll loo = (ll)1<<60;
const double pi = 3.14159265359;
const int N = (int) 1e3 + 5;

using namespace std;

//#define in cin
//#define out cout
pair<int , char> pr[N];
int main() {
    fstream  in("A-large.in" , ios::in);
    fstream out("out.out" , ios::out);
    int t;
    in >> t;
    int n , cnt;
    for(int q = 1; q <= t; q ++){
        in >> n;
        cnt = 0;
        for(int i = 0; i < n; i ++) {
            int a;

            in >> a;
            cnt += a;
            pr[i] = make_pair(a , i + 'A');
        }
        out << "Case #" << q << ": ";;
        while(cnt) {
            sort(pr , pr + n);
            reverse(pr , pr + n);
            if(cnt == 3) {
                out << pr[0].second << ' ';
                pr[0].first --;
                cnt--;
            } else if(cnt == 2) {
                out << pr[0].second << pr[1].second;
                cnt -= 2;
                pr[0].first --;
                pr[1].first --;
            } else {
                out << pr[0].second << pr[1].second << ' ';
                cnt -= 2;
                pr[0].first --;
                pr[1].first --;
            }
        }
        out << endl;
    }
}
