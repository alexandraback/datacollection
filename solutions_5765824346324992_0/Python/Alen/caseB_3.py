#!/usr/bin/env python
#encoding: utf-8


def parseMetaLine(metaLine):
    barberCount, number = metaLine.split(' ');
    return int(barberCount), int(number);

def parseBarbers(barberCount, minutesLine):
	minutes = [int(minute) for minute in minutesLine.split(' ')];
	return minutes[:barberCount];


#返回一个周期的 时间 和 理发人数
def periodList(barbers, count):
	time  = 0;
	tempList = list();
	while True:
		addNum = 0;
		index  = 0;
		while index < count:
			if(time % barbers[index] == 0):
				tempList.append(index+1);
				addNum += 1;
			index += 1
		if(addNum == count and time != 0):
			return tempList[:-count];
		time  += 1;


def numth(metaLine, minutesLine):
	barberCount, number = parseMetaLine(metaLine);
	barbers = parseBarbers(barberCount, minutesLine);
	
	periodlist = periodList(barbers, barberCount);
	period = len(periodlist);
	return periodlist[number%period - 1];


def run(inputFile, outputFile):
        fp = open(inputFile, 'r');
        fw = open(outputFile, 'w');

	caseCount = int(fp.readline());
	caseIndex = 0;
	while caseIndex < caseCount:
		caseIndex += 1;
		metaLine = fp.readline();
		minutesLine  = fp.readline();
		num = numth(metaLine, minutesLine);
		fw.write("Case #%d: %d\n"%(caseIndex, num));

        fp.close();
        fw.close();

if __name__ == "__main__":
	run("in", "out");
