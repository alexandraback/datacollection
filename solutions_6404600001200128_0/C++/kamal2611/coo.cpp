/*
ID: k.kamal1
PROG: test
LANG: C++     
*/
#include <bits/stdc++.h>

using namespace std;

long long arr[1005];


long long get5(int cnm)
{
	long long ret = 0;
	for(int ct = 1; ct < cnm; ct++)
	{
		if(arr[ct] < arr[ct-1])
		ret += arr[ct-1] - arr[ct];
	}
	
	return ret;
}


long long get7(int cnm)
{
	long long rt = 0;
	for(int ct = 0; ct < cnm; ct++)
	{
		arr[ct] *= 10;
	}
	
	long long mxRat = 0;
	for(int ct = 1; ct < cnm; ct++)
	{
		if(arr[ct] < arr[ct-1])
		{
			mxRat = max(mxRat , ( (arr[ct-1] - arr[ct]) / 10  ));
		}
	}
	
	for(int ct = 1; ct < cnm; ct++)
	{
		rt += min(arr[ct-1] , 10*mxRat);
	//	cout << 10*mxRat << endl;
	}
//	cout << rt << " ret " << endl;
	return rt;
}

int main() {
    ofstream fout ("o.out");
    ifstream fin ("in.in");
    int tetC;
    fin >> tetC;
    for(int cnt = 0; cnt < tetC; cnt++)
    {
    	int num;
    	fin >> num;
    	for(int ct = 0; ct < num; ct++)
    	{
    		fin >> arr[ct];
    	}
    	
    	long long c5 = get5(num);
    	long long c7 = get7(num);
    	//long long ret = c5+c7;
    	fout << "Case #" << cnt+1 << ": " << c5 << " " << c7/10 << endl; 
     }
    return 0;
}

