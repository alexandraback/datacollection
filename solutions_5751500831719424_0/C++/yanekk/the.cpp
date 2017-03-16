#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Z[110][110];
int A[110];
int Pref[110];

vector <int> Zmien(int p,string slowo){
	int i,j;
	vector <int> Wynik;
	j = 0;
	Z[p][j]++;
	Wynik.push_back( ((int)slowo[0]-(int)'a') );
	for(i=1; i<slowo.size(); i++){
		if( slowo[i] != slowo[i-1] ){
			Wynik.push_back( ((int)slowo[i]-(int)'a') );
			j++;
		}
		Z[p][j]++;
	}
	return Wynik;
}

bool CzyRowne(vector <int> Wzorzec, vector <int> Nowy ){
	int i;
	if( Wzorzec.size() != Nowy.size() ) return false;
	for(i=0; i<Wzorzec.size(); i++) if( Wzorzec[i] != Nowy[i] ) return false;
	return true;
}

int IleZmian(int n,int l){
	int i,j;
	int ile,suma,wynik,a_wynik;
	wynik = 0;
	for(i=0; i<l; i++){
		for(j=0; j<=110; j++) {
			A[j] = 0;
			Pref[j] = 0;
		}
		for(j=0; j<n; j++){
			A[ Z[j][i] ]++;
		}
		ile = 0;
		suma = 0;
		for(j=0; j<=100; j++){
			Pref[j] = suma;
			suma += ile;
			ile += A[j+1];
		}
		ile = 0;
		suma = 0;
		for(j=101; j>=0; j--){
			Pref[j] += suma;
			suma += ile;
			ile += A[j-1];
		}
		a_wynik = 1000*1000*1000;
		for(j=1; j<=100; j++){
			a_wynik = min( a_wynik,Pref[j] );
		}
		wynik += a_wynik;
	}
	return wynik;
}

int main(){
	string s;
	bool czy;
	vector <int> Wzorzec,Nowy;
	int i,t,n,j,k;
	cin >> t;
	for(i=0; i<t; i++){
		for(j=0; j<=110; j++){
			for(k=0; k<=110; k++) Z[j][k] = 0;
		}
		czy = true;
		cin >> n;
		cin >> s;
		Wzorzec = Zmien(0,s);
		for(j=0; j<n-1; j++){
			cin >> s;
			Nowy = Zmien(j+1,s);
			if( !CzyRowne(Wzorzec,Nowy) ){
				czy = false;
			}
		}
		if( czy ){
			cout << "Case #" << i+1 << ": " << IleZmian(n,Wzorzec.size()) << "\n";
		}
		else{
			cout << "Case #" << i+1 << ": Fegla Won\n";
		}
	}
	return 0;
}
