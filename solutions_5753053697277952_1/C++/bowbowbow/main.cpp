#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
#define FOR(i,n) for(int i=1;i<=n;i++)

string ans;
int N;
vector<pair<int, int> > list;


bool isOk(vector<pair<int, int> > arr){
    double sum = 0;
    int Max = 0;
    for(int i = 0 ; i < N ; i++){
        if(Max < arr[i].first){
            Max = arr[i].first;
        }
    }
    for(int i = 0 ; i < N ; i++){
        sum += arr[i].first;
    }
    if(sum/(double)N < Max)
        return false;
    return true;
}

bool compare(const pair< int, int > i, const pair< int, int> & j){
    return i.first > j.first;
}


int main() {
    freopen("/Users/clsrn1581/Desktop/codejam/A/A-large.in", "r", stdin);
    freopen("/Users/clsrn1581/Desktop/codejam/A/A-large.out", "w", stdout);
    
    int tn; cin >> tn;
    
    FOR(t,tn) {
        ans = "";
        cin >> N;
        list.clear();
        int S = 0;
        FOR(i, N){
            int tmp;
            cin>> tmp;
            S += tmp;
            list.push_back({tmp, i});
        }
        
        FOR(c , S){
            sort(list.begin(), list.end(), compare);
            list[0].first--;
            ans += 'A'+list[0].second-1;
            
            vector<pair<int, int> > ori = list;
            
            sort(list.begin(), list.end(), compare);
            
            list[0].first--;
            
            if(isOk(list)){
                ans += 'A'+list[0].second-1;
                c++;
            }else{
                list = ori;
            }
            ans += " ";
        }
        
        printf("Case #%d: ", t);
        cout << ans << endl;
    }
    return 0;
}
