#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Section {
	int len;
	char c;
};

vector<Section> convertToSections(string input) {
	vector<Section> sections;

	Section last {0, ' '};

	for (char c : input) {
		if (last.c != ' ' && last.c != c) {
			if (last.len > 0) sections.push_back(last);
			last.len = 0;
		}

		last.c = c;
		last.len++;
	}

	if (last.len > 0) sections.push_back(last);

	return sections;
}

void print(vector<Section> sections) {
	for (auto section : sections) {
		cout << section.c << ":" << section.len << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;

		vector<vector<Section>>	strings;

		for (int n = 0; n < N; n++) {
			string input;
			cin >> input;
			auto first = convertToSections(input);
			strings.push_back(first);
			//cout << "#" << input << endl;
			//print(first);
		}

		bool valid = true;
		int moves = 0;

		int length = strings[0].size();
		for (int n = 1; n < N; n++)
			if (length != strings[n].size())
				valid = false;

		if (valid) {
			for (int i = 0; i < length; i++) {
				char c = strings[0][i].c;
				for (int n = 1; n < N; n++)
					if (c != strings[n][i].c)
						valid = false;
			}
		}

		if (valid) {
			for (int i = 0; i < length; i++) {
				vector<int> lengths;
				for (int n = 0; n < N; n++)
					lengths.push_back(strings[n][i].len);
				sort(begin(lengths),end(lengths));

				//cout << "# ";
				//for (auto len : lengths)
				//	cout << len << " ";
				//cout << endl;

				int bestMoves = 1e6;
				for (int i = 0; i < lengths.size(); i++) {
					int goal = lengths[i];
					int preMoves = 0, postMoves = 0;
					for (int j = 0; j < i; j++) preMoves += goal - lengths[j];
					for (int j = i+1; j < lengths.size(); j++) postMoves += lengths[j] - goal;
					//cout << "Pre: " << preMoves << " - Post: " << postMoves << endl;
					int curMoves = preMoves + postMoves;
					//cout << curMoves << endl;
					if (curMoves < bestMoves) bestMoves = curMoves;
				}

				moves += bestMoves;
			}
		}
		
		cout << "Case #" << (i+1) << ": ";

		if (valid)
			cout << moves;
		else
			cout << "Fegla Won";

		cout << endl;
	}

	return 0;
}