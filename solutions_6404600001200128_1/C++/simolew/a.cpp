#include<iostream>
#include<vector>
#include<map>
#include<cstdlib>
#include<cstdint>
#include<algorithm>
using namespace std;


int64_t f() {
    int64_t n;
    cin>>n;
    vector<int64_t> m(n);
    for(int64_t i=0;i<n;i++) cin>>m[i];

    int64_t A = 0, B=0;
    for(int64_t i=1;i<n;i++) {
        A += max(0L, m[i-1]-m[i]);

    }
    int64_t drop = 0;
    for(int64_t i=1;i<n;i++) {
        drop = max(drop,m[i-1]-m[i]);
    }
    for(int64_t i=0;i<n-1;i++) {
        B += min(m[i],drop);
    }

    cout<<A<<" "<<B<<endl;
    


}

int main() {
    int64_t T;
    cin>>T;
    for(int64_t i=1;i<=T;i++) {
        cout<<"Case #"<<i<<": ";
        f();
    }
}
