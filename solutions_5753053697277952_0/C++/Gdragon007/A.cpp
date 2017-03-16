#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, N, P[30];

void getmax(int &a, int &b) {
    a = 0, b = 1;
    if (P[b] > P[a]) swap(a,b);
    for (int i = 2; i < N; ++ i)
        if (P[i]>P[a]) {
            b = a;
            a = i;
        }
        else if (P[i]>P[b]) {
            b = i;
        }
}

int main() {
    cin>>T;
    for (int ca = 1; ca <= T; ++ ca) {
        cin>>N;
        int sum = 0;
        for (int i = 0; i < N; ++ i)
            cin>>P[i], sum += P[i];
        cout<<"Case #"<<ca<<":";
        int one, sec;
        getmax(one, sec);
        while (P[one] > 0) {
           char out = 'A'+one, out1 = 'A' + sec;
           cout<< " " << out;
           sum -- ;
           P[one] -- ;
           if (P[sec] > 0 && sum != 2)
                cout<< out1, P[sec] -- , sum -- ;
           getmax(one, sec);
        } 
        cout<<endl;
    }
    return 0;
}
