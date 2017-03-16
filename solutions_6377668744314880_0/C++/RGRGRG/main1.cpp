

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cfloat>
#include <cstdint> 

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,n) for((i)=1;(i)<=(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define INF 1.0E+15

ifstream infile;

string S[101];
int I[2001];
double D[101];

int pos = 1;

ofstream myfile;

void AN(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 2000; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 I[i] = atoi(s.substr(last+1).c_str());
			 return;
		 }
		 I[i] = atoi(s.substr(last+1,pos-last-1).c_str());
		 last = pos;
	}
	return;
}

void AN2(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 2000; i++)
	{
		 pos = s.find("/",last+1);
		 if (pos == std::string::npos)
		 {
			 I[i] = atoi(s.substr(last+1).c_str());
			 return;
		 }
		 I[i] = atoi(s.substr(last+1,pos-last-1).c_str());
		 last = pos;
	}
	return;
}

void AS(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 100; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 S[i] = s.substr(last+1);
			 return;
		 }
		 S[i] = s.substr(last+1,pos-last-1);
		 last = pos;
	}
	return;
}

void AD(string s){
	unsigned pos;
	int last = -1;
	for (int i = 1; i<= 100; i++)
	{
		 pos = s.find(" ",last+1);
		 if (pos == std::string::npos)
		 {
			 D[i] = atof(s.substr(last+1).c_str());
			 return;
		 }
		 D[i] = atof(s.substr(last+1,pos-last-1).c_str());
		 last = pos;
	}
	return;
}



void main2(int t)
{



	string temp2, temp3;
	getline (infile, temp2);
	AN(temp2);

	int X = I[1];

	double Xunit[20];
	double Yunit[20];

	for (int i = 1; i<= X; i++)
	{
		getline (infile, temp2);
		AD(temp2);
		Xunit[i] = D[1];
		Yunit[i] = D[2];
	}

	myfile << "Case #" << t << ": "   ;
	myfile << endl;	

	

	for (int i = 1; i<= X; i++)
	{
		int bestmin = X-1;

		for (int j= 1; j<= X; j++)
		{
			if (i != j)
			{
				// learn X delta
				double Xdelta = Xunit[j] - Xunit[i];
				double Ydelta = Yunit[j] - Yunit[i];

					int LOWcounter = 0;
					int HIGHcounter = 0;

				if (Xdelta == 0.0)
				{

					for (int k = 1; k<= X; k++)
					{
						if (Xunit[i] < Xunit[k] )
							LOWcounter++;
						else if (Xunit[i] > Xunit[k])
							HIGHcounter++;
					}

				}

				else
				{
					double m = Ydelta/Xdelta;
					double b = Yunit[j] - m * Xunit[j];

					// loop thru and find differences
					for (int k = 1; k<= X; k++)
					{
						if (Yunit[k] < m*Xunit[k] + b)
							LOWcounter++;
						else if (Yunit[k] > m*Xunit[k] + b)
							HIGHcounter++;
					}
				}


				if (HIGHcounter > LOWcounter)
					HIGHcounter = LOWcounter;

				if (HIGHcounter < bestmin)
					 bestmin = HIGHcounter;

			}

		}
		myfile << bestmin;	
		myfile << endl;	
	}

}


int main(void){

	 
	 myfile.open ("example.txt");
	int T, t;
	string temp;

	infile.open("inputhere2.txt");
	getline (infile, temp);

	T = atoi(temp.c_str());
	



	for (int t = 1; t<= T; t++)
		main2(t);
	
	infile.close();


	return(0);

}

