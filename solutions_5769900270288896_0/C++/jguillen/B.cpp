#include <iostream>
#include <cmath>
#include <cstring>
#define MAX_N 17
#define INF 1000000000

using namespace std;

int count_on_bits(int n,int bits){
    int ans = 0;
    for(int i=0;i<bits;i++)
        ans+= (n&(1<<i))?1:0;
    return ans;
}

bool is_on(int cad,int i){
    return cad&(1<<i);
}

int count_happiness(int cad,int bits,int C){
    int ans = 0;
    int c0,c1,r0,r1;
    for(int i=0;i<bits;i++){
        if(!is_on(cad,i)) continue;
        for(int j=i+1;j<bits;j++){
            if(!is_on(cad,j)) continue;
            //cout<<"pair: "<<i<<" "<<j<<endl;
            r0 = i/C;
            c0 = i%C;
            
            r1 = j/C;
            c1 = j%C;
            if(abs(r0-r1)+abs(c0-c1)==1) ans++;
        }
    }
    return ans;
}

int main(){
    int T, R,C,N, counter = 1;;
    cin>>T;
    while(T--){
        cin>>R>>C>>N;
        cout<<"Case #"<<counter++<<": ";
        if(N==0){
            cout<<0<<endl;
        } else {
            int bits = R*C;
            int tope = (1<<bits);
            int ans = INF;

            for(int i=0;i<tope;i++){
                //we need i with bits 1's
    
                if(count_on_bits(i,bits)==N){   
                    //cout<<"cad "<<i<<endl;
                    ans = min(ans, count_happiness(i, bits,C));
                }
            }
            cout<<ans<<endl;
        }
    }
    return  0;
}
