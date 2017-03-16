

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

	//int ans = 0;
	int ans = 0;
	int ans2 =0;

	string temp2, temp3;
	getline (infile, temp2);
	AN(temp2);
	int X = I[1];
	int Y = I[2];
	
	getline (infile, temp2);
	AN(temp2);



	//binarysearch

	long long mintime = 1;
	long long maxtime = 744073709551616;
	
	while(1)
	{
		long long time;
		
			if (maxtime - mintime < 3)
				break;

			if (maxtime < 744073709551616) 
				time = (maxtime + mintime) / 2;
			else
				time = mintime * 10;
		
		long long seen = 0;

		for (int i = 1; i<= X; i++)
		{
			seen += ((time+.05)/(long long)I[i])+1;
		}

		if (seen >= Y)
		{
			if (mintime < 1000)
				break;


			if (maxtime - mintime < 3)
				break;
			//else
			maxtime = time;
			if (mintime > maxtime)
			{
				long long temp = mintime;
				mintime = maxtime;
				maxtime = temp;
			}
		}
		else
		{
			mintime= time;
			if (mintime > maxtime)
			{
				long long temp = mintime;
				mintime = maxtime;
				maxtime = temp;
			}

		}

	}

	long long time = mintime-2;

	while (1)
	{
		time++;
		long long seen = 0;
		// loop thru barbers



		for (int i = 1; i<= X; i++)
		{
			seen += (time-1+.05)/((long long)I[i]) + 1;
			if (seen >= Y)
			{
				cout << "Case #" << t << ": " << i  ;
				cout << endl;	
				return;
			}

		}

		for (int i = 1; i<= X; i++)
		{
			if (time % I[i] == 0)
				seen += 1;
			if (seen >= Y)
			{
				cout << "Case #" << t << ": " << i  ;
				cout << endl;	
				return;
			}
		}


	}
}


int main(void){


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

