# input
fi = open("python/input.txt", "r")
lines = fi.readlines()
fi.close()

# main part
fo = open("python/output.txt", "wb")
t = int(lines[0])
for j in range(0, t):
  first_choice = int(lines[1 + 10*j])
  first_line = [int(i) for i in lines[1 + first_choice + 10*j].split(' ')]
  second_choice = int(lines[6 + 10*j])
  second_line = [int(i) for i in lines[6 + second_choice + 10*j].split(' ')]
  in_common = list(set(first_line).intersection(set(second_line)))
  if len(in_common) == 1:
    fo.write(bytes('Case #' + str(j+1) + ': ' + str(in_common[0]) + '\n', 'UTF-8'))
  elif len(in_common) == 0:
    fo.write(bytes('Case #' + str(j+1) + ': ' + 'Volunteer cheated!'+ '\n', 'UTF-8'))
  else:
    fo.write(bytes('Case #' + str(j+1) + ': ' + 'Bad magician!' + '\n','UTF-8'))
fo.close()
