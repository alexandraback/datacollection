#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

struct SCase{
	int iFirstAnswer;
	vector<vector<int>> vFirstArrangement;
	int iSecondAnswer;
	vector<vector<int>> vSecondArrangement;

	int Solve(string* error) {
		vector<int> results;
		for (int card: vFirstArrangement[iFirstAnswer - 1])
		{
			const vector<int>& row = vSecondArrangement[iSecondAnswer - 1];
			if (find(row.begin(), row.end(), card) != row.end())
				results.push_back(card);
		}

		if (results.empty()) {
			*error = "Volunteer cheated!";
			return 0;
		} else if (results.size() > 1) {
			*error = "Bad magician!";
			return 0;
		} else {
			return results.front();
		}
	}
};


struct SInput{
	vector<SCase> vCases;

	SInput(){
		ifstream ifs("i");
		assert(!ifs.bad());

		int iCaseNumber;
		ifs >> iCaseNumber;
		for (int i = 0; i < iCaseNumber; ++i)
		{
			SCase Case;
			ReadAnswer(ifs, &Case.iFirstAnswer, &Case.vFirstArrangement);
			ReadAnswer(ifs, &Case.iSecondAnswer, &Case.vSecondArrangement);
			vCases.push_back(Case);
		}
	}

	void ReadAnswer(istream& is, int* piAnswer, vector<vector<int>>* pvArrangement)
	{
		is >> *piAnswer;
		for (int i = 0; i < 4; ++i)
		{
			pvArrangement->push_back(vector<int>(4));
			for (int k = 0; k < 4; ++k)
				is >> (*pvArrangement)[i][k];
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	SInput inp;
	
	ofstream ofs("o.txt");	
	for (size_t i = 0; i < inp.vCases.size(); ++i)
	{
		ofs << "Case #" << (i+1) << ": ";
		string error;
		int result = inp.vCases[i].Solve(&error);
		if (result > 0)
			ofs << result;
		else
			ofs << error;
		ofs << endl;
	}

	cin.get();

	return 0;
}

