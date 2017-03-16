#include <iostream>
#include <vector>
using namespace std;



int firstMethod(const vector<int>& cases)
{
	if(cases.size() == 0) return 0;
	int prev = cases[0];
	int current;
	int eaten = 0;


	for(int i=1; i<cases.size(); ++i)
	{
		current = cases[i];
		if(current < prev)
		{
			eaten += (current - prev);
		}
		prev = current;
	}
	return eaten*-1;
}

int secondMethod(const vector<int>& cases)
{
	int prev = cases[0];
	int current,diff,maxDiff = 0;
	for(int i=1; i<cases.size(); ++i)
	{
		current = cases[i];
		diff = prev - current;
		if (diff> maxDiff)
		{
			maxDiff = diff;
		}
		prev = current;
	}
	int eaten = 0;
	for(int i=0; i<cases.size()-1; ++i)
	{
		if(cases[i] <= maxDiff){
			eaten += cases[i];
		}
		else
		{
			eaten += maxDiff;
		}

	}
	return eaten;
}


void calculate(const vector<int>& cases, int& y, int&z)
{
	y = firstMethod(cases);
	z = secondMethod(cases);

}

int main(){
	int n;
	cin >> n;
	
	for(int i=0; i<n; ++i)
	{
		int c;
		cin >> c;
		vector<int>  cases(c);
		for(int i=0; i<c; i++){
			cin >> cases[i];
		}

		int y,z;
		calculate(cases,y,z);
		cout << "Case #" << i+1 << ": " << y << " " << z << endl;
	
	}
	return 0;
}