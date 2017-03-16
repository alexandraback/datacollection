// CodeJam.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<set>

using namespace std;

int main()
{
	int cases = 0;
	set<int> myset;
	set<int> myset_e;

	cin >> cases;

	for(int n = 1 ; n<=cases ; ++n)
	{
		cout << "Case #" << n << ": ";

		int line = 0;
		int num[16] = {0};
		cin >> line;
		for(int i=0; i<16; ++i){ cin >> num[i];}

		myset.insert( num[(line-1)*4]);
		myset.insert( num[(line-1)*4+1]);
		myset.insert( num[(line-1)*4+2]);
		myset.insert( num[(line-1)*4+3]);

		cin >> line;
		for(int i=0; i<16; ++i){ cin >> num[i];}
		
		for(int i=0; i<4 ; ++i)
		{
			if(myset.find(num[(line-1)*4+i])!=myset.end())
			{
				myset_e.insert(num[(line-1)*4+i]);
			}
		}
		
		if(myset_e.size() == 1)
		{
			cout << *(myset_e.begin()) << endl;
		}
		else if(myset_e.size() == 0)
		{
			cout << "Volunteer cheated!" << endl;
		}
		else
		{
			cout << "Bad magician!" << endl;
		}
		myset.clear();
		myset_e.clear();
	}
	return 0;
}

