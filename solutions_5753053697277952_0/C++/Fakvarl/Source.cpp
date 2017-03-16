#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	ifstream in("A.in");
	ofstream out("output.txt");
	
	int n;
	in >> n;
	for (size_t i = 0; i < n; i++)
	{
		int pN;
		in >> pN;
		vector<pair<int, char>> prtAr(pN);
		int total = 0;
		for (size_t j = 0; j < pN; j++)
		{
			prtAr[j].second = 'A' + j;
			in >> prtAr[j].first;
			total += prtAr[j].first;
		}

		out << "Case #" << i+1 << ":";
		
		while (total > 0)
		{
			sort(prtAr.begin(), prtAr.end(), [](pair<int, char> a, pair<int, char> b) { return a.first > b.first; });
			if (prtAr[0].first == 0)
			{
				break;
			}

			out << " " <<prtAr[0].second;
			if (prtAr[0].first == prtAr[1].first && total != 3)
			{
				out <<prtAr[1].second;
				prtAr[1].first -= 1;
				total--;
			}
			prtAr[0].first -= 1;
			total--;

		} 
		
		out << endl;

	}
}