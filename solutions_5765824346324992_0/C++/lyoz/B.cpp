#include <bits/stdc++.h>
using namespace std;

#define dump(...) cout<<"# "<<#__VA_ARGS__<<'='<<(__VA_ARGS__)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

using uint=unsigned int;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vd=vector<double>;
using vvd=vector<vd>;
using vs=vector<string>;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}

template<typename Tuple>
void print_tuple(ostream&,const Tuple&){}
template<typename Car,typename... Cdr,typename Tuple>
void print_tuple(ostream& os,const Tuple& t){
	print_tuple<Cdr...>(os,t);
	os<<(sizeof...(Cdr)?",":"")<<get<sizeof...(Cdr)>(t);
}
template<typename... Args>
ostream& operator<<(ostream& os,const tuple<Args...>& t){
	print_tuple<Args...>(os<<'(',t);
	return os<<')';
}

template<typename Ch,typename Tr,typename C>
basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>& os,const C& c){
	os<<'[';
	for(auto i=begin(c);i!=end(c);++i)
		os<<(i==begin(c)?"":" ")<<*i;
	return os<<']';
}

constexpr int INF=1e9;
constexpr int MOD=1e9+7;
constexpr double EPS=1e-9;

void solve()
{
	int n,k; scanf("%d%d",&n,&k);
	vi bs(n);
	rep(i,n) scanf("%d",&bs[i]);
	
	// 時刻loに1人以上の客の髪を切り始めており，その客の中にk人目がいる
	ll lo=0,hi=1.1e14;
	while(lo<hi){
		ll mi=(lo+hi)/2;
		ll sum=0;
		rep(i,n) sum+=mi/bs[i]+1;
		if(sum>=k) hi=mi;
		else       lo=mi+1;
	}
	
	using State=pair<ll,int>;
	priority_queue<State,vector<State>,greater<State>> pq;
	rep(i,n){
		k-=lo/bs[i];
		pq.emplace(lo/bs[i]*bs[i],i);
	}
	for(;k>1;k--){
		State cur=pq.top(); pq.pop();
		cur.first+=bs[cur.second];
		pq.push(cur);
	}
	printf("%d\n",(int)pq.top().second+1);
}

int main()
{
	int tc; scanf("%d",&tc);
	rep(i,tc){
		printf("Case #%d: ",i+1);
		solve();
	}
}
