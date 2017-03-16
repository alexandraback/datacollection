#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printResult(int cases, int result){
    cout<<"Case #"<<cases<<": "<<result<<endl;
}

int a[1005];


bool myfunction(pair<int, int> a, pair<int, int> b){
    if (a.second < b.second) {
        return true;
    } else if (a.second > b.second){
        return false;
    }
    
    return a.first < b.first;
}
int gcd(int x, int y){
    if (x < y) {
        return gcd(y, x);
    }
    
    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

int lcm(int x, int y){
    int tmpGcd = gcd(x,y);
    return tmpGcd * (x / tmpGcd) * (y / tmpGcd);
}

int main(){
    int T;cin>>T;
    for (int kk = 1; kk <= T; ++ kk) {
        int B,N;cin>>B>>N;
        for (int i = 0; i < B; ++ i) {
            cin>>a[i];
        }
        
        int tmpLcm = 1;//time
        int tmpGcd = a[0];//time
        int cycle = 0;//people
        vector<pair<int, int> > vec;
        for (int i = 0; i < B; ++ i) {
            tmpLcm = lcm(tmpLcm, a[i]);
        }
        for (int i = 0; i < B; ++ i) {
            cycle += tmpLcm / a[i];
            for (int j = 0; j < tmpLcm / a[i]; ++ j) {
                pair<int, int> t(i + 1, j * a[i]);
                vec.push_back(t);
            }
        }
        sort(vec.begin(), vec.end(), myfunction);
        
        int index = (N + cycle - 1) % cycle;
        
        printResult(kk, vec[index].first);
    }
    return 0;
}