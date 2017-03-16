#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
int n , m;
string str;
int T , Tn , arr[500];
int main(){
    //
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        vector < pair < int , int > > v;
        for(int j=0;j<n;j++) cin>>arr[j];
        for(int j=0;j<n;j++)
            v.push_back(P(arr[j] , j));
        vector < string > sol;
        sort(v.begin() , v.end());
        int sz = n;
        while(v[sz-1].first != v[sz-2].first){
            string tt;
            tt.push_back(char('A' + v[sz-1].second));
            v[sz-1].first--;
            sol.push_back(tt);
        }
        for(int j=0;j<sz-2;j++){
            while(v[j].first > 0){
                string tt;
                tt.push_back(char('A' + v[j].second));
                v[j].first --;
                sol.push_back(tt);
            }
        }
        while(v[sz-1].first > 0){
            string tt;
            tt.push_back(char('A' + v[sz-1].second));
            tt.push_back(char('A' + v[sz-2].second));
            v[sz-1].first--; v[sz-2].first--;
            sol.push_back(tt);
            //cout<<"fakss"<<endl;
        }
        int ss = sol.size();

        printf("Case #%d: ",++Tn);
      //  cout<<ss<<endl;
        for(int j=0;j<ss-1;j++){
            cout<<sol[j]<<' ';
        }
        cout<<sol.back()<<' ';
        cout<<endl;
    }
}

