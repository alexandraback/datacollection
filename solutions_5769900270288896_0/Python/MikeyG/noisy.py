with open("B.in") as f:
  num_cases = int(f.readline().strip())
  for case in range(1,num_cases+1):
    data = [int(num) for num in f.readline().strip().split()]
    R = data[0]
    C = data[1]
    N = data[2]
    
    
    # Case 1:
    bank = 0
    rooms_empty = [0,0,0,0,0]
    for i in range(R):
      for j in range(C):
        
        if (i + j) % 2 == 0:
          bank += 1
          continue
      
        score_saved = 4
        if i-1 < 0:
          score_saved -= 1
        if i+1 >= R:
          score_saved -= 1
        if j-1 < 0:
          score_saved -= 1
        if j+1 >= C:
          score_saved -= 1
          
        rooms_empty[score_saved] += 1
        
    # Figure out maximum possible score to save
    # Fill up empty rooms one at a time
    
    unhappiness = 0
    
    # print rooms_empty
    
    for i in range(N):
      if bank > 0:
        bank -= 1
        continue
      for j in range(len(rooms_empty)):
        if rooms_empty[j] > 0:
          rooms_empty[j] -= 1
          unhappiness += j
          break
          
        
    
    # Case 2:
    bank = 0
    rooms_empty = [0,0,0,0,0]
    for i in range(R):
      for j in range(C):
        
        if (i + j) % 2 != 0:
          bank += 1
          continue
      
        score_saved = 4
        if i-1 < 0:
          score_saved -= 1
        if i+1 >= R:
          score_saved -= 1
        if j-1 < 0:
          score_saved -= 1
        if j+1 >= C:
          score_saved -= 1
          
        rooms_empty[score_saved] += 1
    
    # print rooms_empty
    # Figure out maximum possible score to save
    # Fill up empty rooms one at a time
    
    other_unhappiness = 0
    # print bank
    # print rooms_empty
    
    for i in range(N):
      if bank > 0:
        bank -= 1
        continue
      for j in range(len(rooms_empty)):
        if rooms_empty[j] > 0:
          rooms_empty[j] -= 1
          other_unhappiness += j
          break
    
    # print other_unhappiness, unhappiness
    
    answer = min(unhappiness, other_unhappiness)
    
    print("Case #{}: {}".format(case, answer))