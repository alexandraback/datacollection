def getNums():
  chosen = int(input())-1
  for row in range(4):
    line = input()
    if row == chosen:
      ret = set(map(lambda x: int(x), line.split(' ')))
  return ret

for case in range(1, int(input())+1):
  nums = getNums() & getNums()
  if len(nums) == 0:
    ans = 'Volunteer cheated!'
  elif len(nums) == 1:
    ans = list(nums)[0]
  else:
    ans = 'Bad magician!'

  print("Case #"+str(case)+':', ans)
