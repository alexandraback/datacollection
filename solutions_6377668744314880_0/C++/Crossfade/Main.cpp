#include "Precomp.h"
using namespace std;

bool isOnTheEdge(vector<pair<int, int>> treeList, int N, int i)
{
	vector<double> angles;
	for (int j = 0; j < N - 1; ++j)
	{
		if (i != j)
		{
			angles.push_back(atan2(treeList[i].second - treeList[j].second, treeList[i].first - treeList[j].first) + M_PI);
		}
	}

	double diff = -99999;
	for (int j = 0; j < angles.size(); ++j)
	{
		for (int k = j + 1; k < angles.size(); ++k)
		{
			double angle = angles[j] - angles[0] + angles[k] - angles[0];
			if (angle > diff)
			{
				diff = angle;
			}
		}
	}
	double eps = 0.00001;
	if (diff < M_PI + eps)
	{
		return true;
	}
	return false;
}

int main()
{
	ifstream  src("Output.txt");
	string currentDate = currentDateTime();
	replace(currentDate.begin(), currentDate.end(), ':', '.');
	ofstream dst((string("Output") + currentDate + string(".txt")).c_str());
	dst << src.rdbuf();
	src.close();
	dst.close();

	ifstream in("Input.txt");
	ofstream out("Output.txt");

	int T;
	in >> T;

	for (int t = 0; t < T; ++t)
	{
		int N;
		in >> N;
		vector<pair<int, int>> treeList;
		treeList.resize(N);
		for (int i = 0; i < N; ++i)
		{
			int tmpX, tmpY;
			in >> tmpX >> tmpY;
			treeList[i] = pair<int, int>(tmpX, tmpY);
		}
		vector<int> result;
		result.resize(N);
		for (int i = 0; i < N; ++i)
		{
			result[i] = -1;
		}
		
		if (N <= 3)
		{
			for (int i = 0; i < N; ++i)
			{
				result[i] = 0;
			}
		}
		else
		{
			for (int i = 0; i < N; ++i)
			{
				if (isOnTheEdge(treeList, N, i))
				{
					result[i] = 0;
				}
				else // not on the edge
				{
					result[i] = N - 3;
					for (int del = 1; del < N - 3; ++del) // delete del trees
					{
						for (int z = 0; z < N; ++z)
						{
							if (i != z)
							{
								vector<pair<int, int>> currentForest;
								currentForest = treeList;
								//currentForest.erase(currentForest.begin() + z);
								currentForest[z] = currentForest[i];
								if (isOnTheEdge(currentForest, N, i))
								{
									result[i] = del;
									goto FOUND;
								}
							}
						}
					}
				}
				FOUND:;
			}
		}

		out << "Case #" << (t + 1) << ":" << endl;
		for (int i = 0; i < result.size(); ++i)
		{
			out << result[i] << endl;
		}
	}

	return 0;
}