#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int GCD(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	//cout << "GCD of " << a << " and " << b << " is " << a << endl;
	return a;
}

int LCM(int a, int b)
{
	return (a/GCD(a,b))*b;
}

int main(int argc, char *argv[])
{
    if (argc!=3) 
    {
	cout << "Missing arguments." << endl;
	return -1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int T;
    fin >> T;

    for (int t = 0; t < T; ++t)
    {
		int B, N;
		fin >> B; fin >> N;
		
		vector<int> M;
		for (int i = 0; i < B; ++i)
		{
			int temp;
			fin >> temp;
			M.push_back(temp);
		}
		int solution = -1;
		
		if (B == 1)
		{
			solution = 1;
		}
		else
		{
			int lcm = LCM(M[0],M[1]);
			for (int i = 2; i < B; ++i)
			{
				lcm = LCM(lcm,M[i]);
			}
			
			vector<int> nPerLCM(B);
			int totalNPerLCM = 0;
			for (int i = 0; i < B; ++i)
			{
				nPerLCM[i] = lcm/M[i];
				//cout << nPerLCM[i] << endl;
				totalNPerLCM += nPerLCM[i];
			}
			
			N = N % totalNPerLCM;
			if (N == 0) N = totalNPerLCM;
			
			//cout << "totalNPerLCM: " << totalNPerLCM << endl;
			//cout << "lcm: " << lcm << endl;
			int timePtr = lcm / 2;
			int begPtr = 0;
			int endPtr = lcm+1;
			int lowerBound = N + 1;
			int upperBound = -1;
			while ( begPtr <= endPtr)
			{
				
				timePtr = begPtr + (endPtr-begPtr)/2;
				/*cout << "lower: " << lowerBound << endl;
				cout << "upper: " << upperBound << endl;
				cout << "timePtr: " << timePtr << endl;
				cout << "begPtr: " << begPtr << endl;
				cout << "endPtr: " << endPtr << endl;
								
				cout << "N: " << N << endl;*/
				
				lowerBound = 0;
				upperBound = 0;
				for (int i = 0; i < B; ++i)
				{
					if (timePtr % M[i] == 0)
					{
						lowerBound += timePtr / M[i];
						upperBound += timePtr / M[i] + 1;
					}
					else
					{
						lowerBound += timePtr / M[i] + 1;
						upperBound += timePtr / M[i] + 1;
					}
					//lowerBound += 1;
				}
				
				if (timePtr == 0)
				{
					lowerBound = 0;
					upperBound = B;
				}					
				
				if (lowerBound < N && N <= upperBound)
				{
					/*cout << "found at " << timePtr << endl;
					cout << "lowerBound >= N" << endl;
					cout << "lb is " << lowerBound << endl;
					cout << "N is " << N << endl;
					cout << "ub is " << upperBound << endl;*/
					break;
				}
				
				if (lowerBound >= N)
				{
					//timePtr = begPtr + (timePtr-begPtr) / 2;
					endPtr = timePtr;
					/*cout << "lowerBound >= N" << endl;
					cout << "lb is " << lowerBound << endl;
					cout << "N is " << N << endl;
					cout << "ub is " << upperBound << endl;*/
				}
				else if (upperBound < N)
				{
					//timePtr = timePtr + (endPtr-timePtr) / 2;
					begPtr = timePtr+1;
					
				}
			}
			
			int count = lowerBound;
			for (int i = 0; i < B; ++i)
			{
				if (timePtr % M[i] == 0)
				{
					++count;
					if (count == N)
					{
						solution = i+1;
						break;
					}
				}
			}
			
			
			
			/* vector<int> m(B);
			int count = 0;
			while (solution < 0)
			{
				//cout << count << endl;
				int minIdx = -1;
				int minElem = 100001;
				for (int i = 0; i < B; ++i)
				{
					if (m[i] < minElem)
					{
						minIdx = i;
						minElem = m[i];
					}
				}
				for (int i = 0; i < B; ++i)
				{
					
					m[i] -= minElem;
					if (m[i] == 0)
					{
						m[i] = M[i];
						++count;
						if (count == N)
						{
							solution = i+1;
							break;
						}
						
						
					}
				}

				/*for (int i = 0; i < B; ++i)
				{
					cout << m[i] << " ";
				}
				cout << endl;

			}
			*/
			
		}
		
		
		fout << "Case #" << t+1 << ": " << solution;
		
		fout << endl;
    }
    return 0;
}
