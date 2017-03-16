#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<queue>
#include<algorithm>

int arr[100000];
int cnt[100000];

using namespace std;

int lcm(int a,int b){
    int c = __gcd(a,b);
    return (a/c)*b;
}

int lcm_arr(int arr[] , int n){
    int result = arr[0];
    for(int i=1;i<n;++i){
        result = lcm(result , arr[i]);
    }
    
    return result;
}

int main(){
    
    
    freopen("in.txt", "r", stdin);
    
    
    int T,B,N;
    cin>>T;
    for(int i=0;i<T;++i){
        
        for(int i=0;i<100000;++i)
            cnt[i] = 0;

        
        cout<<"Case #"<<i+1<<": ";
        
        cin>>B>>N;
        for(int j=0;j<B;++j){
            cin>>arr[j];
        }
        
        int period_t = lcm_arr(arr,B);
        int period_p = 0;
        for(int j=0;j<B;++j){
            period_p += period_t/arr[j];
        }

        N = N%period_p;
        if(N == 0)
            N = period_p;
        
        //cout<<period_t<<" "<<period_p<<" "<<N<<endl;
        int consumer = B;
        if(B >= N){
            cout<<N<<endl;
            continue;
        }
            
        int b_num = -1;
        while(true){
            for(int j=0;j<B;++j){
                ++cnt[j];
            }
            
            //cout<<consumer<<" ";
            
            for(int j=0;j<B;++j){
                if(cnt[j] >= arr[j])
                    ++consumer,cnt[j]=0;
                if(consumer >= N){
                    b_num = j;
                    break;
                }
                
            }
            
            if(b_num != -1)
                break;
            
        }
        
        cout<<b_num+1<<endl;
        
        
        
    }
    
        return 0;
}