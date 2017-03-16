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

	ifstream fin("A-large.in");
	ofstream fout("output.out");


	int T;
	fin>>T;

	for (int cnt=1; cnt<=T; cnt++)
	{
		int N;
		fin>>N;
		
		int *mushroom=new int [N];
		for (int i=0; i<N; i++)
			fin>>mushroom[i];
		int sum1=0;
		for (int i=0; i<N-1; i++)
		{
			if (mushroom[i]>mushroom[i+1])
				sum1=sum1+mushroom[i]-mushroom[i+1];
		}

		int max_reduce=0;
		for (int i=0; i<N-1; i++)
		{
			if (mushroom[i]>mushroom[i+1] && (mushroom[i]-mushroom[i+1]>max_reduce) )
				max_reduce=mushroom[i]-mushroom[i+1];
		}
		int sum2=0;
		for (int i=0; i<N-1; i++)
		{
			if (mushroom[i]>max_reduce)
				sum2=sum2+max_reduce;
			else
			{
				sum2=sum2+mushroom[i];
			}
		}

		fout<<"Case #"<<cnt<<": "<<sum1<<" "<<sum2<<endl;
	}
			

	


	system("pause");
}

