#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::set;
using std::set_intersection;
using std::inserter;

int main()
{
	ifstream cin("A-small.in");
	ofstream cout("A-small.out");

	int cases;
	cin >> cases;
	cin.ignore();

	for (int case_no = 1; case_no != cases+1; ++case_no) {
		int first;
		cin >> first;
		--first;
		vector<set<int>> first_arrange(4);
		for (int i=0; i!=4; ++i)
			for (int j=0; j!=4; ++j) {
				int temp;
				cin >> temp;
				first_arrange[i].insert(temp);
			}
		int second;
		cin >> second;
		--second;
		vector<set<int>> second_arrange(4);
		for (int i=0; i!=4; ++i)
			for (int j=0; j!=4; ++j) {
				int temp;
				cin >> temp;
				second_arrange[i].insert(temp);
			}
		set<int> result;

		set_intersection(
			first_arrange[first].begin(),
			first_arrange[first].end(),
			second_arrange[second].begin(),
			second_arrange[second].end(),
			inserter(result,result.begin()));

		cout << "Case #" << case_no << ": ";
		if (result.size() == 1)
			cout << *result.begin();
		else if (result.size() == 0)
			cout << "Volunteer cheated!";
		else if (1 < result.size() && result.size() <= 4)
			cout << "Bad magician!";
		cout << endl;
	}
	return 0;

}