#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	for(int a=0; a<tests; a++)
	{
		int qty;
		long long place;
		cin >> qty >> place;
		vector<long long> minutes(qty, 0LL);
		for(int i=0; i<qty; i++)
		{
			cin >> minutes[i];
		}

		long long worst = 200000000000000LL;
		long long low = 0LL;
		vector<pair<long long,pair<long long,long long>>> barbers;
		for(int i=0; i<qty; i++)
		{
			barbers.push_back(make_pair(0LL, make_pair(1LL + i, (long long)minutes[i])));
		}

		long long at = 100000000000000LL;
		long long lastAt = 0LL;
		while(at != lastAt)
		{
//			cout << "Trying: " << at << endl;
			long long served = 0;
			for(int i=0; i<qty; i++)
			{
				served += at / barbers[i].second.second;
			}

			lastAt = at;
			if((served <= (place - 1)) && (served >= (place - (5*qty))))
			{
				break;
			}
			else if(served < (place - 1))
			{
				low = at;
				at = (worst + at) / 2LL;
			}
			else
			{
				worst = at;
				at = (at + low) / 2LL;
			}
		}

		at -= 200000LL;

//		while(place > 1)
//		{
//			barbers[0].first += barbers[0].second.second;
//			place--;
//			sort(barbers.begin(), barbers.end());
//		}
//		long long over = 1000000LL;
//		for(int i=0; i<qty; i++)
//		{
//			long long need = barbers[i].second.second;
//			long long overage = at % need;
//			over = min(over, overage);
//		}

//		at -= over;
		long long served = 0;
		for(int i=0; i<qty; i++)
		{
			long long need = barbers[i].second.second;
			served += at / need;
			barbers[i].first = (at / need) * need;
		}
		place -= served;

		sort(barbers.begin(), barbers.end());
//		int ans = barbers[0].second.first;
//		long long ans = at - over;
//		if(((place - 1) >= qty) || ((place - 1) < 0))
//		{
//			cout << "Error error error" << endl;
//		}
		cerr << "For case: " << (a+1) << ": Served: " << served << " at time: " << at << endl;

		while(place > 1)
		{
			barbers[0].first += barbers[0].second.second;
			place--;
			sort(barbers.begin(), barbers.end());
		}

/*
		vector<int> poss;
		for(int i=0; i<qty; i++)
		{
			if(barbers[i].first <= at)
			{
				poss.push_back(barbers[i].second.first);
			}
		}
		sort(poss.begin(), poss.end());
*/
		int ans = barbers[place-1].second.first;
		cerr << "Barber[" << (place-1) << "] of speed: " << barbers[place-1].second.second << endl;
//		int ans = poss[place-1];
//		cout << "Time of service: " << at << endl;
		cout << "Case #" << (a+1) << ": " << ans << endl;
	}

	return 0;
}
