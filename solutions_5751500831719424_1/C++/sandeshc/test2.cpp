#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

const double eps=1e-11;
//const double pi=acos(-1.0);
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;


#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
#define lpu(i,s,e) for(i=s;i<e;i++)
#define lpd(i,s,e) for(i=s;i>e;i--)
#define lpui(i,s,e) for(i=s;i<=e;i++)
#define lpdi(i,s,e) for(i=s;i>=e;i--)
#define abs(a) (a<0?-(a):a)
#define nl() cout << '\n'
#define nlf() cout << endl

inline void swap(int& a,int &b){ a^=b; b^=a; a^=b; }
inline lli min(lli& a,lli &b){ if(a<b) { return a; } else return b; }
inline lli max(lli& a,lli &b){ if(a>b) { return a; } else return b; }

# define getcx getchar
ull inp_ull()//fast input function
{
        ull n=0;
        int ch=getcx();
        while( ch < '0' || ch > '9' )
        {ch=getcx();}
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        return n;
}

lli inp_lli()//fast input function
{
        lli n=0;
        int ch=getcx();
        int sign=1;
        while( ch < '0' || ch > '9' )
        {if(ch=='-')sign=-1; ch=getcx();}
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        n=n*sign;
        return n;
}

int inp_int()//fast input function
{
        int n=0;
        int ch=getcx();
        int sign=1;
        while( ch < '0' || ch > '9' )
        {if(ch=='-')sign=-1; ch=getcx();}
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        n=n*sign;
        return n;
}

void output(lli x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[25];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int main()
{  
  #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  int t,tp,n,i,j,l;
  int ans_t,p,q;
  t=inp_int(); tp=0;
  vector<string> v;
  vector<char> base;
  string  s; bool flag;
  int m[110][110];
  int ans;
  int cnt; int pc;
  while(tp<t){
    lpu(i,0,100) lpu(j,0,100) m[i][j]=0;
    n=inp_int();
    v.clear(); base.clear();
    lpu(i,0,n) { cin >> s; v.push_back(s); }
    l=0;
    lpu(i,0,v[0].length()) {

      if(i==0) { pc = v[0][0]; cnt=1; }
      else {
        if(pc==v[0][i]) cnt++;
        else {
          base.push_back(pc);
          m[0][l++] = cnt ;
          pc=v[0][i];
          cnt = 1;
        }
      }

      if((i+1)==v[0].length()) {
        base.push_back(pc);
        m[0][l++] = cnt ;
      }

    }
    int lt; flag = true;
    lpu(i,1,v.size()){
      lt=0;
      lpu(j,0,v[i].length()){
        if(j==0) { pc = v[i][0]; cnt = 1; }
        else {
          if(v[i][j]==pc) cnt++;
          else{
            if(base[lt]!=pc) { flag = false; break; }
            else{
                  m[i][lt++] = cnt ;
                  pc = v[i][j]; cnt = 1;
                }
            }
        }

        if((j+1)==v[i].length()) {
          if(base[lt]!=pc) { flag = false; break; }
          else {
            m[i][lt++] = cnt ;
          }
        }
      }
      if(lt!=l) flag=false;
      if(flag==false) break;
    }
    if(!flag) { tp++; cout << "Case #" << tp << ": " << "Fegla Won" << endl ; continue; }
    ans = 1000000 ;
    lpu(i,0,l) m[v.size()][i] = 1;
    lpui(i,0,v.size()){
      ans_t = 0;
      lpu(p,0,base.size()) {
        lpu(q,0,v.size()){
          ans_t += abs(m[q][p] - m[i][p]);
        }
      }
      //cout << "i : " << i << " ans_t : " << ans_t << endl;
      if(ans_t < ans) ans = ans_t ;
    }
    //cout << "DEBUG : BASE STR " ; lpu(i,0,base.size()) putchar(base[i]); putchar('\n');
    tp++; cout << "Case #" << tp << ": " << ans << endl;
  }

  return 0;
}