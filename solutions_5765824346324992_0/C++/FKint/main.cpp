#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

unsigned long long kgv(unsigned long long a, unsigned long long b){
	return a*b/gcd(a, b);
}
unsigned long long kgv(vector<unsigned long long> v){
	unsigned long long k = 1;
	for(vector<unsigned long long>::iterator it = v.begin(); it != v.end(); ++it){
		k = kgv(k, *it);
	}
	return k;
}


struct barber_ready{
	int barber;
	unsigned long long time;
	barber_ready(int barber, unsigned long long time){
		this->barber = barber;
		this->time = time;
	}
	bool operator<(const barber_ready &b) const{
		if(this->time != b.time){
			return this->time > b.time;
		}
		return this->barber > b.barber;
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	int nb_testcases; cin >> nb_testcases;
	for(int current_case = 1; current_case <= nb_testcases; ++current_case){
		unsigned long long N;
		int B;
		cin >> B >> N;
		vector<unsigned long long> barbers;
		for(int i = 0; i < B; ++i){
			unsigned long long T;
			cin >> T;
			barbers.push_back(T);
		}

		unsigned long long k = kgv(barbers);

		unsigned long long processed_per_cycle = 0;
		for(vector<unsigned long long>::iterator it = barbers.begin(); it != barbers.end(); ++it){
			processed_per_cycle += k/(*it);
		}
		N %= processed_per_cycle;
		if(N == 0)
			N = processed_per_cycle;

		priority_queue<barber_ready> pq;
		for(int i = 0; i < B; ++i){
			pq.push(barber_ready(i, 0));
		}

		unsigned long long nb_processed = 0;
		int result = 0;
		while(nb_processed < N){
			nb_processed++;
			barber_ready t = pq.top();
			pq.pop();
			if(nb_processed == N){
				result = t.barber;
				break;
			}
			pq.push(barber_ready(t.barber, t.time + barbers[t.barber]));
		}

		cout << "Case #" << current_case << ": " << result + 1;

		cout << endl;
	}
    return 0;
}
