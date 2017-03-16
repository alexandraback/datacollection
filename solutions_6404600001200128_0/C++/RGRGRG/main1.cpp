

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
	//int Z = I[3];
	
	getline (infile, temp2);
	AN(temp2);

	for (int i = 2; i<= X; i++)
	{
		if (I[i] < I[i-1])
			ans+= ( I[i-1] - I[i]);
	}


	int max = 0;

	// find fastest rate
	for (int i = 2; i<= X; i++)
	{
		if ( I[i-1] > I[i])
		{
			if (I[i-1] - I[i] > max)
				max = I[i-1] - I[i];
		}
	}

	for (int i = 1; i<= X-1; i++)
	{
		if (I[i] < max)
			ans2+= (I[i]);
		else
			ans2+= max;
	}




	cout << "Case #" << t << ": " << ans << " " << ans2 ;
	cout << endl;	
	return;


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

