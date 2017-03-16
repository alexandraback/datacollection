f = open('A-large.in')
o = open('output.txt', 'w')
n = int(f.readline())
for i in range(n):
  size = int(f.readline())
  arr = [int(x) for x in f.readline().strip().split(" ")]
  #print size, arr
  t_1 = 0
  max_diff = 0
  for j in range(1, size):
    if arr[j] < arr[j-1]:
      t_1 += arr[j-1]-arr[j]
      max_diff = max(max_diff, arr[j-1]-arr[j])
  t_2 = 0
  for j in range(size-1):
    t_2 += min(max_diff, arr[j])
  o.write('Case #'+str(i+1)+': '+str(t_1)+" "+str(t_2)+'\n')
f.close()
o.close()
