#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MP(x,y) make_pair(x,y)
#define rl(n) scanf("%ld", &n)
#define rll(n) scanf("%I64d", &n) 
#define M_PII_4 0.785398163397448309616
bool static comparedesc(const long &stud1, const long &stud2){
    return stud1 > stud2;
}



int main(){
    int t ;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        printf("Case #%d: ", _t);
        int n;
        cin >> n;
        vector<int> p(n, 0);
        int tot = 0;
        set<pair<int, int> > sen; 
        set<pair<int, int> > ::iterator it;
        for(int i=0; i<n; i++){
            cin >> p[i];
            tot += p[i];
            sen.insert(MP(p[i], i));
        }
        while(tot && sen.size()){
            it = sen.end();
            it--;
            int a = (*it).second;
            if(it != sen.begin() ){
                it--;
                int b = (*it).second;
                if((sen.size()== 2 && p[a] == 2 && p[b] == 1 )|| 
                    (sen.size() > 2 && p[a] == 1 && p[b] == 1 )){
                    sen.erase(MP(p[a], a));
                    p[a] -= 1;
                    tot--;
                    if(p[a] > 0)
                        sen.insert(MP(p[a], a));
                    cout << (char)('A' + a)  << " ";
                }
                else   {
                    sen.erase(MP(p[a], a));
                    sen.erase(MP(p[b], b));
                    tot -= 2;
                    p[a] -= 1;
                    p[b] -= 1;
                    if(p[a] > 0)
                    sen.insert(MP(p[a], a));
                    if(p[b] > 0)
                    sen.insert(MP(p[b], b));

                    cout << (char)('A' + a) << (char)('A' + b) << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}