#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


#define FOR(i,n) for(int i=0; i<n; i++)

void usefile(const string& a){
    if(a!="std" && a!="s"){
        freopen( (a + ".in").c_str(), "r", stdin);
        freopen( (a + ".out").c_str(), "w", stdout);
    }
}

template<typename T>
void print(const vector<T>& vec){
    FOR(i, vec.size()){
        cout << vec[i] << ((i==vec.size()-1)?'\n':' ');
    }
}

template<typename T>
void print(T vec[], int n){
    FOR(i, n){
        cout << vec[i] << ((i==n-1)?'\n':' ');
    }
}

template<typename T>
int input(T vec[]){
    int n;
    cin >> n;
    FOR(i,n) cin >> vec[i];
    return n;
}

template<typename T>
int input(vector<T>& vec){
    int n;
    cin >> n;
    vec.clear(); vec.resize(n);
    FOR(i,n) cin >> vec[i];
    return n;
}


const int MAXN = 2000;

int N, M;
int B;
int barb[MAXN];
void read(){
    cin >> B >> N;
    FOR(i, B) cin >> barb[i];
}

long long calcCust(long long t)
{
    long long n = 0;
    FOR(i,B){
        n += (t+barb[i]-1)/barb[i];
    }
    return n;
}

bool judge(long long t)
{
    return calcCust(t) >= N;
}

int solve(){
    int mx = 0;
    FOR(i, B) mx = max(mx, barb[i]);
    long long rt = N * (long long)mx;
    long long lf = 0;
    while(lf < rt){
        long long mid = lf + (rt - lf) / 2;
        if(judge(mid)) rt = mid;
        else lf = mid + 1;
    }

    //cout << "-- " << lf << endl;
    long long x1 = calcCust(lf-1);
    long long left = N - x1;
    FOR(i,B){
        if(barb[i] == 1 || lf % barb[i] == 1) {
            left--;
            if(left == 0) return i+1;
        }
    }
}

int main()
{
    usefile("B2");

    int T;
    cin >> T;

    FOR(ca, T){
        read();
        cout << "Case #" << ca + 1 << ": " << solve() << endl;
    }
    return 0;
}
