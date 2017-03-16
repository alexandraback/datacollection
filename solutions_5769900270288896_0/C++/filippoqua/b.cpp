#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <fstream>
#include <climits>
#include <iostream>
#include <queue>
#define ii pair<int,int>
#define ll long long

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

ll n,r,c;
bool tabella[16][16];

int testa()
{
	int count  = 0;
	count =0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			if(tabella[i][j])
			{
				if(i<r-1 && tabella[i+1][j])
					count++;
				if(j<c-1 && tabella[i][j+1])	
					count++;
			}
		}
	return count;
}

int go(int riga, int colonna, int rimanenti)
{
	int tes;
	if(riga==r-1 && colonna==c-1)
	{
		if(rimanenti == 0)
			return testa();
		else if(rimanenti == 1)
		{
			tabella[riga][colonna]=true;
			tes = testa();
			tabella[riga][colonna]=false;
			return tes;
		}
		else
			return INT_MAX;
	}
	else if(colonna==c-1)
	{
		tes = go(riga+1,0,rimanenti);
		tabella[riga][colonna]=true;
		tes = min(tes,go(riga+1,0,rimanenti-1));
		tabella[riga][colonna]=false;
		return tes;
	}
	else
	{
		tes = go(riga,colonna+1,rimanenti);
		tabella[riga][colonna]=true;
		tes = min(tes,go(riga,colonna+1,rimanenti-1));
		tabella[riga][colonna]=false;
		return tes;
	}
}

int main()
{
	int t;
	
	in >> t;
	for(int i=0; i<t; i++)
	{
		for(int j=0; j<16; j++)
			for(int k=0; k<16; k++)
				tabella[j][k]=false;
		
		in >> r >> c >> n;
		
		out << "Case #" << i+1 << ": " << go(0,0,n) << endl;
	}
	return 0;
}

