#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        int b,n;
        cin>>b;
        cin>>n;
        int *p =new int[b];
        int *q =new int[b];
        for (int k=0;k<b;k++){
            cin>>p[k];
            q[k]=0;
        }
        int j=0;
        int s=0;
        int cur=0;
        while(1){
            int small=q[0];
            for(int k=0;k<b;k++){
                small=min(small,q[k]);
            }
            for(int k=0;k<b;k++){
                q[k]-=small;
                if(q[k]==0){
                    j++;
                    cur=k;
                    q[k]=p[k];
                    if(j>=n)
                        break;         
                }
            }
            if(j>=n)
                break;
        }
        cout<<"Case #"<<i<<": "<<cur+1<<endl;
    }

}
