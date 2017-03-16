import sys
import math
import copy



PARTIES = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
ANSWER = ""

#with open("A-large.in") as f :
with open("A-small-attempt0.in") as f :
#with open("input.txt") as f :
	T = int(f.readline());
	line = f.readline();
	for t in range(T) :
		N = int(line);
		SENATORS = list()
		line = f.readline();
		SENATORS = [int(x) for x in line.split()];
		COUNT = 0;
		for z in range(0, len(SENATORS)) :
			COUNT += SENATORS[z];
		print N
		print SENATORS
		print COUNT
		
		result = "Case #%d:" % (t+1)
		#print result
		while COUNT != 0 :
			data = "";
			for i in range(0,len(SENATORS)) :
				SENATORS[i] = SENATORS[i] - 1;
				SUM = COUNT - 1;
				flag = 1;
				if SUM != 0 :
					for k in range(0,len(SENATORS)) :
						if SENATORS[k]*1.0/SUM > 0.5 :
							flag = 0;
							break;
				if flag == 0 :
					SENATORS[i] = SENATORS[i] + 1;
				else :
					data = " " + PARTIES[i];
					COUNT = SUM;
					print data;
					break;
			if data == "" :
				for i in range(0,len(SENATORS)) :
					for j in range(0, len(SENATORS)) :
						flag = 1;
						SENATORS[i] = SENATORS[i] - 1;
						SENATORS[j] = SENATORS[j] - 1;
						if SENATORS[i] >= 0 and SENATORS[j] >= 0 :
							SUM = COUNT - 2;
							if SUM != 0 :
								for k in range(0,len(SENATORS)) :
									if SENATORS[k]*1.0/SUM > 0.5 :
										flag = 0;
										break;
							if flag == 0 :
								SENATORS[i] = SENATORS[i] + 1;
								SENATORS[j] = SENATORS[j] + 1;
							else : 
								data = " " + PARTIES[i] + PARTIES[j];
								COUNT = SUM;
								print data;
								break;
						else :
							flag = 0;
							SENATORS[i] = SENATORS[i] + 1;
							SENATORS[j] = SENATORS[j] + 1;

					if flag == 1 :
						break;
			print COUNT
			result += data;
		result += "\n"
		print result
		ANSWER += result;
		line = f.readline();

#with open("A-large.txt", 'w') as f :
with open("A-samll.txt", 'w') as f :	
#with open("output.txt", 'w') as f :
	f.write(ANSWER);



#with open("A-large.txt", 'w') as f :
#with open("A-samll.txt", 'w') as f :
#with open("output.txt", 'w') as f :
	
		

