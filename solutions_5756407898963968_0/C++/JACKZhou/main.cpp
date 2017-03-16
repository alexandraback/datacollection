#include"iostream"
#include"fstream"
#define cin fin
#define cout fout
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");



	

int main()
{
	int ans1[4],ans2[4],ans,sum,num,row1,row2,temp;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		
		cin >> row1;
		for (int j = 0; j < 4; j++)
		{
			if (j == row1 - 1)
			{
				cin >> ans1[0] >> ans1[1] >> ans1[2] >> ans1[3];
			}
			else
			{
				cin >> temp >> temp >> temp >> temp;
			}
		}
		cin >> row1;
		for (int j = 0; j < 4; j++)
		{
			if (j == row1 - 1)
			{
				cin >> ans2[0] >> ans2[1] >> ans2[2] >> ans2[3];
			}
			else
			{
				cin >> temp >> temp >> temp >> temp;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		sum = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (ans1[i] == ans2[j])
				{
					sum++; ans = ans1[i]; break;
				}
			}
		}
		if (sum == 0)
		{
			cout << "Volunteer cheated!" << endl;
		}
		else if (sum == 1)
		{
			cout << ans << endl;
		}
		else
		{
			cout << "Bad magician!" << endl;
		}
	
	}
	return 0;
}