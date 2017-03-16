#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<queue>


int arr[10000];

using namespace std;

int main(){
    
    freopen("in.txt", "r", stdin);
    
    int T,N;
    cin>>T;
    for(int i=0;i<T;++i){
        
        cout<<"Case #"<<i+1<<": ";
        
        cin>>N;
        for(int j=0;j<N;++j){
            cin>>arr[j];
        }
        
        int pre = arr[0];
        int sum1 = 0;
        for(int j=1;j<N;++j){
            if(pre > arr[j]){
                sum1 += (pre - arr[j]);
            }
            pre = arr[j];
        }
        
        cout<<sum1<<" ";
        
        pre = arr[0];
        int max = 0;
        for(int j=1;j<N;++j){
            if(pre > arr[j] && pre - arr[j] > max){
                max = pre - arr[j];
            }
            pre = arr[j];
        }
        
        pre = arr[0];
        int sum2 = 0;
        for(int j=0;j<N-1;++j){
            if(arr[j] > max)
                sum2 += max;
            else
                sum2 += arr[j];
        }
        
        
        cout<<sum2<<endl;
        
    }
    
        return 0;
}