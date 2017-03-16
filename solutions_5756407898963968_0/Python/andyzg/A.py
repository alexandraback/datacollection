def solve(firstSol, firstGrid, secSol, secGrid):
  ans = dict()
  for num in firstGrid[int(firstSol)-1]:
    ans[num] = 1

  count = 0
  index = ""
  for num in secGrid[int(secSol)-1]:
    if num in ans:
      ans[num] = ans[num] + 1
      count += 1
      index = num

  if count == 1:
    return index
  elif count == 0:
    return "CHEAT"
  else:
    return "BAD"
  
def main():
  input = open("input.in","r").read().split("\n")
  output = open("output.out", "w")

  num = input.pop(0)
  for i in range(0, int(num)):
    firstSol = input.pop(0)
    firstGrid = []
    
    for j in range(0, 4):
      firstGrid.append(input.pop(0).split(" "))
    secSol = input.pop(0)
    secGrid = []
    for j in range(0, 4):
      secGrid.append(input.pop(0).split(" "))

    case = solve(firstSol, firstGrid, secSol, secGrid)
    
    if case == "CHEAT":
      output.write("Case #" + str(i+1) + ": Volunteer cheated!\n")
    elif case == "BAD":
      output.write("Case #" + str(i+1) + ": Bad magician!\n")
    else:
      output.write("Case #" + str(i+1) + ": " + case + "\n")

main()
