#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <functional>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n))
#define TESTS wez(testow); while(testow--)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define MAX(a,b) ( (a) < (b) ? (b) : (a) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define tr(i,t) for (typeof((t).begin()) i=(t).begin(); i!=(t).end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define REMIN(a,b) (a)=min((a),(b))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define SZ(x) ((int)((x).size()))
#define lastEle(vec) vec[vec.size()-1]
#define pb push_back
#define mp make_pair

//Debug Macros
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)



#define MODN 1000000007

#define PI 3.1415926535897932384626
#define LSOne(S) (S & (-S))
#define MAXN 110
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef long long ll;
multiset<int , greater<int> > s;


// void print(set< ii > &a){
//     cerr<<endl;
//     tr(it,a) {

//         cerr<< it->first <<" "<< it->second <<" ";
//     }
//     cerr<<endl;
// }
int gcd(int a,int b){
    if(a==0) return b;
    else return gcd(b%a,a);
}

int lcm(int a,int b){
    return (a/gcd(a,b) ) * b ;
}

set< ii > mset;
int main(int argc, char const *argv[])
{
    int n,cno=1;
    int m[1010];
    int bn;

   // cerr<<lcm(lcm(2,5),5);
    TESTS{
        mset.clear();
        getII(bn,n);
        F(i,0,bn) getI(m[i]);
        int lcmt = m[0];
        F(i,1,bn){
            lcmt = lcm(lcmt,m[i]);
        }
        cerr<<lcmt<<endl;
        int sett=0;
        F(i,0,bn){
            sett += lcmt/m[i];
        }

        cerr<<sett<<endl;

        F(i,0,bn){
            F(j,0,lcmt/m[i]){
                mset.insert(mp(m[i]*j,i));
            }
        }

        //print(mset);

        int nn = (n)- ( ((n-1)/sett) * sett);

        F(i,0,nn-1){
                mset.erase(mset.begin());
        }

        int ans = mset.begin()->second;
        printf("Case #%d: %d\n", cno++ , ans+1);

    }


    return 0;
}