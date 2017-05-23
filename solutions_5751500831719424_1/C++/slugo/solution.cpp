#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

#define SORT(x) sort(x.begin(),x.end())
#define REVERSE(x) reverse(x.begin(),x.end())
#define mp(x,y) make_pair(x,y)

using namespace std;

typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VII;

map< pair<int,int> , int> fr;

int main()
{
    ios_base::sync_with_stdio(false);

   freopen("rep.in","r",stdin);
   freopen("rep.out","w",stdout);

    int T;cin>>T;
    int t = 1;

    while(T--){

    fr.clear();

    int N;
    cin>>N;

    vector<string> arr;
    set<string> idss;
    vector<char> lett;
    for(int k=0;k<N;k++){
        string a;cin>>a;set<char> act;
        arr.push_back(a);
        string aaa;
        int id = -1;
        char last = '*';
        for(int i=0;i<a.size();i++){
            if(a[i]!=last){
                id++;
                if(k==0)lett.push_back(last);
                aaa+=a[i];
            }
            fr[ mp(k,id) ]++;
            last = a[i];
        }
    idss.insert(aaa);
    }


    if(idss.size()!=1){
    cout<<"Case #"<<t<<": "<<"Fegla Won"<<endl;
    t++;
    }

    else{

    int res = 0;
    for(int k=0;k<lett.size();k++){
    int mn = 1000000000;
        for(int j=1;j<=100;j++){
        int act = 0;
            for(int i=0;i<N;i++){
                int val = fr[mp(i,k)];
                if( val < j)act+=j-val;
                if( val > j)act+=val-j;
            }
            //cout<<" "<<k+1<<" "<<" "<<j<<" "<<act<<endl;
            mn=min(act,mn);
        }
        res+=mn;
    }

    cout<<"Case #"<<t<<": "<<res<<endl;
    t++;
    }

    }

    return 0;
}
