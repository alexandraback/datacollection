#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int distance_to_media(std::vector<int> &v){
	std::sort(v.begin(), v.end());
	int median = v[v.size()/2];
	int distance=0;
	for(int K=0; K<v.size(); ++K)
		distance += std::abs(v[K]-median);
	return distance;
}

template<class Iter, class T>
int cuenta_repetidos(Iter &begin, Iter end, T val){
	int count = 0;
	for(; begin not_eq end; ++begin)
		if(*begin == val)
			++count;
		else
			break;
	return count;
}

template<class Iter>
void print(Iter begin, Iter end){
	for(; begin not_eq end; ++begin)
		std::cout << *begin << ' ';
	std::cout << '\n';
}

template<class Cont_Iter, class Cont>
bool done(const Cont_Iter &cit, const Cont &cont){
	int n=cit.size();
	for(int K=0; K<n; ++K)
		if(cit[K] not_eq cont[K].end())
			return false;
	return true;
}

int solve(std::vector<std::string> &words){
	int n = words.size();
	int total = 0;
	//recorrer las cadenas y contar las repeticiones del 'primer' caracter
	std::vector<std::string::iterator> wit(n);
	for(int K=0; K<n; ++K)
		wit[K] = words[K].begin();

	while( wit[0] not_eq words[0].end() ){
		std::vector<int> cantidad(n);
		char value = *wit[0];
		for(int K=0; K<n; ++K)
			cantidad[K] = cuenta_repetidos(wit[K], words[K].end(), value);
		total += distance_to_media(cantidad);
		if(cantidad[0] == 0)
			return -1;
	}
	if(not done(wit, words))
		return -1;
	return total;
}

void magia(std::vector<std::string> &words){
	int result = solve(words);
	if( result == -1 )
		std::cout << "Fegla Won";
	else
		std::cout << result;
}

int main(){
	int casos;
	std::cin >> casos;
	for(int K=1; K<=casos; ++K){
		int n;
		std::cin>>n;
		std::vector<std::string> words(n);

		for(int L=0; L<n; ++L)
			std::cin>>words[L];

		std::cout << "Case #" << K << ": ";
		magia(words);
		std::cout << '\n';
	}
}
