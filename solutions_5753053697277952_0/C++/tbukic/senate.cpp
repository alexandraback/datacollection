#include <iostream>
#include <string>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		
		int positive = 0, p[n]; 
		for (int & party : p) {
			std::cin >> party;
			if (party > 0) {
				positive++;
			}
		}
		
		std::vector<std::string> evacuation;
		std::string evac = "";
		
		while (positive) {
			for (int i = 0; i < n; ++i) {
				if (p[i] > 0) {
					if (positive > 1 || p[i] < 2) {
						--p[i];
						evac += (char) 'A' + i;
					} else {
						p[i] -= 2;
						evac += (char) 'A' + i;
						if (evac.length() == 2) {
							evacuation.push_back(evac);
							evac = "";
						}
						evac += (char) 'A' + i;
					}
					if (p[i] == 0) {
						--positive;
					}
				}
				if (evac.length() == 2) {
					evacuation.push_back(evac);
					evac = "";
				}
			}
			if (evac.length() > 0) {
				evacuation.push_back(evac);
				evac = "";
			}
		}
		
		
		std::cout << "Case #" << i + 1 << ":";
		for (int i = evacuation.size() - 1; i >= 0; --i) {
			std::cout << " " << evacuation[i];
		} 
		
		std::cout << std::endl;
	}

	return 0;
}
