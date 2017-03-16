#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string CASE = "Case #";
const string BAD = "Bad magician!";
const string CHEATED = "Volunteer cheated!";

const int BAD_ANSWER = -1;
const int CHEATED_ANSWER = -2;

int guess(int case_num,ifstream& fin)
{
	int first_answer;
	int second_answer;
	int first_arrange[16];
	int second_arrange[16];
	fin >> first_answer;
	for (int i = 0; i < 16; i++)
    {
		fin >> first_arrange[i];
	}

	fin >> second_answer;
	for (int i = 0; i < 16; i++)
    {
		fin >> second_arrange[i];
	}

	int found[4] = {0};
	int num[4] = {0};

	for (int i = 0; i < 4; i++)
    {
		int cardNum = first_arrange[4*(first_answer-1) + i];
		for (int j = 0; j < 16; j++)
        {
			if (cardNum == second_arrange[j])
			{
				found[j/4]++;
				num[j/4] = cardNum;
			}
		}
	}

	if (found[second_answer-1] == 0)
    {
		return CHEATED_ANSWER;
	}
	if (found[second_answer-1] > 1)
	{
		return BAD_ANSWER;
	}
	return num[second_answer-1];


}
int main()
{
	int T; // number of test cases
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.txt");
	fin >> T;

	for (int i = 0; i < T; i++)
    {
		int a = guess(i+1,fin);
		switch(a) {
			case BAD_ANSWER:
				fout << CASE << (i+1) << ": " << BAD << endl;
				break;
			case CHEATED_ANSWER:
				fout << CASE << (i+1) << ": " << CHEATED << endl;
				break;
			default:
				fout << CASE << (i+1) << ": " << a << endl;
				break;
		}
	}
	fin.close();
	fout.close();
}
