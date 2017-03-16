#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test()
{
	ll n, b;
	cin >> b >> n;
	
	vector<int> data(b+1);
	for (size_t i = 1; i<=b; i++)
		cin >> data[i];
		
	ll low = 0;
	ll high = n*1000000;
	
	while (low <= high)
	{
		ll test = (high+low)/2;
		//cerr << "Testing " << test << " (" << low << " - " << high << ")" << endl;
		
		ll already_finished = 0;
		ll ongoing = 0;
		vector<int> beginning_barbers;
		for (size_t i = 1; i <=b; i++)
		{
			//cerr << "#"<<i << " already_finished " << (test/data[i]) << " at time " << test << endl;
			already_finished += test / data[i];
			if (test % data[i] == 0)
			{
				beginning_barbers.push_back(i);
			}
			else
			{
				ongoing++;
			}
		}
		
		//cerr << "beginning=" << beginning_barbers.size() << ", ongoing = " << ongoing << endl;
		
		ll low_bound_starting_clients = already_finished + ongoing +1;
		ll upp_bound_starting_clients = low_bound_starting_clients + beginning_barbers.size();
		
		//cerr << "Possible range: [" << low_bound_starting_clients << "; " << upp_bound_starting_clients << ")" << " where is n = " << n << endl;
		if(n >= upp_bound_starting_clients)
		{
			low = test+1;
			continue;
		}
		else if(n < low_bound_starting_clients)
		{
			high = test-1;
			continue;
		}
		else
		{
			cout << beginning_barbers[n - low_bound_starting_clients];
			break;
		}
	}
}

int main()
{
	size_t c;
	std::cin >> c;
	for (size_t i = 1; i<=c; ++i)
	{
		std::cout << "Case #" << i << ": ";
		test();
		std::cout << std::endl;
	}
}
