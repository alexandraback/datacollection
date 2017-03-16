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
typedef unsigned long long int ulli;
typedef long long int lli;
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
    int b,n;
    scanf("%d %d",&b,&n);
    int arr[b];
    getArray(arr,b);
    int barberDelay[b];
    for(int i = 0;i < b;i++) barberDelay[i] = 0;
    lli L = 0;
    lli R = ulli(n)*100000;
    //cout << R;
    lli mid = (L+R)/2;
    lli ans = 0;
    lli ansWasCut = 0;
    while(L<=R) {

        /// check mid
        //cout << L << " " <<  R << endl;
        //system("pause");
        ulli wasCut = 0;
        for(int i = 0;i < b;i++) {
            wasCut += (mid/arr[i]) + 1;
        }
        if(wasCut >= n) {
            ans = mid;
            ansWasCut = wasCut;
            R = mid-1;
        }
        else {
            L = mid+1;
        }
        mid = (L+R)/2;
    }
    // reverse ans
    int rAns = 999999999;
    vector<int> rI;
    for(int i = 0;i < b;i++) {
        if(ans%arr[i] < rAns) {
            //cout << "CLEAR WITH " << i << endl;
            rAns = ans%arr[i];
            rI.clear();
            rI.push_back(i+1);
        }
        else if(ans%arr[i] == rAns) {
            rI.push_back(i+1);
        }
    }
    // determine the barber
    ///cout << "ans : " << ans << endl;
    //cout << "wasCut : " << ansWasCut << endl;
    //cout << "rI : ";
    //for(int i = 0;i < rI.size();i++) cout << rI[i] << " ";
    //cout << endl;
    int realAns = rI[n-(ansWasCut-rI.size())-1];
    printf("%d\n",realAns);
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
