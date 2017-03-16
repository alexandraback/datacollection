n = int(raw_input())
for i in range(n):
	print "Case #%d:"%(i+1),
	
	fir =  int(raw_input())
	fir_mat = []
	for j in range(4):
		row = raw_input().split()
		for k in range(4):
			row[k] = int(row[k])
		fir_mat.append(row)
	 
	sec = int(raw_input())
	sec_mat = []
	for j in range(4):
		row = raw_input().split()
		for k in range(4):
			row[k] = int(row[k])
		sec_mat.append(row)	
		
	count = 0
	for j in range(4):
		flag = True
		for k in range(4):
			if sec_mat[sec-1][k]==fir_mat[fir-1][j]:
				count += 1
				ans = sec_mat[sec-1][k]
			if count > 1:
				ans = "Bad magician!"
				flag = False
				break
		if flag == False:
			break
	if count == 0:
		ans = "Volunteer cheated!"
		
	print ans