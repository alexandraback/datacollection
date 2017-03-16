/**********************************
 *          Vinit Gandhi          *
 *  L. D. College of Engineering  *
 **********************************/
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MP   make_pair
#define PB   push_back
#define FI   first
#define SE   second
#define ll   long long
#define SIGN(x) (((x)>0)-((x)<0))
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a)   ((ll)(a).size())
#define FILL(a,x)   memset(a, (x), sizeof((a)));
#define IN(l,i,r)   ((l)<(i)&&(i)<(r))
#define LIN(l,i,r)  ((l)<=(i)&&(i)<(r))
#define INR(l,i,r)  ((l)<(i)&&(i)<=(r))
#define LINR(l,i,r) ((l)<=(i)&&(i)<=(r))
#define cmp_db(a,b) (abs(b-a)<eps)
#define is_int(a)   (cmp(a,0))
#define FOR(i,b,e,s)  for(i=(b);SIGN(s)*i<SIGN(s)*(e);i+=(s))
#define FORE(it,a)    for(auto &it : (a))
#define PRESENT(c,x)  ((c).find(x)!=(c).end())
#define CPRESENT(c,x) (find(ALL(c),x)!=(c).end())
#define nl         cout<<'\n'

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const ll mod=1e9+7;
const double pi=acos(-1.0);
const double eps=1e-6;
const int MAX_SIZE=100;
const int dX[]={-1, 1, 0, 0,-1, 1,-1, 1};
const int dY[]={ 0, 0,-1, 1, 1,-1,-1, 1};

template<class S, class T> ostream& operator<<(ostream& o,const pair<S,T>& a)  {o<<a.FI<<" "<<a.SE<<" "; return o;}
template<class S, class T> ostream& operator<<(ostream& o,const map<S,T>& a)   {FORE(it,a) o<<(it); return o;}
template<class S> ostream& operator<<(ostream& o,const vector<S>& a)           {FORE(it,a) o<<(it)<<" ";  o<<"\n"; return o;}
template<class S> ostream& operator<<(ostream& o,const vector<vector<S> >& a)  {FORE(it,a) o<<(it); return o;}
template<class S> ostream& operator<<(ostream& o,const set<S>& a)              {FORE(it,a) o<<(it)<<" "; o<<"\n"; return o;}
const ll MAX=100;
int p[MAX];
int main()
{
    IOS;
    int i, t, T, N;
    cin>>T;
    FOR(t, 0, T, 1)
    {
        priority_queue<pii> q;
        cout<<"Case #"<<t+1<<": ";
        cin>>N;
        FOR(i, 0, N, 1)
        {
            cin>>p[i];
            q.push(MP(p[i], i));
        }
        while(SZ(q)>2)
        {
            pii temp=q.top();
            q.pop();
            cout<<char(temp.SE+'A')<<" ";
            if(temp.FI-1)
                q.push(MP(temp.FI-1, temp.SE));
        }
        pii temp1=q.top();
        q.pop();
        pii temp2=q.top();
        q.pop();
        while(temp1.FI > temp2.FI)
        {
            cout<<char(temp1.SE+'A')<<" ";
            temp1.FI--;
        }
        while(temp1.FI)
        {
            cout<<char(temp1.SE+'A')<<char(temp2.SE+'A')<<" ";
            temp1.FI--;
        }
        nl;
    }
    return 0;
}
