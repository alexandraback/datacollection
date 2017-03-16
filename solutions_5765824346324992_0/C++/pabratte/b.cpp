#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <numeric>
	
using namespace std;
	int gcd(int a, int b)
	{
		for (;;)
		{
			if (a == 0) return b;
			b %= a;
			if (b == 0) return a;
			a %= b;
		}
	}

int lcm(int a, int b)
{
	int temp = gcd(a, b);
	
	return temp ? (a / temp * b) : 0;
}

int main(int argc, char *argv[]) {
	int nTestCases;
	//auto &input = cin;
	ifstream input("B-small-attempt1.in");
	ofstream output("B-small-attempt1.out");
	
	input>>nTestCases;
	int B, N;
	
	
	
	for(int i = 0; i < nTestCases; i++){
		cout<<"Case #"<<i+1<<endl;
		input>>B>>N;
		vector<int> M(B, 0);
		vector<int> Barbers(B, 0);
		int clientsAttended = 0;
		
		
		int mult = 1;
		int multClients = 0;
		for(int k=0; k<B; k++){
			input>>M[k];
			Barbers[k]=0;
			mult *= M[k];
		}
		for(int k=0; k<B; k++){
			multClients += mult/M[k];
		}
		
		while(N>multClients){
			N-=multClients;
		}
		
		int lastBarber = 0;
		while(clientsAttended < N){
			//
			for(int k=0; k<B; k++){
				if(Barbers[k]==0){
				//	cout<<"Attending "<<clientsAttended<<" on barber "<<k<<endl;
					Barbers[k]+=M[k];
					clientsAttended++;
					lastBarber = k+1;
					if(clientsAttended >= N) break;
				}
			}
			
			for(int k=0; k<B; k++){
				if(Barbers[k]>0) Barbers[k] = Barbers[k] - 1;
			}
		}
		output<<"Case #"<<i+1<<": "<<lastBarber<<endl;
//		cout<<"===================="<<endl;
		
	}
	
	
	
	return 0;
}

