#include <iostream>
#include <limits>
#include <cstdio>
#include <queue>
using namespace std;
struct Partito{
	int senatori;
	char lettera;
	
	bool operator<(const Partito& b) const{
		if(senatori < b.senatori) return true;
		else return false;
	}
};
int main(int argc, char **argv)
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	
	int times;
	cin >> times;
	for(int t = 1; t <= times; t++){
		priority_queue<Partito> q;
		int n;
		cin >> n;
		int total = 0;
		for(int i = 0; i < n; i++){
			Partito t;
			t.lettera = i + 'A';
			cin >> t.senatori;
			total += t.senatori;
			q.push(t);
		}
		cout << "Case #" << t << ": ";
		while(q.top().senatori > 0){
			Partito p1, p2;
			p1 = q.top();
			q.pop();
			p2 = q.top();
			q.pop();
			if((total-1)/2 < p2.senatori){
				cout << p1.lettera << p2.lettera << " ";
				p1.senatori--;
				p2.senatori--;
				q.push(p1);
				q.push(p2);
				total -= 2;
			}else if((total-2)/2 < p2.senatori || p1.senatori == 1){
				cout << p1.lettera << " ";
				p1.senatori--;
				q.push(p1);
				q.push(p2);
				total--;
			}else {
				cout << p1.lettera << p1.lettera << " ";
				p1.senatori -= 2;
				q.push(p1);
				q.push(p2);
				total -= 2;
			}
			
		}
		cout << endl;
			
	}
	return 0;
}

