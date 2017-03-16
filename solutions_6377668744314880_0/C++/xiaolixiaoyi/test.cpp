#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int x[3005], y[3005];

int main(){
    int T;cin>>T;
    for (int kk = 1; kk <= T; ++ kk) {
        cout<<"Case #"<<kk<<": "<<endl;
        int N;cin>>N;
        for (int i = 0; i < N; ++ i) {
            cin>>x[i]>>y[i];
        }
        if (N == 1) {
            cout<<0<<endl;
            continue;
        }
        
        for (int i = 0; i < N; ++ i) {
            int min = N + 1;
            for (int  j = 0; j < N; ++ j) {
                if (i == j) {
                    continue;
                }
                int count1 = 0, count2 = 0;
                if (x[i] == x[j]) {
                    for (int k = 0; k < N; ++ k) {
                        if (k == i || k == j) {
                            continue;
                        }
                        if (x[k] > x[i]) {
                            ++ count1;
                        } else if(x[k] < x[i]){
                            ++ count2;
                        }
                    }
                }else{
                    for (int k = 0; k < N; ++ k) {
                        if (k == i || k == j) {
                            continue;
                        }
                        
                        int dest1 = (y[i] - y[j]) * (x[k] - x[i]);
                        int dest2 = (x[i] - x[j]) * (y[k] - y[i]);
                        if (dest1 > dest2) {
                            ++ count1;
                        } else if(dest1 < dest2){
                            ++ count2;
                        }
                    }
                }
                min = min < count1 ? min : count1;
                min = min < count2 ? min : count2;
            }
            cout<<min<<endl;
        }
    }
    return 0;
}