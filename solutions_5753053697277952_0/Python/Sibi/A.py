import sys

iFile = open(sys.argv[1],"r")

T = int(iFile.readline().strip())

def id2letter(x):
  return chr(ord('A')+x)
  
def argmax(x):
  max_item = max(x)
  return x.index(max_item)

for t in range(T):
  parties = int(iFile.readline().strip())
  senators = [int(x) for x in iFile.readline().strip().split()]
  
  answer = ""
  first = True
  if sum(senators) % 2 != 0:
    answer = id2letter(argmax(senators))
    answer += " "
    senators[argmax(senators)] -= 1
    first = False
    
  while sum(senators) > 0:
    if not first:
      answer += " "
    first = False
    largest_party = argmax(senators)
    senators[largest_party] -= 1
    answer += id2letter(largest_party)
    largest_party = argmax(senators)
    senators[largest_party] -= 1
    answer += id2letter(largest_party)
    
    
  
  output = str(answer)
  
  print("Case #"+str(t+1)+": "+output)
