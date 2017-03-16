#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll long long

using namespace std;

struct dat{
    int ind,val;
};

bool myfunc(struct dat a, struct dat b) {
    return a.val < b.val;


}

char intToLetter(int v) {
    return v+'A';
}

int main() {
    freopen("f1.in","r",stdin);
    freopen("f1.out","w",stdout);
    int T;
    cin>>T;
    rep(t,1,T+1) {
        int n;
        cin>>n;
        int total_sum=0;
        struct dat arr[n];
        rep(i,0,n) {
            cin>>arr[i].val;
            arr[i].ind = i;
            total_sum+=arr[i].val;
        }
        sort(arr,arr+n,myfunc);

        //rep(i,0,n) {
  //          cout<<arr[i].val<<' '<<arr[i].ind<<endl;
   //     }
       // cout<<"-----------------------------------"<<endl;
        cout<<"Case #"<<t<<": ";

        int final_sum=total_sum;
        while(total_sum>0) {
            sort(arr,arr+n,myfunc);

            if(arr[n-1].val+arr[n-2].val == total_sum) {
                cout<<intToLetter(arr[n-2].ind)<<intToLetter(arr[n-1].ind)<<' ';
                total_sum-=2;
                arr[n-1].val--;
                arr[n-1].val--;
            }
            else {
                cout<<intToLetter(arr[n-1].ind)<<' ';
                total_sum--;
                arr[n-1].val--;
            }

        }
        cout<<endl;
    }

}
