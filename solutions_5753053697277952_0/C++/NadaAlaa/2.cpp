#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <unordered_map>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("outJAM1.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        int n,arr[2000],count[27]={0},sum=0;
        cin>>n;
        for(int i=0; i<n; i++) cin>>arr[i],count[i]+=arr[i],sum+=arr[i];
        priority_queue<pair<int,char> > qee;
        for(int i=0; i<n; i++) qee.push({count[i],char(i+'A')});
        cout<<"Case #"<<tc<<":";
        if(sum%2) {
            pair<int,char> p1=qee.top();
            qee.pop();
            cout<<" "<<p1.second;
            p1.first--;
            if(p1.first) qee.push(p1);
        }
        while(qee.size()){
            pair<int,char> p1=qee.top();
            qee.pop();
            if(qee.size()){
                pair<int,char> p2=qee.top();
                qee.pop();
                cout<<" "<<p1.second<<p2.second;
                p1.first--;
                p2.first--;
                if(p1.first) qee.push(p1);
                if(p2.first) qee.push(p2);
            }
            else{
                cout<<" "<<p1.second;
                p1.first--;
                if(p1.first){
                    cout<<p1.second;
                    p1.first--;
                    if(p1.first) qee.push(p1);
                }
            }
        }
        cout<<endl;
    }
}