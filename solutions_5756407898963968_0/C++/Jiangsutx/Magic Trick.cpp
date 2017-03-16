#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("A-small-out.txt");		
	ifile.open("A-small-attempt0.in");			

	int T, x1, x2;
	int a[5][5], b[5][5];
	ifile>>T;
	for (int iT=1; iT<=T;iT++)
	{
		ifile>>x1;
		for (int i=1; i<=4; i++)
			for (int j=1; j<=4; j++)
				ifile>>a[i][j];
		ifile>>x2;
		for (int i=1; i<=4; i++)
			for (int j=1; j<=4; j++)
				ifile>>b[i][j];
		int count = 0, ans;
		for (int i=1; i<=4; i++)
			for (int j=1; j<=4; j++)
				if (a[x1][i]==b[x2][j]) {count++; ans = a[x1][i];};

		if (count==0)
			ofile<<"Case #"<<iT<<": "<<"Volunteer cheated!"<<endl;
		else if (count==1)
			ofile<<"Case #"<<iT<<": "<<ans<<endl;
		else
			ofile<<"Case #"<<iT<<": "<<"Bad magician!"<<endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}