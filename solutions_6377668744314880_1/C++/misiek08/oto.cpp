#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<map>
#define int long long
#define ll long long
#define ld long double
#define MAX_N 200021
//#define M_PI (long double)(3.14159265358979323846)
using namespace std;

ll z, n, R, stos_it, wyznacznik;
ld wynik=0;
pair<ll, ll> algosi[MAX_N];
pair<ll, ll> stos[MAX_N];
vector< pair<ll, ll> > otoczka;
map< pair<ll, ll>, bool> mapa;

ld dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
}

ll det(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C)
{
    pair<ll, ll> AB=make_pair(B.first-A.first, B.second-A.second);
    pair<ll, ll> AC=make_pair(C.first-A.first, C.second-A.second);
    return (AB.first*AC.second)-(AB.second*AC.first);
}

void w_jedna_strone()
{
    stos_it=1;
    stos[stos_it]=algosi[1];

    for(int i=2; i<=n; ++i)
    {
        wyznacznik=0;
        //if(stos_it>1) wyznacznik=det(stos[stos_it-1], stos[stos_it], algosi[i]);
        //if(stos_it>1 && wyznacznik==0) stos_it--;
        while( stos_it>=2 && det(stos[stos_it-1], stos[stos_it], algosi[i]) > 0 )  stos_it--;
        stos_it++;
        stos[stos_it]=algosi[i];
    }
    for(int i=1; i<=stos_it-1; ++i) otoczka.push_back(stos[i]);
}

void znajdz_otoczke()
{
    sort(algosi+1, algosi+n+1);
    w_jedna_strone();
    reverse(algosi+1, algosi+n+1);
    w_jedna_strone();
}

main()
{
    ios_base::sync_with_stdio(0);
    cin >> z;
    for(int lzd=0; lzd<z; ++lzd)
    {
        cin >> n;
		vector< pair< ll, ll> > pkt;
		for(int i=1; i<=n; ++i) {cin >> algosi[i].first >> algosi[i].second; pkt.push_back(algosi[i]);}
        if(n==1)
        {
            cout << "Case #" << lzd+1 << ":" << endl;
			cout << 0 << endl;
            continue;
        }
        if(n==2)
        {
            cout << "Case #" << lzd+1 << ":" << endl;
			cout << 0 << endl << 0 << endl;
            continue;
        }
        znajdz_otoczke();

        otoczka.push_back(otoczka[0]);
        //for(int i=0; i<otoczka.size()-1; ++i) {/*cout << otoczka[i].first << " " << otoczka[i].second << endl; */mapa[otoczka[i]]=true;}//wynik+=dist(otoczka[i], otoczka[i+1]);
		//cout << endl;
		cout << "Case #" << lzd+1 << ":" << endl;
		for(int i=0; i<pkt.size(); ++i)
		{
			if(mapa[pkt[i]]==true) {cout << 0 << endl; continue;}
			int ile=0, mini=1e6, wspolliniowe=0, wywal=0;
			
			for(int j=0; j<pkt.size(); ++j)
			{
				if(pkt[j].first==pkt[i].first && pkt[j].second==pkt[i].second) continue;
				wspolliniowe=0; wywal=0;
				for(int k=0; k<pkt.size(); ++k)
				{
					int deta=det(pkt[i], pkt[j], pkt[k]);
					if(deta>0) wywal++;
					
					
					
				}
				mini=min(wywal, mini);
			}
			
			cout << mini << endl;
		}
		//cout << "---" << endl << endl;
        wynik=0; otoczka.clear();
    }
    return 0;
}
