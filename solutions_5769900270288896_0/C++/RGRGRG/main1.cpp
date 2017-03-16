

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
long int I[2001];
double D[101];
int ANS[1000001];

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
void main3(int t)
{
		myfile << t << " " << ANS[t];	
		myfile << endl;	
}

int powRG(int a, int b)
{
	int ans = 1;
	for (int i = 1; i <= b; i++)
	{
		ans = ans*2;
	}
	return ans;
}


void main2(int t)
{



	string temp2, temp3;
	getline (infile, temp2);
	AN(temp2);

	int X = I[1];
	int Y = I[2];
	int Z = I[3];

	if (X > Y)
	{
		int temp = X;
		X = Y;
		Y = temp;
	}

	int minx = 9999;

	if (Z <= 1)
	{
			myfile << "Case #" << t << ": " << 0 ;
	myfile << endl;	
	return;

	}


	
	for (int z = 0; z<= 70000; z++)
{
	int on[16][16];
		int count = 0;

	for (int x = 0; x< X; x++){
		for (int y = 0; y< Y; y++)
		{
				on[x][y] =  z / powRG(2,x+(y-1)*X+1);
				on[x][y] =  (on[x][y] + powRG(2,x+(y-1)*X-1) / powRG(2,x+(y-1)*X));


				if (on[x][y])
					count++;
		}
	}

	if (count == Z)
	{
		int countT = 0;

		for (int x = 0; x<= X-1; x++){
			for (int y = 0; y<= Y-1; y++)
			{
					if (x < X-1)
						if (on[x][y]&& on[x+1][y])
						countT++;
					if (y < Y-1)
					if (on[x][y] && on[x][y+1])
						countT++;
			}
		}

		if (countT <= minx)
			minx = countT;


	}

}

	myfile << "Case #" << t << ": " << minx ;
	myfile << endl;	

}


int main(void){

	 
	myfile.open ("RGoutput.txt");
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

