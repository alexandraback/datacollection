#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
typedef pair<int,int> ii;
typedef pair<int, ii> iii; // time, ID, time taken to cut
ll gcd(ll a, ll b){ return b==0? a: gcd(b, a%b); }
ll lcm(ll a, ll b){ return a * (b / gcd(a,b)); }

int main(){
	ios_base::sync_with_stdio(0);
	
	ifstream cin;
	cin.open("input.in");
	ofstream cout;
	cout.open("output.o");
	
	int t; cin >> t;
	for(int a = 1; a <= t; a++){
		ll b, n; cin >> b >> n;
		ll barber[b];
		for(int i = 0; i < b; i++) cin >> barber[i];
		if(b==1){
			cout << "Case #" << a << ": 1\n"; 
			continue;
		}
		ll lcmll = lcm(barber[0], barber[1]);
		for(int i = 2; i < b; i++){
			lcmll = lcm(lcmll, barber[i]);
		}
		int lcmcut = 0;
		for(int i = 0; i < b; i++){
			lcmcut += lcmll / barber[i];
		}
		//cout << "lcm is " << lcmll << endl;
		n %= lcmcut;
		if(n==0) n = lcmcut;
		// brute force the remaining
		priority_queue<iii, vector<iii>, greater<iii> > pq;
		for(int i = 0; i < b; i++){
			pq.push(mp(0, mp(i+1, barber[i])));	
		}		
		while(true){
			iii front = pq.top(); pq.pop();
			//cout << front.first << " " << front.second.first << " " << front.second.second << endl;
			if(n==1){
				cout << "Case #" << a << ": " << front.second.first << "\n";
				break;
			}
			front.first += front.second.second;
			pq.push(front);
			n--;
		}
	}
/*
10
5 100
5 5 5 5 5

*/	
}
