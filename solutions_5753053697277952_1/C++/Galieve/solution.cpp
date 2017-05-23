#define WORK_WITH_FILES //(quitar antes de enviar)
#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue> 
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <bitset>
using namespace std;

#endif
#ifndef THEFANTASTICHEADER_H
#define THEFANTASTICHEADER_H

using ullint = unsigned long long int;
typedef unsigned short int usint;

//vector<ullint> calcularPrimos();

template <typename T, typename Comp>
bool busquedaBinaria(const vector<T> &vektor, const T &buscado, int & pos, Comp ord);

template <typename T, typename Comp>
void colocarInsercion(vector<T> & lista, int i, Comp ord);

template <typename T, typename Comp>
void ordenarInsercion(vector<T> & lista, Comp ord);

vector<ullint> calcularPrimos(){
	bool primo = true;
	ullint num = 3, square = ullint(sqrt(ULLONG_MAX));
	vector<ullint> v(1, 2);
	while (num <= square){
		ullint i = 0;
		primo = true;
		while (i < v.size() && primo){
			if (num % v[i] == 0){
				primo = false;
			}
			++i;
		}
		if (primo){
			v.push_back(num);
		}
		++num;
	}
	return v;
}

//Poner Comp ord = Comp() implica que en la UVa no compile.
template <typename T, typename Comp = less<T>>
bool busquedaBinaria(const vector<T> &vektor, const T& buscado, int &pos, Comp ord) {
	int ini = 0, fin = vektor.size(), mitad;
	bool encontrado = false;
	// 0 <= ini <= fin <= N
	// array[0..ini) < buscado Y buscado < array[fin..N)
	while (ini < fin && !encontrado) {
		mitad = (ini + fin - 1) / 2; // división entera
		if (ord(buscado, vektor[mitad])) fin = mitad;
		else if (ord(vektor[mitad], buscado)) ini = mitad + 1;
		else encontrado = true;
	}
	if (encontrado) pos = mitad; // en la posición mitad
	else pos = ini; // No encontrado, le corresponde la posición ini (=fin)
	return encontrado;
}

//Poner Comp ord = Comp() implica que en la UVa no compile.
template <typename T, typename Comp = less<T>>
void colocarInsercion(vector<T> & lista, int i, Comp ord) {
	T elemento = lista[i];
	int j = i;
	while (j > 0 && ord(elemento, lista[j - 1])) {
		lista[j] = lista[j - 1];
		--j;
	}
	if (j != i) lista[j] = elemento;
}

//Poner Comp ord = Comp() implica que en la UVa no compile.
template <typename T, typename Comp = less<T>>
void ordenarInsercion(vector<T> & lista, Comp ord) {
	int N = lista.size();
	for (int i = 1; i < N; ++i) {
		colocarInsercion(lista, i, ord);
	}
}

//UVa Judge
/*
#ifndef ONLINE_JUDGE
ifstream in("casos.txt");
auto cinbuf = cin.rdbuf(in.rdbuf());
ofstream out("answer.txt");
auto coutbuf = cout.rdbuf(out.rdbuf());
#endif

#ifndef ONLINE_JUDGE
cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);
system("pause");
#endif
*/

//UCM
/*
#ifndef DOMJUDGE
ifstream in("casos.txt");
auto cinbuf = cin.rdbuf(in.rdbuf());
ofstream out("answer.txt");
auto coutbuf = cout.rdbuf(out.rdbuf());
#endif

#ifndef DOMJUDGE
cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);
system("pause");
#endif*/

//Cualquier juez
/*
#define WORK_WITH_FILES //(quitar antes de enviar)
#ifdef WORK_WITH_FILES
ifstream in("casos.txt");
auto cinbuf = cin.rdbuf(in.rdbuf());
ofstream out("answer.txt");
auto coutbuf = cout.rdbuf(out.rdbuf());
#endif

#ifdef WORK_WITH_FILES
cin.rdbuf(cinbuf);
cout.rdbuf(coutbuf);
system("pause");
#endif*/
#endif
struct partido{
	int n;
	char letra;
};
void maximo(vector<partido> &lista, char &a);
int main(){
#ifdef WORK_WITH_FILES
	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
	ofstream out("answer.txt");
	auto coutbuf = cout.rdbuf(out.rdbuf());
#endif
	int casos;
	char a, b;
	cin >> casos;
	for (int i = 0; i < casos; ++i){
		int tam;
		cin >> tam;
		string ans = "";
		vector<partido> lista(tam);
		for (int i = 0; i < tam; ++i){
			cin >> lista[i].n;
			lista[i].letra = char(i) + 'A';
		}
		maximo(lista, a);
		ans += a;
		while (lista.size() > 0){
			maximo(lista, a);
			if (lista.size() == 1){
				ans += " ";
				ans += a;
				maximo(lista, a);
				ans += a;
			}
			else if (lista.size() > 0){
				ans += a;
				maximo(lista, a);
				ans += " ";
				ans += a;
			}
			else{
				ans += a;
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << "\n";
	}
	/*
	Escribir codigo aquí
	*/
#ifdef WORK_WITH_FILES
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);
	system("pause");
#endif
}
void maximo(vector<partido> &lista, char &a){
	int max = lista[0].n, ind = 0;
	for (int i = 1; i < lista.size(); ++i){
		if (lista[i].n > max){
			max = lista[i].n;
			ind = i;
		}
	}
	--lista[ind].n;
	a = lista[ind].letra;
	if (lista[ind].n == 0){
		lista.erase(lista.begin() + ind);
	}
}