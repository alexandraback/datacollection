#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream ein;
FILE * aus;
int TestCase;

void start()
{	
	// read test case
	vector<int> u(17,0);
	int a,rg,r,c,m,ps;	
	ps = -1;
	for (a=0;a<2;a++)
	{
		ein >> rg;
		for (r=1;r<5;r++)	
		{
			for (c=1;c<5;c++)
			{
				ein >> m;
				if (r==rg)
				{
					u[m]++;
					if (u[m]==2)
					{
						if (ps==-1)
							ps=m;
						else
							ps=100;
					}
				}
			}
		}
	}
	// output result    
	fprintf(aus, "Case #%d: ", TestCase);
	if (ps == -1)
		fprintf(aus, "Volunteer cheated!\n");
	if (ps == 100)
		fprintf(aus, "Bad magician!\n");
	if (ps>=0 && ps<=18)
		fprintf(aus, "%d\n", ps);
}

void main()
{
	int NumTestCases;	
	ein.open("A-small-attempt0.in");
	aus = fopen("ausgabe.txt","w");
	
	ein >> NumTestCases;
	for (TestCase = 1; TestCase <= NumTestCases; TestCase++)
		start();

	fclose(aus);
	ein.close();
}
