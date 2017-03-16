#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        long long B, N; cin>>B; cin>>N;
        //cout<<B<<" "<<N<<endl;
        int Mk[B];
        for(int i=0;i<B;i++){
            cin>>Mk[i];
        }
        if (N<=B){printf("Case #%d: %d\n", case_id, N); continue;}
        N-=B;
        long long T_min = 0, T_max = 922337203685477580, T_mid;
        long long count;
        while(T_min<T_max-1){
            T_mid = (T_max-T_min)/2+T_min;
            count = 0;
            for(int i=0;i<B;i++){
                count+=T_mid/Mk[i];
            }
            if (count>=N) T_max = T_mid;
            else T_min = T_mid;
        }
//        count = 0;
//        for(int i=0;i<B;i++){
//            count+=(T_min)/Mk[i];
//        }
//        if (count>=N) cout<<"asdkjahsdkasjhd"<<endl;
        
        count = 0;
        for(int i=0;i<B;i++){
            count+=(T_max-1)/Mk[i];
        }
//        cout<<B<<" "<<N<<endl;
//        for(int i=0;i<B;i++) cout<<Mk[i]<<" "; cout<<endl;
//        cout<<count<<endl;
//        cout<<T_min<<" "<<T_max<<endl;
        
        int counter = N-count;
        //cout<<B<<" "<<N<<endl;
        //cout<<counter<<endl;
        //cout<<T_max<<endl;
        //cout<<count<<endl;
        int i;
        for(i=0;i<B;i++){
            if (T_max%Mk[i]==0 && counter==1) break;
            if (T_max%Mk[i]==0) counter--;
        }
        if (i==B) cout<<"Asdasdas"<<endl;
        printf("Case #%d: %d\n", case_id, i+1);
    }
}