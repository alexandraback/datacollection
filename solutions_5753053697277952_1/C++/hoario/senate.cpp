#include <iostream>
#include <map>

using namespace std;

typedef map<char, int> Senate;

char get(Senate & senate) {
	char who = 'Z';
	int max = 0;
	Senate::iterator next;
	for (Senate::iterator i = senate.begin(); i != senate.end(); ++i) {
		if(i->second > max) {
			who = i->first;
			max = i->second;
			next = i;
		}
	}
	if (--next->second == 0) senate.erase(next);
	return who;	
}

int main(int argc, char** argv) {
	size_t inputCount;
	cin >> inputCount;
	for (size_t inputNumber = 1; inputNumber <= inputCount; ++inputNumber) {
		Senate  senate;
		size_t N;
		size_t total =0;
		cin >> N;
		for (char party = 0; party < N; ++party) {
			cin >> senate['A' + party];
			total += senate['A' + party];
		}
		cout << "Case #" << inputNumber << ":";
		char next;
		while (total > 0) {
			cout << ' ';
			next = get(senate);
			cout << next;
			--total;
			if ((total == 1) ||
			    (total != 0 && total != 2 &&
			     (  (senate.size()-1) <= ((total-1)/2)  ))) {
				next = get(senate);
				cout << next;
				--total;
			}
		}						
		
		for (Senate::const_iterator i = senate.begin(); i != senate.end(); ++i) {
				cout << " " << std::string(i->second, i->first);
		}
		cout << endl;
	}
	return 0;
}
