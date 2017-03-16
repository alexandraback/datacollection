#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Barber{
	Barber(int id,int work): id(id), next_time(0),work(work){ }
	int id;
	int work;
	int next_time;
	bool operator < (const Barber& b){
		return next_time > b.next_time || (next_time == b.next_time && id > b.id);
	}
};
int m[2000];
vector<Barber> heap;
int main(){
	ifstream inf("B-small-attempt3.in");
	ofstream outf("B-small-attempt3.out");
	int T, N, B;
	inf >> T;
	for (int i = 1; i <= T; i++){
		int l[2000] = { 0 };
		inf >> B >> N;
		for (int j = 1; j <= B; j++){
			inf >> m[j];
		}
		int timespan = 100;
		
		while (true){
			int n = 0;
			for (int j = 1; j <= B; j++){
				int left = timespan - l[j];
				if (left >= 0){
					n += left / m[j];
					//left %= m[j];
					//if (left >= 0) 
					n++;
				}
				//n += (timespan + m[j] - l[j]) / m[j];
			}
			if (n < N){
				N -= n;
				for (int j = 1; j <= B; j++){
					if (timespan < l[j]){
						l[j] -= timespan;
					}
					else{
						l[j] = m[j] - (timespan - l[j]) % m[j];
						if (l[j] == 0)
							l[j] = m[j];
					}
				}
				timespan *= 2;
			}
			else{
				timespan /= 2;
				if (timespan < 100){
					for (int j = 1; j <= B; j++){
						Barber t(j,m[j]);
						t.next_time = l[j];
						heap.push_back(t);
					}
					break;
				}
			}
		}
		/*
		for (int j = 1; j <= B; j++){
			Barber t(j, m[j]);
			t.next_time = l[j];
			heap.push_back(t);
		}
		*/
		make_heap(heap.begin(),heap.end());
		for (int j = 1; j < N; j++){
			pop_heap(heap.begin(),heap.end());
			if (heap.back().next_time + heap.back().work <= 0){
				for (int k = 0; k < heap.size(); k++){
					heap[k].next_time -= heap.back().next_time;
				}
			}
			heap.back().next_time += heap.back().work;
			push_heap(heap.begin(), heap.end());
		}
		outf << "Case #" << i << ": " << heap.front().id << endl;
		cout << i;
		heap.clear();
	}


	return 0;
}