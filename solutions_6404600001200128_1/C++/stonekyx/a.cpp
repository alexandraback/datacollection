#include <iostream>

using namespace std;

int compute1(int N, int list[])
{
    int ans = 0;
    for(int i=1; i<N; i++) {
        ans += list[i-1]-list[i]>0?list[i-1]-list[i]:0;
    }
    return ans;
}

int compute2(int N, int list[])
{
    int ans = 0;
    int maxdiff = 0;
    for(int i=1; i<N; i++) {
        int diff = list[i-1]-list[i]>0?list[i-1]-list[i]:0;
        if(diff>maxdiff) {
            maxdiff = diff;
        }
    }
    for(int i=0; i<N-1; i++) {
        int eaten = maxdiff;
        if(eaten > list[i]) {
            eaten = list[i];
        }
        ans += eaten;
    }
    return ans;
}

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--,Tcnt++) {
        int N;
        cin>>N;
        int *list = new int[N];
        for(int i=0; i<N; i++) {
            cin>>list[i];
        }
        cout<<"Case #"<<Tcnt<<": "<<compute1(N, list)<<" "<<compute2(N, list)<<endl;
        delete[] list;
    }
    return 0;
}

