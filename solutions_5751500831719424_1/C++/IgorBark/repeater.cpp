#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std ;

int main()
{
	ifstream fin;
	fin.open("repeater.in");

	ofstream fout;
	fout.open("repeater.out");

	int T,N;
	fin >> T;
	for(int caseNum = 1 ; caseNum <= T ; caseNum ++)
	{
		fin >> N;

		string cur;
		vector<pair<char,vector<int> > > reduced = vector<pair<char,vector<int> > >(0);

		fin >> cur;
		for(int i = 1; i < cur.size() ; i ++)
		{
			if(cur[i] != cur[i - 1])
			{
				reduced.push_back(make_pair(cur[i-1],vector<int>(0)));
			}
		}
		reduced.push_back(make_pair(cur[cur.size() - 1],vector<int>(0)));

		bool bad = false;
		for(int i = 0 ; i < N ; i ++)
		{
			if(i != 0)
				fin >> cur;

			if(!bad)
			{
				int curnum = 1;
				int curtrack = 0;

				if(cur[0] != reduced[0].first)
					bad = true;

				for(int s = 1 ; s < cur.size() && !bad ; s ++)
				{
					if(cur[s] == cur[s-1])
					{
						curnum ++;
					}
					else
					{
						reduced[curtrack].second.push_back(curnum);
						curtrack ++;
						curnum = 1;
						if(curtrack >= reduced.size() || cur[s] != reduced[curtrack].first)
							bad = true;
					}
				}

				if(!bad)
					reduced[curtrack].second.push_back(curnum);
				if(curtrack < reduced.size() - 1)
					bad = true;
			}
		}
		
		if(!bad)
		{
			int total = 0;
			for(int i = 0 ; i < reduced.size() ; i ++)
			{
				sort(reduced[i].second.begin(), reduced[i].second.end());
				int mid = reduced[i].second[(int)(reduced[i].second.size() / 2)];
				for(int j = 0 ; j < reduced[i].second.size() ; j ++)
					total += abs(reduced[i].second[j] - mid);
			}
			fout << "Case #" << caseNum << ": " << total << endl;
		}
		else
		{
			fout << "Case #" << caseNum << ": Fegla Won" << endl;
		}
	}
	return 0 ;
}