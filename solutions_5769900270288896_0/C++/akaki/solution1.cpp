#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int i,j,k,m[1005],n, cur , test,t, mx, a,d, ii,x,r,c,b;
string str;
int log[100]; 


int main(){
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    cin>>t;
    while(t--){
        test++;
        cin >> a>> b >> c;
        n= a*b;
        
        int ans = 1000000;
        for (int mask = 0;mask<(1<<n);mask++){
            vector <int> coord;
            for (i=0;i<n;i++){
                if (mask&(1<<i)){
                    coord.push_back(i);
                }
            }
            //cout<<mask<<" "<<coord.size()<<"aaaa\n ";
            if (coord.size()==c){
                int cur = 0;
                for (i=0;i<c;i++){
                    int x = coord[i]%b;
                    int y = coord[i]/b;
                    //cout<<x<<" "<<y<<" ";
                    for (j=i+1;j<c;j++){
                        int x1 = coord[j]%b;
                        int y1 = coord[j]/b;
                        if (abs(x-x1)+abs(y-y1)==1){
                            cur++;
                        }
                    }
                }
                //cout<<"\n\n";   
                if (ans>cur) ans = cur; 
            }
        }
        cout<<"Case #"<<test<<": "<<ans<<"\n";      
        
    } 
    return 0;
}
