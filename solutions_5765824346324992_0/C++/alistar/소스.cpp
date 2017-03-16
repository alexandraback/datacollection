#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int B[6];
int b;
int N;
int sum[6];

int Haircut()
{
	int index=1;
	int cnt=0;
	int end=N;
	while(N--)
	{
		end++;
		cnt++;
		int m=987654321;
		for (int i = 1; i <= b; i++)
		{
			if(sum[i] < m)
			{
				index=i;
				m=sum[i];
			}
		}
		sum[index]=sum[index]+B[index];
		
		int p=sum[1];
		bool flag=true;
		for (int i = 2; i <= b; i++)
		{
			if(p!=sum[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
			N=end%cnt;
	}
	return index;
}



int main()
{
	ifstream OpenFile("B-small-attempt0.txt");
	ofstream SaveFile("output6.txt");

	int T;
	OpenFile>>T;
	for (int t = 0; t < T; t++)
	{
		int res;
		OpenFile>>b>>N;
		memset(B,0,sizeof(int)*6);
		memset(sum,0,sizeof(int)*6);
		for (int i = 1; i <= b; i++)
			OpenFile>>B[i];
		SaveFile<<"Case #"<<t+1<<": "<<Haircut()<<endl;
	}
	OpenFile.close();
	SaveFile.close();
	return 0;
}
