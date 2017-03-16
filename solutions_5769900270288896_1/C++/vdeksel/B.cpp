#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

void start()
{
	printf("%d\n", TestCase);
	int result;
	// read test case
	int R, C, N;
	ein >> R >> C >> N;

	int Z;
	if (min(R,C)==1)
	{
		if (max(R,C) % 2 == 1)
		{
			Z = N-(max(R,C)+1)/2;
			if (Z <= 0)
			{
				result = 0;
			}
			else
			{
				result = 2*Z;
			}
		}
		else
		{
			Z = N-(max(R,C)/2);
			if (Z <= 0)
			{
				result = 0;
			}
			else
			{
				result = 1;
				Z--;
				result += 2*Z;
			}
		}
	}
	else
	{

	result = 2*R*C-C-R;	
	int X = R*C - N;

	int maxX;
	maxX = ceil((double(R)-2)*(double(C)-2)/2);
	X = min(X, maxX);
	result -= 4*X;

	int Y = R*C-N-X;
	int bl = ceil(double(R)*double(C)/2);

	int eck;
	eck = (R*C % 2 == 1 ? 4 : 2);
	int maxY = bl - maxX - eck;
	
	result -= 3*min(Y,maxY);
	
	Y -= min(Y,maxY);

	result -= 2*min(Y,eck);
	
	// yet another way...
	int result2 = 2*R*C-R-C;
	X = R*C-N;
	maxX = (R-2)*(C-2) - maxX;
	X = min(X, maxX);
	result2 -= 4*X;
	Y = R*C-N-X;
	bl = R*C-bl;
	eck = 4-eck;
	maxY = bl - maxX - eck;
	result2 -= 3*min(Y,maxY);
	Y -= min(Y,maxY);
	result2 -= 2*min(Y,eck);

	result = min(result,result2);


	}
	// output result
    fprintf(aus, "Case #%d: %d\n", TestCase, result);     // %llu , %ll
}

void main()
{
	int NumTestCases;	
	ein.open("B-large.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
