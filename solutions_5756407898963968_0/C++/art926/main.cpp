#include <QFile>
#include <QTextStream>
#include <QSet>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam2014-0A/test.txt");
QFile outFile("C:/CodeJam2014-0A/output.txt");


int main(int argc, char *argv[])
{
	inFile.open(QFile::ReadOnly);
	outFile.open(QFile::WriteOnly);
	QTextStream inData(&inFile);
	QTextStream outData(&outFile);

	int T;
	inData >> T;

	for(int t=0; t<T; t++)
	{
		int i1, i2;
		QSet<int> set1, set2;
		int n;

		inData >> i1;
		for(int i=1; i<=4; i++)
		{
			for(int j=1; j<=4; j++)
			{
				inData >> n;
				if(i==i1)  set1 << n;
			}
		}

		inData >> i2;
		for(int i=1; i<=4; i++)
		{
			for(int j=1; j<=4; j++)
			{
				inData >> n;
				if(i==i2)  set2 << n;
			}
		}

		QList<int> repeatedNumbers = set1.intersect(set2).toList();

		if(repeatedNumbers.count()==0)		outData << QString("Case #%1: %2\r\n").arg(t+1).arg("Volunteer cheated!");
		else if(repeatedNumbers.count()==1)	outData << QString("Case #%1: %2\r\n").arg(t+1).arg(repeatedNumbers[0]);
		else					outData << QString("Case #%1: %2\r\n").arg(t+1).arg("Bad magician!");
	}
}