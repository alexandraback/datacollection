#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<cstdint>
#include<algorithm>
using namespace std;


int f() {
    int n;
    cin>>n;
    vector<int> m(n);
    for(int i=0;i<n;i++) cin>>m[i];

    int A = 0, B=0;
    for(int i=1;i<n;i++) {
        A += max(0, m[i-1]-m[i]);

    }
    int drop = 0;
    for(int i=1;i<n;i++) {
        drop = max(drop,m[i-1]-m[i]);
    }
    for(int i=0;i<n-1;i++) {
        B += min(m[i],drop);
    }

    cout<<A<<" "<<B<<endl;
    


}

int main() {
    int T;
    cin>>T;
    for(int i=1;i<=T;i++) {
        cout<<"Case #"<<i<<": ";
        f();
    }
}
