#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void getCandidate(int* candidate)
{
	int row, tmp;
	cin>> row;
	for(int r=1;r<=4;r++)
	{
		if(r == row)
		{
			for(int i=0;i<4;i++)
				cin>> candidate[i];
		}
		else
		{
			for(int i=0;i<4;i++)
				cin>> tmp;
		}
	}
}

int main()
{
	int caseNum;
	cin >> caseNum;
	for(int t=1; t<=caseNum; t++)
	{
		int candidateA[4];
		int candidateB[4];
		getCandidate(candidateA);
		getCandidate(candidateB);
		int numMatch = 0;
		int match = 0;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				if(candidateA[i] == candidateB[j])
				{
					match = candidateA[i];
					numMatch++;
				}
			}
		}

		cout<< "Case #"<<t<<": ";
		switch (numMatch)
		{
		case 0:
			cout << "Volunteer cheated!"<<endl;
			break;
		case 1:
			cout << match<<endl;
			break;
		default:
			cout << "Bad magician!"<<endl;
			break;
		}
	}
	return 0;
}
