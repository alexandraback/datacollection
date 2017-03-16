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
#define PAIR pair<int,int>
#define PI 3.14159265
typedef long long ll;

using namespace std;

struct point {
    int x;
    int y;
};
struct angle {
    int x;
    int y;
};
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

int quadrant(const angle& a) {
    if(a.x == 0 && a.y == 0) return 0;
    if(a.x <= 0) {
        if(a.y <= 0) return 1;
        else return 4;
    }
    else {
        if(a.y <= 0) return 2;
        else return 3;
    }
}
double aat(int y,int x) {
    double toRet = atan2(y,x);
    if(toRet < 0) toRet += 2*PI;
    return toRet;
}
bool aSort(const angle& a,const angle& b) {
     // <- = 0        ->
     if(a.x == 0 && a.y == 0) return false;
     if(b.x == 0 && b.y == 0) return false;
     return aat(a.y,a.x)<aat(b.y,b.x);
}
angle min(const angle& a,const angle& b) {
    if(aSort(a,b)) return a;
    return b;
}
angle oppo(const angle& a) {
    angle toRet = a;
    toRet.x *= -1;
    toRet.y *= -1;
    return toRet;
}
bool angle_on(const angle& a , const angle& b) {
    return fabs(aat(a.y,a.x)-aat(b.y,b.x)) < 0.000001;
    //if(a.x == b.x && a.y == b.y) return true;
    //return false;
}
bool angle_in(const angle&a , const angle &low,const angle&high) {
    // check by quadrant
    return (aat(a.y,a.x) <= aat(high.y,high.x) && aat(a.y,a.x) >= aat(low.y,low.x));
}
int gcd(int a,int b) {
    if(a>=b) {
        if(a%b==0) return b;
        else return gcd(b,a%b);
    }
    else {
        if(b%a == 0) return a;
        else return gcd(a,b%a);
    }
}
/*angle toLowest(const angle& a) {
    angle toRet = a;
    int gcdd = gcd(a.x,a.y);
    toRet.x /= gcdd;
    toRet.y /= gcdd;
    return toRet;
}*/
void solve()
{
    /// START HERE <-----------------------------------------
    printf("\n");
    int n =getInt();
    point arr[n];
    for(int i = 0;i < n;i++) scanf("%d %d",&arr[i].x,&arr[i].y);
    for(int i = 0;i < n;i++) {
        // all angle around
        int ans = n-1;
        angle ang[n];
        for(int j = 0;j < n;j++) {
            ang[j].x = arr[j].x-arr[i].x;
            ang[j].y = arr[j].y-arr[i].y;
            //printf("%d -> %d = %f\n",i,j,angle[j]);
        }
        sort(ang,&ang[n],aSort);
        /*printf("EDGE LIST : ");
        for(int x = 0; x < n;x++) printf("%.2f ",aat(ang[x].y,ang[x].x));
        printf("\n");*/
        for(int j = 0;j < n;j++) {
            // use this edge
            if(quadrant(ang[j]) == 0) continue;
            angle usedLow = min(ang[j],oppo(ang[j]));
            angle usedHigh = oppo(usedLow);
            /// brute force small
            int onEdge = 0;
            int inEdge = 0;
            //printf("USING EDGE %d\n",j);
            for(int k = 0;k < n;k++) {

                if(quadrant(ang[k]) == 0) continue;
                //ang[k] = toLowest(ang[k]);
                //printf("CHECK EDGE %d ",k);
                if(angle_on(ang[k],usedLow) || angle_on(ang[k],usedHigh)) {
                    //printf("onEdge");
                    onEdge++;
                }
                else if(angle_in(ang[k],usedLow,usedHigh)) {
                    //printf("inEdge");
                    inEdge++;
                }
                //printf("\n");
            }
            //printf("SUMMARY : %d %d\n",onEdge,inEdge);
            ans = min(ans,min(n-1-onEdge-inEdge,inEdge));
            /*double edgeUsed = angle[j];
            if(edgeUsed > 9999) continue;
            if(edgeUsed > PI) edgeUsed -= PI; // lower edge used
            double higherEdge = edgeUsed+PI;
            /// binary search
            int L = 0;
            int R = n-1;
            int mid = (L+R)/2;
            int validLower = -1;
            int validHigher = -1;
            int invalidHigh = -1;
            int invalidLow = -1;
            while(L <= R) {
                if(angle[mid] < edgeUsed) {
                    L = mid+1;
                }
                else {
                    validLower = mid;
                    R = mid-1;
                }
                mid = (L+R)/2;
            }
            L = 0; R = n-1; mid = (L+R)/2;
            while(L <= R) {
                if(angle[mid] > higherEdge) {
                    R = mid-1;
                }
                else {
                    validHigher = mid;
                    L = mid+1;
                }
                mid = (L+R)/2;
            }

            /// inv
            L = 0; R = n-1; mid = (L+R)/2;
            while(L <= R) {
                if(angle[mid] <= edgeUsed) {
                    invalidLow = mid;
                    L = mid+1;
                }
                else {
                    R = mid-1;
                }
                mid = (L+R)/2;
            }
            L = 0; R = n-1; mid = (L+R)/2;
            while(L <= R) {
                if(angle[mid] >= higherEdge) {
                    invalidHigh = mid;
                    R = mid-1;
                }
                else {
                    printf("%f >= %f Wrong !",angle[mid],higherEdge);
                    L = mid+1;
                }
                mid = (L+R)/2;
            }
            if(validLower == -1 || validHigher == -1 || invalidLow == -1 || invalidHigh == -1) {
                ans = 0;
            }
            else {
                ans = min(ans,min(n-((invalidLow+1)+(n-invalidHigh)),n-1-(validHigher-validLower+1)));
            }
            printf("EDGE USE %f - %f = %d-%d , %d-%d\n",edgeUsed,higherEdge,validLower,validHigher,invalidLow,invalidHigh);*/
        }
        printf("%d\n",ans);
    }
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
