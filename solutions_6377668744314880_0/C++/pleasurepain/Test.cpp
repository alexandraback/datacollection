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

	ifstream fin("C-small-attempt2.in");
	ofstream fout("output.out");


	int T;
	fin>>T;

	for (int cnt=1; cnt<=T; cnt++)
	{
		int N;
		fin>>N;
		int *x_label=new int [N];
		int *y_label=new int [N];

		for (int i=0; i<N; i++)
		{
			fin>>x_label[i]>>y_label[i];
		}

		/*for (int i=0; i<N; i++)
			cout<<x_label[i]<<" "<<y_label[i]<<endl;*/
		

		

		fout<<"Case #"<<cnt<<":"<<endl;

		for (int i=0; i<N; i++)
		{
			int global_min=100;
			for (int j=0; j<N; j++)
			{
				if (j!=i)
				{
					if (x_label[i]!=x_label[j])
					{
						int numl=0;
						int numr=0;
						for (int k=0; k<N; k++)
						{
							int result=(y_label[j]-y_label[i])*(x_label[k]-x_label[i])+(y_label[i]-y_label[k])*(x_label[j]-x_label[i]);
							if (result>0)
								numr++;
							if (result<0)
								numl++;
							/*if (y_label[j]==y_label[i])
							{
								if (y_label[i]-y_label[k]>0)
									numr++;
								if (y_label[i]-y_label[k]<0)
									numl++;
							}
							else
							{
								double result=1.0*(y_label[j]-y_label[i])*(x_label[k]-x_label[i])/(x_label[j]-x_label[i])+y_label[i];
								if (result-y_label[k]>0)
									numr++;
								if (result-y_label[k]<0)
									numl++;
							}*/
						}
						if (numr<global_min)
							global_min=numr;
						if (numl<global_min)
							global_min=numl;
					}
					else
					{
						int numl=0;
						int numr=0;
						for (int k=0; k<N; k++)
						{
							if (x_label[k]>x_label[i])
								numr++;
							if (x_label[k]<x_label[i])
								numl++;
						}
						if (numr<global_min)
							global_min=numr;
						if (numl<global_min)
							global_min=numl;
					}
				}
			}
			if (N!=1)
				fout<<global_min<<endl;
			else
				fout<<"0"<<endl;
		}

		
		
			delete []x_label;
			delete []y_label;

	}
			

	


	system("pause");
}

