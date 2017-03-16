#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int m[10101];

int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        int n;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>m[i];
        }
        int ma=0;
        int s=0;
        for (int i=1;i<n;i++){
            ma=max(ma, m[i-1]-m[i]);
            if (m[i]<m[i-1]){
                s+=m[i-1]-m[i];
            }
        }
        int s2=0;
        for (int i=0;i<n-1;i++){
            s2+=min(m[i], ma);
        }
        cout<<s<<" "<<s2<<endl;
    }
}
