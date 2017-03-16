//============================================================================
// Name        : QualificationRoundA.cpp
// Author      : crr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int nCase;
	ifstream fin("A-small-attempt0.in");
	ofstream cout("A-small-practice.out");
	fin >> nCase;
//	cout << nCase << endl;
	bool isFirstCase = true;
	for(int iCase=0;iCase<nCase;iCase++)
	{
		if(isFirstCase)
			isFirstCase = false;
		else
			cout<<endl;
		cout<<"Case #"<<iCase+1<<": ";
		int line1;
		vector<int> set1;
		fin >> line1;
//		cout << line1 << endl;
		for(int i=0;i<4;i++)
		{
			int elem;
			if(i==(line1-1))
			{
				for(int ii=0;ii<4;ii++) {
					fin>> elem;
					set1.push_back(elem);
				}
			}else
				fin>>elem>>elem>>elem>>elem;
		}
		int line2;
		vector<int> set2;
		fin >> line2;
//		cout << line2 << endl;
		for(int j=0;j<4;j++)
		{
			int elem;
			if(j==(line2-1)) {
				for(int jj=0;jj<4;jj++) {
					fin >> elem;
					set2.push_back(elem);
				}
			}else
				fin>>elem>>elem>>elem>>elem;
		}

		sort(set1.begin(),set1.end());
		sort(set2.begin(),set2.end());
		vector<int> intersection;
		set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),back_inserter(intersection));
		if(intersection.size() == 0)
			cout << "Volunteer cheated!";
		else if(intersection.size() ==1)
			cout << intersection[0];
		else
			cout << "Bad magician!";
	}

	return 0;
}
