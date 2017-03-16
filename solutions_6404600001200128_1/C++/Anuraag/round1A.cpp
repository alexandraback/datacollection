#include<iostream>
#include<cstdio>

using namespace std;

int T;
int N;
int arr[1001];

#define LARGE

int main(){
    freopen("a.txt","rt",stdin);
    #ifdef LARGE
         freopen("A-large.in","rt",stdin);
         freopen("outAlarge.out","wt",stdout);
    #endif

    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<": ";
        cin>>N;
        int max=0,min=0;
        for(int j=0;j<N;j++){
            cin>>arr[j];
            if(j>=1){
                if(max< arr[j-1]-arr[j]){
                    max = arr[j-1]-arr[j];
                }
                if(arr[j]<arr[j-1]){
                    min = min+ arr[j-1]-arr[j];
                }
            }
        }
        cout<<min<<" ";
        min=0;
        for(int i=0;i<N-1;i++){
            if(max<arr[i]){
                min += max;
            }else{
                min += arr[i];
            }
        }
        cout<<min<<"\n";
    }
}
