#include <QFile>
#include <QTextStream>
#include <QSet>
#include <math.h>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam/Round1/B/B-small-attempt0.in");
QFile outFile("C:/CodeJam/Round1/B/output.txt");

int indexOfMinValue(QList<int> *list)
{
    int index = 0;
    int min = list->value(0);
    for(int i=1; i<list->count(); i++)
    {
        if(list->value(i) < min)
        {
            min = list->value(i);
            index = i;
        }
    }

    return index;
}

int gcd(int a, int b)  //greatest common divisor
{
  int c;
  while ( a != 0 )
  {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int lcm(int a, int b)  //lowest common multiple
{
    return a*b / gcd(a,b);
}

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
        int B, N;
        inData >> B;
        inData >> N;

        QList<int> speedRates, minutesLeft;
        for(int i=0; i<B; i++)
        {
            int s;  //number of minutes needed for i-barber
            inData >> s;
            speedRates.append(s);
            minutesLeft.append(0);
            //totalSpeed += (double)1/s;
        }

        if(B>1)
        {
            //find period
            int period = 1;
            for(int i=0; i<speedRates.count(); i++)   period = lcm(period, speedRates[i] );

            int peopleForPeriod = 0;
            for(int i=0; i<speedRates.count(); i++)  peopleForPeriod += period / speedRates[i];

            while(N>peopleForPeriod) N -= peopleForPeriod;
        }

        int indexOfMin = 0;
        int tMinutesLeft;
        for(;;)
        {
            indexOfMin = indexOfMinValue(&minutesLeft);
            N--;
            if(N==0) break;

            tMinutesLeft = minutesLeft[indexOfMin];
            for(int i=0; i<minutesLeft.count(); i++)  minutesLeft[i] -= tMinutesLeft;
            minutesLeft[indexOfMin] += speedRates[indexOfMin];
        }

        outData << QString("Case #%1: %2\r\n").arg(t+1).arg(indexOfMin+1);
    }
}























