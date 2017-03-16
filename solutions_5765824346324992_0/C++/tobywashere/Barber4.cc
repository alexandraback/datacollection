#include <iostream>
#include <vector>

using namespace std;

struct Barber
{
    int speed;
    int numServe;
    int finish;
};

int main()
{
    int numCases;
    cin >> numCases;
    for (int c = 1; c <= numCases; c++)
    {
	int numBarbers;
	cin >> numBarbers;
	long long n;
	cin >> n;
	vector<Barber> barbers(numBarbers);
	int prod = 1;
	for (int i = 0; i < numBarbers; i++)
	{
	    cin >> barbers[i].speed;
	    prod *= barbers[i].speed;
	    barbers[i].finish = 0;
	}  
	int total = 0;
	for (int i = 0; i < numBarbers; i++)
	{
	    barbers[i].numServe = prod/barbers[i].speed;
	    total += barbers[i].numServe;
	}
	//cout << "total: " << total << endl;
	if (n % total != 0)
	{
	    n = n % total;
	}
	else
	{
	    n = total;
	}
	int minBarber;
	while (n > 0)
	{
	    int minFinish = barbers[0].finish;
	    minBarber = 0;
	    for (int i = 1; i < numBarbers; i++)
	    {
		if (barbers[i].finish < minFinish)
		{
		    minFinish = barbers[i].finish;
		    minBarber = i;
		}
	    }
	    barbers[minBarber].finish += barbers[minBarber].speed;
	    n--;
	}
	cout << "Case #" << c << ": " << (minBarber + 1) << endl;
    }
}
