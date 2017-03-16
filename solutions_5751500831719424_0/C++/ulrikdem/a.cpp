#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int strings;
		cin >> strings;
		string line, simplified;
		cin >> line;
		char current = 0;
		vector<vector<int>> count;
		for(char next : line) {
			if(next != current) {
				simplified += next;
				current = next;
				count.push_back({1});
			} else {
				++count[count.size() - 1][0];
			}
		}
		bool valid = true;
		for(int string = 1; string < strings; ++string) {
			cin >> line;
			if(valid) {
				int index = 0, next = 0;
				for(char current : simplified) {
					if(next == line.size() || line[next] != current) {
						valid = false;
						break;
					}
					int counter = 0;
					while(next < line.size() && line[next] == current) {
						++next;
						++counter;
					}
					count[index++].push_back(counter);
				}
				if(next != line.size()) {
					valid = false;
				}
			}
		}
		if(valid) {
			int actions = 0;
			for(auto& sequence : count) {
				nth_element(sequence.begin(), sequence.begin() + sequence.size() / 2, sequence.end());
				int median = sequence[sequence.size() / 2];
				for(int value : sequence) {
					actions += abs(value - median);
				}
			}
			cout << "Case #" << test << ": " << actions << '\n';
		} else {
			cout << "Case #" << test << ": Fegla Won\n";
		}
	}
	return 0;
}
