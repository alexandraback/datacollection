#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("A-large-out.txt");		
	ifile.open("A-large.in");			
	//ifile.open("B-small.txt");	

	long T;
	long N;
	char a[110];
	int b[110][110];
	

	ifile>>T;
	for (int iT=1; iT<=T;iT++)
	{
		ifile>>N;
		char ch[110][200];
		int number = 0;
		for (int i=0; i<N; i++)
		{
			ifile>>ch[i];
		}
		for (int i=0; i<110; i++)
		{
			for (int j=0; j<110; j++)
				b[i][j] = 0;
		}
		bool fail_flag = false;
		for (int i=0; i<N; i++)
		{
			if (i==0)
			{
				a[0] = ch[i][0];
				number = 0; b[number][i] += 1;
				for (int j=1;j<strlen(ch[i]);j++)
				{
					if (ch[i][j]==a[number])
					{
						b[number][i] += 1;
					}
					else
					{
						number++;
						a[number] = ch[i][j];
						b[number][i] += 1;
					}
				}
			}else
			{
				int cur_number = 0;
				for (int j=0;j<strlen(ch[i]);j++)
				{
					if (ch[i][j]==a[cur_number])
					{
						b[cur_number][i] += 1;
					}
					else 
					{
						if (j>0 && b[cur_number][i]>0 && a[cur_number+1]==ch[i][j])
						{
							cur_number++;
							b[cur_number][i] += 1;
						}
						else
						{
							fail_flag = true;
							break;
						}
					}
				}
				if (fail_flag ||(cur_number!=(number)))
				{
					fail_flag = true;
					break;
				}
			}
		}
		if (fail_flag)
		{
			ofile<<"Case #"<<iT<<": Fegla Won"<<endl;
		}
		else
		{
			int count = 0;
			for (int i=0;i<=number;i++)
			{
				qsort(b[i],N,sizeof(int),compare);
				int idx = floor(1.0f*(N-1)/2);
				int med = b[i][idx];

				for (int j=0;j<N;j++)
				{
					count += abs(b[i][j]-med);
				}

			}
			ofile<<"Case #"<<iT<<": "<<count<<endl;
		}
	}
	ifile.close();
	ofile.close();
	system("pause");
}