#include<iostream>
using namespace std;

int A[10000+7];

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;

    for(int tt = 1; tt<=T; tt++) {
        int n;
        cin>>n;

        int a = 0, b = 0, x = 0;
        cin>>A[1];
        for(int i = 2; i<=n; i++)
        {
            cin>>A[i];
            int d = A[i-1] - A[i];
            if(A[i] < A[i-1])
            {
                a += d;
                x = max(x, d);
            }
        }
        for(int i = 1; i<n; i++)
        {
            b += min(A[i], x);
        }

    cout<<"Case #"<<tt<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}
