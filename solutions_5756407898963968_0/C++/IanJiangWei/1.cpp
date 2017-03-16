#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int cas_num;
	ifstream infile("A-small-attempt1 (1).in");
	ofstream outfile("aresult.txt");
	infile>>cas_num;
	int a[4][4],b[4][4],al,bl,same;
	for (int i=0;i<cas_num;i++)
	{
		infile>>al;
		//outfile<<al<<endl;//----------
		al--;
		for (int j=0;j<4;j++)
		{
			for (int k=0;k<4;k++)
			{
				infile>>a[j][k];
				//outfile<<a[j][k]<<" ";//----------
			}
			//outfile<<endl;//------------
		}
		infile>>bl;
		//outfile<<bl<<endl;//----------
		bl--;
		for (int j=0;j<4;j++)
		{
			for (int k=0;k<4;k++)
			{
				infile>>b[j][k];
				//outfile<<b[j][k]<<" ";//----------
			}
			//outfile<<endl;//------------
		}
		bool ok=false;
		bool over=false;
		for (int j=0;j<4;j++)
		{
			for (int k=0;k<4;k++)
			{
				if (a[al][j]==b[bl][k])
				{
					if (ok==true)
					{
						over=true;break;
					}
					else ok=true;
					same=b[bl][k];
				}
			}
		}
		outfile<<"Case #"<<i+1<<": ";
		if (over==true)
		{
			outfile<<"Bad magician!";
		}
		else if(ok==false)
			outfile<<"Volunteer cheated!";
		else
			outfile<<same;
		outfile<<endl;
	}
	outfile.close();
	infile.close();
	return 0;
}