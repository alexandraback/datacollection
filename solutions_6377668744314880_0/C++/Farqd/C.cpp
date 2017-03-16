#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
#define FWD(i,a,b) for (int i=(a); i<(b); ++i)
#define BCK(i,a,b) for (int i=(a); i>(b); --i)
#define ALL(u) (u).begin(),(u).end()

#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define x first
#define y second

#define int long long

typedef LL T;
typedef pair<T,T> P;

inline bool left(P& a, P& b, P& c) { //dla slabej otoczki zmienic na ostra nierownosc
return (b.st - a.st) * (c.nd - a.nd) - (c.st - a.st) * (b.nd - a.nd) < 0; // LL !
}

inline void add_point(vector<P>& hull, P pt, int limit) {
while(hull.size() > limit && left(hull[hull.size()-2], hull[hull.size()-1], pt))
hull.pop_back();
hull.pb(pt);
}

// IN: punkty (uwaga: sa sortowane)
// OUT: ich otoczka wypukla
// UWAGA: gdy wszystkie punkty na wejsciu sa wspolliniowe dla SLABEJ OTOCZKI
// kazdy punkt wewnetrzny jest zwrocony i w gornej i w dolnej polotoczce
// w kolejnosci obejscia
vector<P> compute_hull(vector<P>& in) {
sort(ALL(in));
in.resize(unique(ALL(in)) - in.begin()); //zakomentuj jak nie ma powtorzonych punktow
if (in.size() <= 1) return in;
vector<P> out;
REP(i, in.size()) add_point(out, in[i], 1);
int cursize = out.size();
FORD(i, in.size()-1, 0) add_point(out, in[i], cursize);
out.pop_back();
return out;
}

int n; 


pair<int,int> MP [1000];
map<pair<int, int>, int> M;
int wynik[1000];

main()
{
	ios::sync_with_stdio(0);
	int z; cin>>z; for(int x=0; x<z; x++)
	{
		cin>>n;
		vector<P> v;
		int ix=0;
		for(int i=0; i<n; i++)
		{
			int a,b; cin>>a>>b; v.push_back({a,b});
			
			P j = {a,b};

			MP[ix] = j;

			M[j]=ix;
			ix++;
		}


		for(int i=0; i<n; i++)
			wynik[i] = n-1;


		for(int i=0; i<(1<<(n)); i++)
		{
			vector<P> U ;
			int ile =0;
			for(int k=0;k<n; k++)
			{
				if(  (i >> k)  % 2 ==1)
					U.push_back(v[k]);
				else
					ile++;

			}	

			sort(U.begin(), U.end());
			vector<P> oto;
			oto=compute_hull(U);
/*
			if(ile==0)
			{
				cout<<"PASAS  "<<i<<endl;
				cerr<<oto.size()<<endl;
				cerr<<U.size()<<endl;
				for(int i=0; i<oto.size(); i++)
					cout<<oto[i].first<<" "<<oto[i].second<<endl;
			}*/

			for(int j=0; j<oto.size(); j++)
			{
				int nr = M[oto[j]];

				wynik[nr] = min (wynik[nr], ile);
			}
		}

/*
		sort(v.begin(), v.end());
		vector<P> oto;
		oto=compute_hull(v);

		cout<<endl<<endl;
		for(int i=0; i<oto.size(); i++)
			cout<<oto[i].first<<" "<<oto[i].second<<endl;
		cout<<endl;
		
*/




		cout<<"Case #"<<x+1<<":"<<endl;

		for(int i=0; i<n; i++)
		cout<<wynik[i]<<endl;


	}

	return 0;
}