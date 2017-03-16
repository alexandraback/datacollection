T = int(raw_input())

for i in xrange(T):
  cards = []
  for j in xrange(2):
    # Get answer
    answer = int(raw_input()) 
    # Get required line
    for k in xrange(4):
      tmp = raw_input().split()
      if (k + 1) == answer:
        cards.append(tmp)

  # Compute answer
  num_match = 0
  num = 0
  for item in cards[0]:
    if item in cards[1]: # coincidences
      num_match += 1
      num	 = item

  if num_match == 1:
    print 'Case #' + str(i+1) + ': ' + str(num)
  elif num_match > 1:
    print 'Case #' + str(i+1) + ': ' + 'Bad magician!'
  else:
    print 'Case #' + str(i+1) + ': ' + 'Volunteer cheated!'
