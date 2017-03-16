#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
	return (a*b) / gcd(a, b);	
}

struct barberTime
{
	long long num;
	long long time;
	
	/*bool operator()(const barberTime& a, const barberTime& b) const
    	{
        	if (a.time < b.time)
        	{
        		return true;
        	}
        	else if (a.time > b.time)
        	{
        		return false;
        	}
        	else
        	{
        		if (a.num < b.num)
        			return true;
        		else
        			return false;
        	}
    	}*/
    	
    	bool operator <(const barberTime& rhs) const
    	{
        	if (time < rhs.time)
        	{
        		return true;
        	}
        	else if (time > rhs.time)
        	{
        		return false;
        	}
        	else
        	{
        		if (num < rhs.num)
        			return true;
        		else
        			return false;
        	}
    	}
};

int main()
{
	long long t, n, b;
	vector<long long> time;
	vector<long long> cust;
	//multimap<long long, long long> barbers;
	multiset<barberTime> barbers;
	long long doneCust = 0;
	long long lcmTime = 1;
	long long barber;
	long long zero = 0;
	barberTime temp;
	
	cin >> t;
	
	for (int casenum = 1; casenum <= t; casenum++)
	{
		cin >> b >> n;
		time.resize(b+1);
		cust.resize(b+1);
		temp.time = 0;
		for (long long i =1; i <= b; i++)
		{
			cin >> time[i];
			lcmTime = lcm(lcmTime, time[i]);
			//barbers.insert(make_pair(zero, i));
			temp.num = i;
			barbers.insert(temp);
		}
		
		for (long long i = 1; i <= b; i++)
		{
			cust[i] = lcmTime / time[i];
			doneCust += cust[i];
		}
		
		//haven't gotten to me
		if (doneCust < n)
		{
			n = n % doneCust;
			if (n == 0)
				n += doneCust;
		}
		
		//at lcmTime, all barbers are done (at the same time!)
		/*cout << "lcm " << lcmTime << endl;
		cout << "done " << doneCust << endl;
		cout << "remaining " << n << endl;*/
		
		/*cout << barbers.size() << endl;
		for (set<barberTime>::iterator pos = barbers.begin(); pos != barbers.end(); ++pos)
		{
			cout << (*pos).time << " " << (*pos).num << endl;
		}*/
		
		//now have some number of customers in front needing haircuts,
		//and all barbers are available
		for (int i = 1; i <= n-1; i++)	//iterate people in front
		{
		/*cout << barbers.size() << endl;
		for (set<barberTime>::iterator pos = barbers.begin(); pos != barbers.end(); ++pos)
		{
			cout << (*pos).time << " " << (*pos).num << endl;
		}*/
		
		//cout << i << endl;
			multiset<barberTime>::iterator first = barbers.begin();
			temp.num = (*first).num;
			temp.time = (*first).time + time[temp.num];
			//temp.num = first.num;
			//temp.time = first.time + time[temp.num];
			
			barbers.erase(first);
			barbers.insert(temp);
			//barbers.insert(make_pair(firstTime+time[firstNum], firstNum));
		}
		
		//print results
		cout << "Case #" << casenum <<": " << (*barbers.begin()).num;
		cout << endl;
		
		time.clear();
		cust.clear();
		barbers.clear();
		lcmTime = 1;
		doneCust = 0;
	}
}
