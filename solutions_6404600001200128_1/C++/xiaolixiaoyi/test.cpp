#include<iostream>
using namespace std;

void printResult(int cases, int result1, int result2){
    cout<<"Case #"<<cases<<": "<<result1<<" "<<result2<<endl;
}

int a[1005];

int main(){
    int T;cin>>T;
    for (int kk = 1; kk <= T; ++ kk) {
        int N;cin>>N;
        for (int i = 0; i < N; ++ i) {
            cin>>a[i];
        }
        
        int y = 0,z = 0;
        int max = a[0] - a[1];
        double rate;
        for (int i = 1; i < N; ++ i) {
            int rest = a[i - 1] - a[i];
            if (rest > 0) {
                y += rest;
            }
            if (max < rest) {
                max = rest;
            }
        }
        if (max <= 0) {
            rate = 0;
        } else {
            rate = max / 10.0;
        }
        double tmp = rate * 10;

        for (int i = 0; i < N - 1; ++ i) {
            int tmp1 = (int)tmp;
            if (tmp > tmp1) {
                tmp1 ++;
            }
            z += tmp1 > a[i] ? a[i] : tmp1;
        }
        printResult(kk, y ,z);
        
    }
    return 0;
}