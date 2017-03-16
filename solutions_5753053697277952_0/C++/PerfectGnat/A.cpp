#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{int num;
	char nome;
} miotipo;

int somma(vector<miotipo> v)
{
	int res = 0;
	for (vector<miotipo>::iterator ii = v.begin(); ii!=v.end(); ii++)
	if (ii->num != 0) res++;
	return res;
}


bool myfunction (miotipo a, miotipo b) {return a.num>b.num;}

int main()
{
	ifstream myfile;
	//myfile.open("testA.in");
	myfile.open("A-small-attempt0.in");
	
	int T;
	myfile >> T;
	
	for (int t=0; t<T; t++)
	{
		int N;
		
		myfile >> N;
		cout << "Case #" << t+1 << ":";
		
		vector <miotipo> p;
		
		for (int n=0; n<N; n++)
		{
			miotipo temp;
			myfile >> temp.num;
			temp.nome = 'A'+n;
			p.push_back(temp);
		}
		
		// for (int i=0; i<N; i++)
		// cout << p[i].nome;
		
		sort(p.begin(),p.end(),myfunction);

		// for (int i=0; i<N; i++)
		// cout << p[i].nome;		
		
		int changed = 1;
		while (changed)
		{
			changed = 0;
			for (int i = 0; !changed && i<N-1; i++)
			if (p[i].num>p[i+1].num)
			{
				cout << " " << p[i].nome;
				p[i].num--;
				changed = 1;
			}
		}	
		
		int s = somma (p);
		while (s!=0)
		{
			//cout << "s vale" << s; getchar();
			cout << " " << p[0].nome;
			p[0].num--;
			
			if (s%2 == 0)
			{
				cout << p[1].nome;
				p[1].num--;
			}
			sort(p.begin(),p.end(),myfunction);
			s = somma(p);
		}
		
		cout << endl;

	}
}
