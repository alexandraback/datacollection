#include <fstream>
using namespace std;

#include "MagicTrick.cpp"

int main() {
	ifstream infile("A-small-attempt1.in");
	ofstream outfile("results.out");
	MagicTrick trick;
	trick.go(infile, outfile);
}