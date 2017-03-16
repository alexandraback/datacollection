#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>
#include <iomanip>
using namespace std;

int party[26];
int sum;
int T, N, t;

int largest_party_index(){
    int idx=0, maxp=0;
    for(int i=0;i<N;i++){
        if(party[i]>maxp){
            maxp = party[i];
            idx = i;
        }
    }
    party[idx]--;
    sum--;
    return idx;
}

int main() {
    
    freopen("D:\\Desktop\\A-large.in","r",stdin);
    freopen("D:\\Desktop\\test.out","w",stdout);
    cin>>T;
    for(int j=1; j<=T; j++){
        sum = 0;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>party[i];
            sum += party[i];
        }
        cout<<"Case #"<<j<<": ";
        while(sum>3){
            
            t = largest_party_index();
            cout<<(char)('A'+t);            
            t = largest_party_index();
            cout<<(char)('A'+ t)<<" ";            
        }
        if(sum==3){
            t = largest_party_index();
            cout<<(char)('A'+t)<<" ";            
        }        
        t = largest_party_index();
        cout<<(char)('A'+t);
        t = largest_party_index();
        cout<<(char)('A'+t)<<endl;
    }
    return 0;
}
