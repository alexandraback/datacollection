/*
 * MagicTrick.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: Ganesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#define iter(i, N) for(long long i=0 ; i<N ; i++)

using namespace std;

int main()
{
	long long cases;
	cin>>cases;
	iter(q, cases)
	{
		int r1, r2,x;
		cin>>r1;
		bool done[20];
		iter(i, 20)
			done[i] = false;
		for(int i=0 ; i<4 ; i++)
		{
			for(int j=0 ; j<4 ; j++)
			{
				cin>>x;
				if(i == r1-1)
				done[x] = true;
			}
		}
		int count = 0, val;
		cin>>r2;
		for(int i=0 ; i<4 ; i++)
		{
			for(int j=0 ; j<4 ; j++)
			{
				cin>>x;
				if(i == r2-1)
				{
					if(done[x])
					{
						count++;
						val = x;
					}
				}
			}
		}
		cout<<"Case #"<<q+1<<": ";
		switch(count)
		{
			case 0	:	cout<<"Volunteer cheated!\n";
						break;
			case 1	:	cout<<val<<"\n";
						break;
			default	:	cout<<"Bad magician!\n";
		}
	}
	return 0;
}




