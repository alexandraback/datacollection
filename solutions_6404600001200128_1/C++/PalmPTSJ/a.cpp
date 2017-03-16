// Version 2.1
#define TESTCASE true
#define DEBUG false

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>
#define FOR(s,t) for(int s = 0;s < t;s++)
#define PI pair<int,int>
typedef long long ll;

using namespace std;
void print(int i) { printf("%d ",i); }
void print(double i) { printf("%f ",i); }
int getInt() {
    int a;
    scanf("%d",&a);
    return a;
}
void getInt(int& a) {
    scanf("%d",&a);
}
double getDouble() {
    double a;
    scanf("%lf",&a);
    return a;
}
void getDouble(double& a) {
    scanf("%lf",&a);
}
void getArray(int *arr,int size) { for(int i = 0;i < size;i++) getInt(arr[i]); }
void getArray(int **arr,int N,int M) { for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) getInt(arr[i][j]);}
void getArray(double *arr,int size) { for(int i = 0;i < size;i++) getDouble(arr[i]); }
void getArray(double **arr,int N,int M) { for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) getDouble(arr[i][j]); }

vector<int> getVector(int size) { vector<int> toRet(size); for(int i = 0;i < size;i++) toRet[i] = getInt(); return toRet; }

template<class t> bool sortMaxToMin(const t&a,const t&b) { return a>b; }

template<class t> void sortUp(t* arr,int n) { sort(arr,&arr[n]); }
template<class t> void sortDown(t* arr,int n) { sort(arr,&arr[n],sortMaxToMin<t>); }

template<class t> t* array(int N) { return (t*)calloc(sizeof(t),N); }
template<class t> t** array(int N,int M) {
    t** toRet = (t**)calloc(sizeof(t*),N);
    for(int i = 0;i < N;i++) toRet[i] = (t*)calloc(sizeof(t),M);
    return toRet;
}
template<class t> void freeMatr(t** matr,int N,int M) {
    for(int i = 0;i < N;i++) free(matr[i]);
    free(matr);
}

void printArray(int* arr,int n) { for(int i = 0;i < n;i++) printf("%d ",arr[i]);}
void printVector(vector<int> &V) { for(int i = 0;i < V.size();i++) printf("%d ",V[i]); }
bool same(const string& a,const string& b) { return a.compare(b)==0;}

template<class t>
vector<t> subvector(vector<t> V,int st,int len) {
    return vector<t>(V.begin()+st,V.begin()+st+len);
}

void solve()
{
    /// START HERE <-----------------------------------------
    int n = getInt();
    int arr[n];
    getArray(arr,n);
    int f,s;
    f = s = 0;
    for(int i = 1;i < n;i++) {
        // first method
        if(arr[i] < arr[i-1]) {
            f += arr[i-1]-arr[i]; /// sum of all drop
        }
    }
    // find biggest drop
    int biggestDrop = 0;
    for(int i = 1;i < n;i++) {
        if(arr[i-1]-arr[i] > biggestDrop) biggestDrop = arr[i-1]-arr[i];
    }
    /// calc 2nd method
    int mush = arr[0];
    for(int i = 1;i < n;i++) {
        s += mush - max(mush-biggestDrop,0);
        mush -= biggestDrop;
        if(mush < 0) mush = 0;
        if(arr[i] > mush) {
            mush = arr[i];
        }
    }
    printf("%d %d\n",f,s);
}

int main()
{
    if(TESTCASE) {
        int t,tt;
        scanf("%d",&tt);
        for(t=0;t < tt;t++)
        {
            printf("Case #%d: ",t+1);
            solve();
        }
    } else {
        solve();
    }
}
