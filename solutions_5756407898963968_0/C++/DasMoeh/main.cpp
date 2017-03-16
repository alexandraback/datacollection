#include <QCoreApplication>

#include <QTextStream>
#include <QFile>
#include <QStringList>

#include <QDebug>

int main(int argc, char** argv)
{
  QCoreApplication app(argc, argv);
  QFile inFile("/home/alex/projects/GoogleCodeJam/input/input.txt");
  if(!inFile.open(QIODevice::ReadOnly)) {
    qDebug() <<  "ReadError:" << inFile.errorString();
    return -1;
  }
  QTextStream in(&inFile);
  QFile outFile("/home/alex/projects/GoogleCodeJam/input/output.txt");
  if(!outFile.open(QIODevice::WriteOnly)) {
    qDebug() <<  "WriteError:" << outFile.errorString();
    return -1;
  }
  QTextStream out(&outFile);
  int numberOfCases = in.readLine().toInt();
  qDebug() << "Cases:" << numberOfCases;
  for (int c = 1; c <= numberOfCases; ++c)
  {
    int firstNumber = in.readLine().toInt();
    qDebug() << "First Number:" << firstNumber;
    QStringList firstRow;
    for (int i = 1; i <= 4; ++i)
    {
      QString line = in.readLine();
      if (firstNumber == i)
      {
	firstRow = line.split(" ");
	qDebug() << firstRow;
	Q_ASSERT_X(firstRow.size() == 4, "main", "number of tokens in first row is not four");
      }
    }
    int secondNumber = in.readLine().toInt();
    qDebug() << "Second Number:" << secondNumber;
    QStringList secondRow;
    for (int i = 1; i < 5; ++i)
    {
      QString line = in.readLine();
      if (secondNumber == i)
      {
	secondRow = line.split(" ");
	qDebug() << secondRow;
	Q_ASSERT_X(secondRow.size() == 4, "main", "number of tokens in second row is not four");
      }
    }
    int matches = 0;
    int match = -1;
    for (int i = 0; i < firstRow.size(); ++i)
    {
      if (secondRow.contains(firstRow[i]))
      {
	matches++;
	match = firstRow[i].toInt();
      }
    }
    if (0 == matches)
    {
      out << "Case #" << c << ": Volunteer cheated!" << endl;
    }
    else if (1 == matches)
    {
      out << "Case #" << c << ": " << match << endl;
    }
    else
    {
      out << "Case #" << c << ": Bad magician!" << endl;
    }
  }
  inFile.close();
  outFile.close();
  return app.exec();
}
