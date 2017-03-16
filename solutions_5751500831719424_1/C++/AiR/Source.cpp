#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int ruchy_na_litere(string* s, int start, int n){
	char a = s[0][start];
	for (int i = 0; i < n; i++){
		if (s[i][start] != a) return -1;
	}
	int ile_razy_powt_litera = 0;
	for (int i = 0; i < n; i++){
		if (s[i][start] == s[i][start + 1]) ile_razy_powt_litera++;
	}
	if (ile_razy_powt_litera > n / 2) {//dodaje powtorki
		
		for (int i = 0; i < n; i++){
			if (s[i][start] != s[i][start + 1])
			s[i].insert(s[i].begin() + start, s[i][start]);
			//cout << s[i] << endl;
		}
		return n - ile_razy_powt_litera;
	}
	else{//usuwam powtorki
		for (int i = 0; i < n; i++){
			if (s[i][start] == s[i][start + 1])
			s[i].erase(s[i].begin() + start);
			//cout << s[i] << endl;
		}
		return ile_razy_powt_litera;
	}
}

int main(){
	fstream plik, plikout;
	plik.open("a.in", ios::in);
	plikout.open("a.out", ios::out);
	int t;
	plik >> t;
	int n;

	for (int i = 0; i < t; i++){
		plik >> n;
		string* s = new string[n];
		for (int j = 0; j < n; j++){
			plik >> s[j];
			//cout << s[j] << endl;
		}
		int wynik = 0, dodaj = 0;
		int j = 0;
		bool blad = false;
		while(j < s[0].length()){
			dodaj = ruchy_na_litere(s, j, n);
			if (dodaj < 0){
				blad = true;
				break;
			}
			wynik += dodaj;
			if (dodaj == 0) j++;
		}
		int dlugosc = s[0].length();
		for (int j = 1; j < n; j++){
			if (s[j].length() != dlugosc){
				blad = true;
			}
		}
		if (blad){
			plikout << "Case #" << i + 1 << ": Fegla Won" << endl;
		}
		else{
			plikout << "Case #" << i + 1 << ": " << wynik << endl;
		}
		delete [] s;
	}

	system("pause");
	plik.close();
	plikout.close();
}