#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//ifstream fin("in.txt");
	//ofstream fout("out.txt");
	istream &ist=cin;
	ostream &ost=cout;
	int T;
	ist>>T;
	
	for(int i=1;i<=T;i++){
		int line1,line2;
		int num1[4][4],num2[4][4];
		ist>>line1;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				ist>>num1[j][k];
		ist>>line2;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				ist>>num2[j][k];
		int count[20]={0};
		memset(count,0,80);
		for(int j=0;j<4;j++){
			count[num1[line1-1][j]]++;
			count[num2[line2-1][j]]++;
		}
		int g=0;
		int rem=0;
		for(int j=1;j<=16;j++){
			if(count[j]==2){
				if(g==0){
					g++;
					rem=j;
				}
				else{
					g++;
					ost<<"Case #"<<i<<": Bad magician!"<<endl;
					break;
				}
			}			
		}
		if(g==0)
		{
			ost<<"Case #"<<i<<": Volunteer cheated!"<<endl;
		}
		else if(g==1)
		{
			ost<<"Case #"<<i<<": "<<rem<<endl;
		}
	}
	return 0;
}
/*
1
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
*/