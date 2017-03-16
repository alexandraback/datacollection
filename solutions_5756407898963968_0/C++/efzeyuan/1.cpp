#include<iostream>
#include<fstream> 
using namespace std;

int main()
{
	ifstream f;
	ofstream f1;
	f.open("E:\\code jam\\A-small-attempt5.in");
	f1.open("E:\\code jam\\1.out");
	int n;
	f>>n;
	int i,j;
	int a,b,output;
	int caseA[20],caseB[20];
	int result[20];
	int flag;
	for (i=0;i<n;i++)
	{
		for (j=0;j<17;j++) result[j]=0;
		f>>a;
		for (j=0;j<16;j++) f>>caseA[j];
		for (j=0;j<4;j++)
		{
			result[caseA[a*4+j-4]]++;
		}
		f>>b;
		for (j=0;j<16;j++) f>>caseB[j];
		for (j=0;j<4;j++)
		{
			result[caseB[b*4+j-4]]++;
		}
		flag=0;
		for (j=0;j<17;j++)
		{
			if (result[j]==2)
			{
				flag++;
				output=j;
			}
		}
		f1<<"Case #"<<i+1<<": ";
		if (flag==0) f1<<"Volunteer cheated!"<<endl;
		if (flag==1) f1<<output<<endl;
		if (flag>1) f1<<"Bad magician!"<<endl;
	}
}
