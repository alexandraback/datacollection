//==================================================================//
// Name        : flash7even                                         //
// Author      : Tarango Khan                                       //
// Codeforces  : flash_7                                            //
// Topcoder    : flash_7                                            //
// Hackerrank  : flash_7                                            //
// Email       : tarangokhan77@gmail.com                            //
// Facebook    : tarango.khan                                       //
//==================================================================//

//==================================================================//
#include <bits/stdc++.h>                                            //
using namespace std;                                                //
#define read(nm)        freopen(nm, "r", stdin)                     //
#define write(nm)       freopen(nm, "w", stdout)                    //
#define pb              push_back                                   //
#define mp              make_pair                                   //
#define F               first                                       //
#define S               second                                      //
#define eps             1e-9                                        //
#define FABS(x)         ((x)+eps<0?-(x):(x))                        //
#define pf              printf                                      //
#define sf              scanf                                       //
#define pi              acos(-1.0)                                  //
#define SZ(x)           ((int)(x).size())                           //
#define mems(x,v)       memset(x,v,sizeof(x))                       //
#define fills(v,n)      fill(v.begin(), v.end(), n)                 //
#define vsort(v)        sort(v.begin(),v.end())                     //
#define asort(v,n)  	sort(a,a+n)                                 //
#define LL              long long                                   //
#define LLU             long long unsigned int                      //
#define debug1(v1)      cout<<"1@ Debug Val 1 = "<<v1<<endl;        //
#define debug2(v2)      cout<<"   2@ Debug Num 2 = "<<v2<<endl;     //
#define debug3(v3)      cout<<"      3@ Debug Res 3 = "<<v3<<endl;  //
#define UB(v,a)   upper_bound(v.begin(),v.end(),a)-v.begin()        //
#define LB(v,a)   lower_bound(v.begin(),v.end(),a)-v.begin()        //
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)     //
//==================================================================//

//==================================================================//
void make_unique(vector<int> &a){ sort(a.begin(), a.end());         //
     a.erase(unique(a.begin(), a.end()), a.end()); }                //
void printDouble(double f,int p){ cout << fixed;                    //
     cout << setprecision(p) << f <<endl; }                         //
int  Set(int N,int cur){ return N = N | (1<<cur); }                 //
int  Reset(int N,int cur){ return N = N & ~(1<<cur); }              //
bool Check(int N,int cur){ return (bool)(N & (1<<cur)); }           //
LL   GCD(LL a,LL b){ if(b == 0) return a; return GCD(b,a%b);}       //
LL   LCM(LL a,LL b){ return a*b/GCD(a,b);}                          //
LL   POW(LL a,LL p){ LL res = 1,x = a;while(p){if(p&1)              //
     res = (res*x); x = (x*x);p >>= 1;} return res;}                //
//==================================================================//

//==================================================================//
//int knightDir[8][2] = {{-2,1},{-1,2},{1,2},{2,1},                 //
//                      {2,-1},{-1,-2},{1,-2},{-2,-1}};             //
//int dir8[4][2]      = {{-1,0},{0,1},{1,0},{0,-1},                 //
//                      {-1,-1},{1,1},{1,-1},{-1,1}};               //
//int dir4[4][2]      = {{-1,0},{0,1},{1,0},{0,-1}};                //
//==================================================================//
//=======// Done With The Shortcut Stuffs! Now Let's Code! //=======//

#define INF (1<<30)
#define MOD 1000000007

#define Size 1000005

int A[27],total;
int N;

void solve(){
    while(true){
        int mxCnt = 0;
        vector<int> L;
        for(int i = 0;i<N;i++){
            if(A[i] == mxCnt && mxCnt != 0){
                L.push_back(i);
            }else if(A[i]>mxCnt){
                L.clear();
                L.push_back(i);
                mxCnt = A[i];
            }
        }
        if(L.size() == 0) break;
        if(L.size() == 1){
            cout << " ";

            int id = L[0];
            char ch1 = (char)(id + 'A');
            cout << ch1;
            A[id]--;
            total--;
            if(total == 2) continue;
            if(A[id]>0){
                char ch2 = (char)(id + 'A');
                cout << ch2;
                A[id]--;
                total--;
            }
        }else{
            cout << " ";

            int id1 = L[0];
            char ch1 = (char)(id1 + 'A');
            cout << ch1;
            A[id1]--;
            total--;
            if(total == 2) continue;
            int id2 = L[1];
            char ch2 = (char)(id2 + 'A');
            cout << ch2;
            A[id2]--;
            total--;
        }
    }
    cout << endl;
}

int main(){
    read("input.txt");
    write("output_1.txt");
    fast_cin;
    int nCase;
    cin >> nCase;
    for(int cs = 1;cs<=nCase;cs++){
        cin >> N;
        total = 0;
        for(int i = 0;i<N;i++){
            cin >> A[i];
            total += A[i];
        }
        cout << "Case #" << cs << ":";
        solve();
    }
}
