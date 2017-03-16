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
#define FOR(s,t) for(int s = 0;s < t;s++)
#define PI pair<int,int>
typedef long long ll;

using namespace std;
void print(int i) { printf("%d ",i); }
void print(double i) { printf("%f ",i); }
int abs(int a) { return a<0?-a:a;}
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
int cut(string& str,char c)
{
    int toRet = 0;
    for(int i = 0;i < str.size();i++) {
        if(str[i] == c) {
            toRet++;
        }
        else {
            break;
        }
    }
    // cut string
    str = str.substr(toRet,string::npos);
    return toRet;
}
void solve()
{
    // START HERE <-----------------------------------------
    int n =getInt();
    string arr[n];
    FOR(i,n) cin >> arr[i];
    // get the need data
    string charArr = "";
    int cnt[1000] = {0};
    char lastChar = '\0';
    int lastCnt = -1;
    FOR(i,arr[0].size()) {
        if(lastChar == arr[0][i]) cnt[lastCnt]++;
        else {
            charArr.push_back(arr[0][i]);
            lastChar = arr[0][i];
            lastCnt++;
        }
    }
    /// parse to ARRAY
    bool fail = false;
    int ans = 0;
    FOR(i,charArr.size())
    {
        // get every string length of this char
        int cntArr[n];
        int mx = 0;
        FOR(j,n) {
            cntArr[j] = cut(arr[j],charArr[i]);
            if(cntArr[j] == 0) {
                //cout << "FAIL " << i << endl;
                // fail
                fail = true;
                break;
            }
            mx = max(mx,cntArr[j]);
        }
        if(fail) break;
        // get ans from cntArr
        int tAns = 999999999;
        for(int target = 1;target <= mx;target++) {
            int _tAns = 0;
            // make every thing eq to target
            for(int j = 0;j < n;j++) {
                _tAns += abs(cntArr[j]-target);
            }
            tAns = min(_tAns,tAns);
        }
        //cout << "PLUS " << tAns << endl;
        ans += tAns;
    }
    // if still any string left from cut
    for(int i = 0;i < n;i++) {
        if(arr[i].size() > 0) {
            fail = true;
            break;
        }
    }
    if(fail) cout << "Fegla Won" << endl;
    else cout << ans << endl;
    //cout << charArr << endl;
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
