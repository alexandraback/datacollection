#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <numeric> //accumulate(i poczatek,i koniec, wartosc_poczatkowa)
#include <utility> //swap
#include <map>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
int main (int argc, char * const argv[]) {
	if(!freopen("in4.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
		if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
	ios_base::sync_with_stdio(0);
	//usuwam powtorzenia wszystkich liter i sprawdzam, czy sa takie same, jezeli nie to sie nie da
	//dla kazdej litery z kazdego wyrazu po redukcji aaabc do abc zapamietuje ile liter jest we wejsciowym 3,1,1
	//porownoje dwie tablice, czy usuwam czy dodaje nie ma znaczenia
	
	//w rozszerzonym w tych tablicach musze znalezc wartosc srednia dla kazdej litery
	//moge sprawdzic wszystkie 100!!!! wartosci i policzyc ktora sie najbardziej oplaca!! - i mam rozw
	int t,n;
	cin>>t;
	FOR(numer_testu,1,t){
		cin>>n;
		vector<string> lancuch(n);
		vector<string> lancuchy_skrocone(n);
		vector<vector<int> >tablica(n);
		REP(x,n) cin>>lancuch[x];
		//teraz kazdy lancuch sprowadzam do lancucha bez powtorzen
		bool da_sie=1;
		REP(numer_lancucha,n){
			int ile=1;
			REP(pozycja,lancuch[numer_lancucha].size()){
				if(pozycja==0) lancuchy_skrocone[numer_lancucha]+=lancuch[numer_lancucha][pozycja];
				else {
					if(lancuch[numer_lancucha][pozycja]!=lancuch[numer_lancucha][pozycja-1]){lancuchy_skrocone[numer_lancucha]+=lancuch[numer_lancucha][pozycja];tablica[numer_lancucha].PB(ile);ile=1;}
					else ile++;
				}
			}
			tablica[numer_lancucha].PB(ile);
			//jak sie konczy na 2 takie same np. bb to nie push backnie ile
			//if(lancuch[numer_lancucha][SIZE(lancuch[numer_lancucha])-1]==lancuch[numer_lancucha][SIZE(lancuch[numer_lancucha])-2])//przedost rowna sie ost
			//	tablica[numer_lancucha].PB(ile),lancuchy_skrocone[numer_lancucha]+=lancuch[numer_lancucha][SIZE(lancuch[numer_lancucha])-1];
			if(numer_lancucha and lancuchy_skrocone[numer_lancucha]!=lancuchy_skrocone[numer_lancucha-1]){
				da_sie=0;
				break;
			}
		}
		/*cout<<"wypis tabl: "<<endl;
		REP(x,n){
			REP(y,lancuchy_skrocone[x].size()){
			cout << tablica[x][y]<<" ";	
			}
			cout << endl;
		}*/
		LL ans=0;
		cout << "Case #"<<numer_testu<<": ";
		if(!da_sie) cout<<"Fegla Won"<<endl;
		else {
			//cout<<endl;
			//licze ile trzeba wykonac
			REP(numer_w_tablicy,lancuchy_skrocone[0].size())//wszystkie maja taka sama dlugosc
			{
				LL optymalna=1000000000;
				FOR(wartosc_optymalna,1,100){LL temp=0;
				REP(numer_lancucha,n){
					temp+=abs(wartosc_optymalna- tablica[numer_lancucha][numer_w_tablicy]);
					
				}
					optymalna=min(optymalna, temp);
				}
				ans+=optymalna;
			}
			cout << ans<<endl;
		}

	}
	
	
    return 0;
}
