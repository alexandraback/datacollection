#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vI;
typedef vector<double> vD;
typedef vector<pair<int, int> > vpI;
typedef vector<string> vS;
typedef pair<int, int> pI;
typedef pair<double, double> pD;
typedef map<int, int> mI;
typedef map<string, int> mSI;
typedef map<int, pair<int, int> > mIP;
typedef map<pair<int, int>, int> mPI;
typedef set<int> sI;
typedef set<pI> sPI;
typedef set<string> sS;
typedef priority_queue<int> Qmax;
typedef priority_queue<int, vector<int>, greater<int> >Qmin;

#define TWO(k)  (1<<(k))
#define LTWO(k) (((LL)(1)<<(k)))
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Ford(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define For0(n) for(int (i)=0;(i)<(n);(i)++)
#define For1(n) for(int (i)=1;(i)<=(n);(i)++)
#define Zero(i) memset((i),0,sizeof((i)))
#define Fu1(i) memset((i),0xff,sizeof((i)))
#define NegOne(i) memset((i),0xff,sizeof((i)))
#define Bit(s,i) (( (s) &(1<<(i)))>0)
#define NP next_permutation

//const double PI = acos(-1.0);
//const double EPS = 1e-9;
//const int ioo = (~0)-(1<<31);
//const LL loo = (~(LL)0)-((LL)1<<63);
//const int MOD = 1000000007;
//const LL MODL = 1000000007;;

int Scan()     //输入外挂
{
  int res=0,ch,flag=0;
  if((ch=getchar())=='-')
      flag=1;
  else if(ch>='0'&&ch<='9')
      res=ch-'0';
  while((ch=getchar())>='0'&&ch<='9')
      res=res*10+ch-'0';
  return flag?-res:res;
}

void Out(int a)    //输出外挂
{
  if(a>9)
      Out(a/10);
  putchar(a%10+'0');
}

int r, c, n;
int bitnum[100005];
const int di[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int bit_num(int x)
{
    int ans = 0;
    while(x > 0){
        x -= x & (-x);
        ans++;
    }
    return ans;
}

void init_bitnum()
{
    for(int i = 1; i <= 100000; i++) bitnum[i] = bit_num(i);
}

int main()
{
    freopen("out.txt","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    int t, test = 0;
    cin>>t; 
    init_bitnum();
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        cin>>r>>c>>n;
        int mask = 1<<(r*c);
        int ans = 10*r*c;
        if(n == 0) ans = 0;
        int flag[20][20];
        for(int i = 1; i < mask; i++){
            if(bitnum[i] == n){
                memset(flag, 0, sizeof(flag));
                for(int j = 0; j < r*c; j++){
                    if((1<<j)&i){
                        flag[j/c][j%c] = 1;
                    }
                }
                int n1 = 0;
                for(int j = 0; j < 20; j++){
                    for(int k = 0; k < 20; k++){
                        if(flag[j][k]){
                            for(int t = 0; t < 4; t++){
                                int dx = j+di[t][0], dy = k+di[t][1];
                                if(dx >= 0 && dx < 20 && dy >= 0 && dy < 20 && flag[dx][dy]) n1++;
                            }
                        }
                    }
                }
                ans = min(ans, n1/2);
            }
        }
        cout<<ans<<endl;
    }
    return(0);
}

