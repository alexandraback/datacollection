#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream input;
	ofstream output;
	input.open("A-large.in");
	output.open("output.txt");
	
	int T, N, P, p;
	char party;
	
	input >> T;
	
	for (int t = 1; t <= T; t++)
	{
		output <<"Case #" << t << ": ";
		input >> N;
		vector<int> people;
		P = 0;
		for(int n = 0; n < N; n++)
		{
			input >> p;
			P += p;
			people.push_back(p);
		}
		while(P != 0)
		{
			if(P == 3)
			{
				party = distance(people.begin(), max_element(people.begin(), people.end())) + 65;
				output << party << ' ';
				people[party-65]--;
				P--;
			}
			else
			{
				party = distance(people.begin(), max_element(people.begin(), people.end())) + 65;
				output << party;
				people[party-65]--;
				P--;
				party = distance(people.begin(), max_element(people.begin(), people.end())) + 65;
				output << party << ' ';
				people[party-65]--;
				P--;
			}
		}
		output << endl;
	}
	
	output.close();
	input.close();
	
	return 0;
}