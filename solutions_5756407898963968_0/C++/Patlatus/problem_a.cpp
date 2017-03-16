#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

int a1, a2;
int deck1[4][4], deck2[4][4];

string solve() {
	set<int> s1;
	set<int> s2;
	set<int> intersect;

  
	for ( int i = 0; i < 4; i++)
		s1.insert(deck1[a1 - 1][i]);
	for ( int i = 0; i < 4; i++)
	    s2.insert(deck2[a2 - 1][i]);

	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(intersect,intersect.begin()));
	switch (intersect.size()){
	case 1:
		return to_string(static_cast<long long>(*intersect.begin()));
    break;
	case 0:
		return "Volunteer cheated!";
    break;
	default:
		return "Bad magician!";
	}
}

int main(int argc, char* argv[]) {	
	string inputFile = (argc > 1) ? argv[1] : "input.txt";
	string outputFile = (argc > 2) ? argv[2] : (argc > 1) ? (inputFile + "out.txt") : "output.txt";
	ifstream in;
	ofstream out;
	in.open(inputFile);
	out.open(outputFile);

	int tests;
	in >> tests;
	for (int test = 1; test <= tests; ++test) {
		out << "Case #" << test << ": ";
		// Grab input
		in >> a1;
		for ( int i = 0; i < 4; i++ ) {
			for ( int j = 0; j < 4; j++ ) {
				in >> deck1[i][j];
			}
		}
		in >> a2;
		for ( int i = 0; i < 4; i++ ) {
			for ( int j = 0; j < 4; j++ ) {
				in >> deck2[i][j];
			}
		}
		// Solve the problem and give feedback to the end user;
		out << solve() << endl;
		cerr << ": " << test << endl;
	}

	in.close();
	out.close();

	cout << inputFile << '\n' << outputFile << '\n';
 	cin.get();
	return 0;
}