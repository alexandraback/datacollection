#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include<algorithm>
#include <random>
#include<iomanip>


using namespace std;



int main()
{

	/*ifstream fin("input.txt");
	ofstream fout("output.txt");*/

	ifstream fin("B-small-attempt1.in");
	ofstream fout("output.out");


	int T;
	fin>>T;

	for (int cnt=1; cnt<=T; cnt++)
	{
		int B,N;
		fin>>B>>N;

		int *B_time=new int [B];
		for (int i=0; i<B; i++)
			fin>>B_time[i];

		int *B_cost_time=new int [B];
		for (int i=0; i<B; i++)
			B_cost_time[i]=0;
		int *B_index=new int [B];
		for (int i=0; i<B; i++)
			B_index[i]=i;

		int min_m=1;
		int flag=true;
		while (flag)
		{
			flag=false;
			for (int i=0; i<B; i++)
			{
				if (min_m%B_time[i]!=0)
				{
					flag=true;
					min_m++;
					break;
				}
			}
		}

		
		int num_per=0;
		for (int i=0; i<B; i++)
			num_per+=min_m/B_time[i];
		/*cout<<min_m<<endl;
		cout<<num_per<<endl;*/

		if (N>num_per)
		{
			if (N%num_per==0)
				N=num_per;
			else
				N=N%num_per;
		}

		//cout<<cnt<<" "<<N<<endl;

		for (int i=1; i<=N-1; i++)
		{
			B_cost_time[B_index[0]]+=B_time[B_index[0]];
			for (int i=1; i<B; i++)
			{
				if (B_cost_time[B_index[i-1]]>B_cost_time[B_index[i]])
				{
					int temp_index=B_index[i-1];
					B_index[i-1]=B_index[i];
					B_index[i]=temp_index;
				}
				else
				{
					if (B_cost_time[B_index[i-1]]==B_cost_time[B_index[i]] && B_index[i-1]>B_index[i])
					{
						int temp_index=B_index[i-1];
						B_index[i-1]=B_index[i];
						B_index[i]=temp_index;
					}
				}
			}
		}
		fout<<"Case #"<<cnt<<": "<<B_index[0]+1<<endl;

		delete []B_time;
		delete []B_cost_time;
		delete []B_index;
	}
			

	


	system("pause");
}

