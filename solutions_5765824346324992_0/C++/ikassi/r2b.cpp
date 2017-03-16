#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd ( int a, int b )
{
	int c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

int lcmV(int a,const vector<int>& v, int index)
{
	if (index == v.size()-1)
	{
		return lcm(a,v[index]);
	}
	return lcm(a,lcmV(v[index],v,index+1));
}

int fullRotation(const vector<int>& v){
	int lcml =  lcmV(v[0],v,1);
	int fr  = 0;
	for(int i =0; i<v.size(); ++i)
	{
		fr += (lcml/v[i]);
	}
	return fr;
}


int sum(const vector<int>& v){
	int sum = 0;
	for(int i=0; i<v.size(); ++i){
		sum += v[i];
	}
	return sum;
}


int simulate(const vector<int>& barbers, int pos)
{

	int fullRot = fullRotation(barbers);
	int currCust = 0;
	while(currCust < pos){
		currCust += fullRot;
	}
	currCust -= fullRot;
	currCust += 1;
	if(currCust <= 0) currCust = 1;

//	cout << fullRot << endl;






	vector<int> chairs(barbers.size(),0);
	int lastAss;
	for(int cust = currCust; cust<= pos; ++cust)
	{
		// paei na evrei to proto athkiasero
		bool found = false;
		for(int i=0; i<chairs.size(); ++i){
			if (chairs[i] == 0){
				//	cout << "Customer " << cust << " is with barber" << i << endl;
				// ivren athkiasero ara fkenei
				chairs[i] = barbers[i];
				lastAss = i+1;
				found = true;
				break;
			}
		}
		if(found){
			continue;
		}
		// alliws diagrafume tus ullus ena lepto
		else{
			int mini = chairs[0];
			for(int i=0; i<chairs.size(); ++i){
				if(mini > chairs[i]) mini = chairs[i];
			}
			for(int i=0; i<chairs.size(); ++i){
				chairs[i]-=mini;
			}
			cust--;
		}
	}
	return lastAss;
}



int main(){
	int n;
	cin >> n;
	
	for(int i=0; i<n; ++i)
	{
		int B,N;
		cin >> B;
		cin >> N;

		vector<int> barbers(B);
		for(int i=0; i<B; ++i)
		{
			cin >> barbers[i];
		}
		cout << "Case #" << i+1 << ": " <<  simulate(barbers,N) << endl;


		
	}
	return 0;
}