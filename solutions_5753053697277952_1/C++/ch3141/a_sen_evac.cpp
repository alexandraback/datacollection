// cat input.in | ./a.out > output
#include <iostream>
#include <vector>
#include <algorithm>


typedef long long myint;

template <typename T>
std::vector<T> read_vector(int length, std::istream& in = std::cin) {
	std::vector<T> vector;
	for(; length>0; length--) {
		T item;
		in >> item;
		vector.push_back(item);
	}
	return vector;
}







// has to print everything except "Case #n: " and eol \n
// read from std::cin
void handle_case() {
	int n;
	std::cin >> n;
	std::vector<int> v = read_vector<int>(n);
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	int sum = 0;
	for(int i: v) sum+= i;
	
	while(sum>0) {
		std::vector<int>::iterator it = std::max_element(v.begin(), v.end());
		std::vector<int>::iterator it2 = std::find(it+1, v.end(), *it);
		
		std::cout << " " << alphabet[(it-v.begin())];
		if(it2 != v.end() && (*it) + (*it2) == sum) {
			(*it2)--;
			sum--;
			std::cout << alphabet[(it2-v.begin())];
		}
		(*it)--;
		sum--;
	}
}


int main() {
	int num_cases;
	std::cin >> num_cases;
	for(int tcase = 1; tcase <= num_cases; tcase++) {
		std::cout << "Case #" << tcase << ":";
		handle_case();
		std::cout << std::endl;
	}
}
