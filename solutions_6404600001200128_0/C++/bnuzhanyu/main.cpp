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
        //cout << vec[i] << ((i==n-1)?'\n':' ');
        cout << vec[i] << endl;
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




const int MAXN = 1010;
int food[MAXN];

int N;

void read(){
    N = input(food);
}


void solve(int &a, int &b){
    a = 0;
    int rate = 0;
    for(int i=0; i<N-1; i++){
        a += ((food[i] > food[i+1]) ? food[i] - food[i+1] : 0);
        rate = max(rate, food[i] - food[i+1]);
    }
    b = 0;
    for(int i=0; i<N-1; i++){
        b += (food[i] - food[i+1] >= rate) ? rate: min(rate, food[i]);
    }
}

int main()
{
    usefile("A");
    int T;
    cin >> T;

    FOR(ca, T){
        read();
        int a,b;
        solve(a, b);
        cout << "Case #" << ca + 1 << ": " << a << " " << b << endl;
    }
    return 0;
}
