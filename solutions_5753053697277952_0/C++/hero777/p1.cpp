#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include <algorithm>


using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main ()
{
	ifstream input;
	ofstream output;
	input.open("in.txt");
	output.open("out.txt");
	int test,tests;
	input >> tests;
	//printf("%d", tests);
	for (int test = 0; test < tests; test++)
	{	
		output << "Case #"<< test+1 << ": " ;
		int num;
		input >>  num;
		int party[num];
		forn(i, num)
			input >> party[i];
		int curr = 0;
		forn(i, num)
			curr += party[i];
		printf("%d\n", curr);
		while(curr > 0)
		{
			
			int maxi = 0;
			int maxin = 0;
			forn(i, num)
			{
				if (party[i] > maxi)
				{				
					maxi = max(maxi, party[i]);
					maxin = i;
				}
			}
			char a = 'A' + maxin;
			if (maxi > 2)
			{
				
				curr -= 1;
				party[maxin] -=1;
				output << a;
				forn(i, num)
							if(i != maxin)
								if (party[i] == maxi)
								{
									char b = 'A' + i;
									output << b << " ";
									curr-=1;
									party[i]-=1;
									break;
								}
				output << " ";
				
			}	
			else
			{
				if (maxi == 2)
				{
					if (curr == 4)
					{
						output << a;
						curr -=1;
						party[maxin] -=1;
						forn(i, num)
							if(i != maxin)
								if (party[i] > 0)
								{
									char b = 'A' + i;
									output << b << " ";
									curr-=1;
									party[i]-=1;
									break;
								}
					
					}
					else
					{
						curr -= 1;
						party[maxin] -=1;
						output << a << " ";
					}
					
					
				}
				else 
				{
					if (curr > 2)
					{
						curr -= 1;
						party[maxin] -=1;
						output << a << " ";
					}
					else
					{
						output << a;
						curr -=1;
						party[maxin] -=1;
						forn(i, num)
							if(i != maxin)
								if (party[i] > 0)
								{
									char b = 'A' + i;
									output << b << " ";
									curr-=1;
									party[i]-=1;
									break;
								}
					
					
					}
				}
			}
		}		
		output << "\n";
		
	}
}	



