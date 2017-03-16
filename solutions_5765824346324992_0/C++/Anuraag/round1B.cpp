#include<iostream>
#include<cstdio>

using namespace std;

int T;
int B;
long N;
long arr[1001],arr3[1001];
int arr2[1001];

int main(){
    freopen("B-small-attempt.in","rt",stdin);
    freopen("Bout.out","wt",stdout);
   cin>>T;
   for(int i=1;i<=T;i++){
       cout<<"Case #"<<i<<": ";
       cin>>B;
       //int *arr = new int[B];
       //int *arr2 = new int[B];
       //int *arr3 = new int[B];
       cin>>N;
       int mins;
       int counts=0;
       long mul=1;
       for(int j=0;j<B;j++){
           cin>>arr[j];
           arr2[j]=counts=j+1;
           arr3[j]=arr[j];
           //int temp=mul%arr[j];
           //if(temp!=0){
                //for(int s=2;s<=arr[j];s++){
                    //if((temp*s)%arr[j]==0){
                      //  mul *=s;
                    //}


                //}

           //}
           mul*=arr[j];
           if(j==0){
              mins = arr[0];
           }else{
               if(mins>arr[j]){
                   mins = arr[j];
               }
           }
       }
       int tot=0;
       for(int j=0;j<B;j++){
           tot += mul/arr[j];
       }
       int getcountss = (N-B)/tot;
       getcountss = getcountss*tot;
       int remain = N-getcountss;

       int nmins;
       while(true){
            if(counts>=remain){
                break;
            }
            for(int j=0;j<B;j++){
                arr3[j]=arr3[j]-mins;
                if(arr3[j]<=0){
                    arr2[j]=counts+1;
                    counts++;
                    arr3[j]=arr3[j]+arr[j];
                }
                if(j==0){
                    nmins=arr3[j];
                }else{
                    if(nmins>arr3[j]){
                        nmins = arr3[j];
                    }
                }
            }
            mins=nmins;

       }

       int ans = 0;
       for(int k=0;k<B;k++){
            if(remain==arr2[k]){
                ans=k+1;
                break;
            }
       }
       cout<<ans<<"\n";
   }



}
