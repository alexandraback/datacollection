// Version 2
#define TESTCASE true
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#define FOR(s,t) for(int s = 0;s < t;s++)
#define PI pair<int,int>
typedef long long ll;

using namespace std;
void print(int i) { printf("%d ",i); }
void print(double i) { printf("%lf ",i); }
int getInt() {
    int a;
    scanf("%d",&a);
    return a;
}
double getDouble() {
    double a;
    scanf("%lf",&a);
    return a;
}

void getArray(int *arr,int size) { for(int i = 0;i < size;i++) arr[i] = getInt(); }
void getArray(double *arr,int size) { for(int i = 0;i < size;i++) arr[i] = getDouble(); }

int sortMinToMax(const void* a,const void* b){ return *((int*)a) - *((int*)b); }
int sortMaxToMin(const void* a,const void* b){ return *((int*)b) - *((int*)a); }
void sortArrayUp(int* arr,int n){ qsort(arr,n,sizeof(int),sortMinToMax); } /* Min -> Max */
void sortArrayDown(int* arr,int n){ qsort(arr,n,sizeof(int),sortMaxToMin); } /* Max -> Min */

template<class t>
t* array(int N) { return (t*)calloc(sizeof(t),N); }
void solve()
{
    // START HERE <-----------------------------------------
    int row1 = getInt()-1;
    int arr1[16];
    getArray(arr1,16);
    int row2 = getInt()-1;
    int arr2[16];
    getArray(arr2,16);
    // check
    int ans = -1;
    for(int i = 0;i < 4;i++) {
        // if have this number
        bool have = false;
        for(int j = 0;j < 4;j++) {
            if(arr2[j+row2*4] == arr1[i+row1*4]) {
                have = true;
                break;
            }
        }
        if(have) {
            if(ans == -1) {
                ans = arr1[i+row1*4];
            }
            else {
                ans = 9999999;
            }
        }
    }
    if(ans == -1) printf("Volunteer cheated!");
    else if(ans == 9999999) printf("Bad magician!");
    else printf("%d",ans);
}

int main()
{
    if(TESTCASE) {
        int tt;
        scanf("%d",&tt);
        FOR(t,tt)
        {
            printf("Case #%d: ",t+1);
            solve();
            printf("\n");
        }
    } else {
        solve();
    }
}
