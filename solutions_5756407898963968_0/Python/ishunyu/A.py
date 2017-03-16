f = open("A-small-attempt0.in", "r")
fout = open("A-small-attempt0.out", "w")
num = int(f.readline())
res = 0

for i in range(num):
  # read first arrangement
  r1 = int(f.readline())
  r1_nums = []

  for j in range(4):
    if j == (r1-1):
      r1_nums = f.readline().split(" ")
      r1_nums = [int(x) for x in r1_nums]
    else:
      f.readline()

  # read second arragement
  r2 = int(f.readline())
  r2_nums = []

  for j in range(4):
    if j == (r2-1):
      r2_nums = f.readline().split(" ")
      r2_nums = [int(x) for x in r2_nums]
    else:
      f.readline()

  res = 0
  done = False
  for x in r1_nums:
    if done:
      break
    for y in r2_nums:
      if y == x:
        if res == 0:
          res = x
        elif res > 0:
          res = -1
          done = True
          break

  if res == 0:
    fout.write("Case #" + str(i+1) + ": Volunteer cheated!")
  elif res > 0:
    fout.write("Case #" + str(i+1) + ": " + str(res))
  else:
    fout.write("Case #" + str(i+1) + ": Bad magician!")
  fout.write("\n")




