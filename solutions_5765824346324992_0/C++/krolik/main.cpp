#include <iostream> 
#include <fstream> 
#include <vector>

using namespace std;


bool allEqual(vector<long> b, int B){
	for(int i = 0; i < B - 1; i++)
		if(b[i] != b[i + 1])
			return false;
	
	return true;
}

int indexMin(vector<long> b, int B){
	int index = 0;
	
	for(int i = 1; i < B; i++)
		if(b[index] > b[i])
			index = i;
	
	return index;	
}

vector<int> NWW(vector<long> b, int B){
	vector<long> temp;
	vector<int> order;

	for(int i = 0; i < B; i++){
		order.push_back(i);
		temp.push_back(b[i]);
	}
		
	while(!allEqual(temp, B)){
		int index = indexMin(temp, B);
		temp[index] += b[index];
		order.push_back(index);
	}
	
	return order;
}

int main() {	
	ifstream input("B-small-attempt0.in");
	ofstream output("output.ou");

	int sets, n;
	
	if(input.is_open()){
		input >> sets;
		n = 1;
		
		while(sets > 0){
		
			int temp;
			long B, N;
			vector<long> b;
		
			input >> B >> N;
			for(int i = 0; i < B; i++){
				input >> temp;
				b.push_back(temp);
			}
			
			vector<int> order = NWW(b, B);
			
			output << "Case #" << n << ": " << order[(N - 1) % order.size()] + 1 << "\n";
			
		
		
			sets--;
			n++;
		}
		
		input.close();
		output.close();
	}
	
	return 0; 
}
