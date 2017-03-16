#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main(){
    freopen("A.in","r",stdin);
    freopen("output.txt","w",stdout);
    int TC;
    cin>>TC;
    for(int ZZ=1;ZZ<=TC;ZZ++){
        int n,a1=0,a2=0;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        int max1 = 0;
        for(int i=1;i<n;i++){
            max1 = max(max1,ar[i-1]-ar[i]);
        }
        if(max1<=0){
            a1 = 0;
            a2 = 0;
        }else{
            for(int i=1;i<n;i++){
                int x = ar[i-1] - ar[i];
                if(x>0)
                    a1+=x;

                int y= min(ar[i-1],max1);
                a2+=y;
            }
        }

        cout<<"Case #"<<ZZ<<": "<<a1<<" "<<a2<<endl;
    }
    return 0;
}
