#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int row1[4];
int row2[4];
void ReadLine(ifstream& in,int r, int row[4])
{
	 int temp;
	 for (int i = 1 ; i < r; ++i)
		 for(int j = 0 ; j <4;++j)
			in >>temp;
	 for (int j = 0; j<4;++j)
		 in >> row[j];
	 for(int i = r; i<4; ++i)
		 for(int j = 0 ; j <4;++j)
			 in >>temp;
}
int  CheckRow1InRow2(int row1[4],int row2[4],int * num)
{
	int n;
	n = 0;
	for (int i = 0;i<4;++i)
	{
		for (int j = 0; j<4; ++j)
		{
			if (row2[i] == row1[j])
			{
				n++;
				*num = row2[i];
				break;
			}
		}
	}
	return n;
}

int main()
{
	ifstream infile;
	infile.open("A-small-attempt0.in");
	ofstream outfile("DATA.OUT");
	int n;
	infile >> n;// cases
	int r1,r2;	// ROW ANSWERS
	int t;int num;
	for (int i = 0; i<n; ++i)
	{
		infile >> r1;
		ReadLine(infile,r1,row1);
		infile >> r2;
		ReadLine(infile,r2,row2);
		t = CheckRow1InRow2(row1,row2,&num);
		if (t ==0)
		{
			outfile << "Case #" << i+1 <<": Volunteer cheated!\n";
		}else if (t == 1)
		{
			outfile << "Case #" << i+1 <<": " << num <<'\n';
		}else if(t > 1)
		{
			outfile << "Case #" << i+1 <<": Bad magician!\n";
		}
	}
}

