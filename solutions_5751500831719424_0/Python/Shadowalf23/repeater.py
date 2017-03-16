

def problem(words):
  counter={}
  for i in range(len(words)):
    counter[i]=0
  totmoves=0

  fword=words[0]
  done=False
  while True:
    #check current
    for i in range(len(words)):
      if fword[counter[0]]!=words[i][counter[i]]:
        return "Fegla Won"
    # if it passes that, move the counters
    moves=[]
    donewords=[]
    #print counter
    for i in range(len(words)):
      word=words[i]
      curletter=word[counter[i]]
      tmpmoves=0
      while counter[i]<len(word) and word[counter[i]]==curletter:
        counter[i]+=1
        tmpmoves+=1
      moves.append(tmpmoves)
      if counter[i]>=len(word):
        donewords.append(word)
        done=True
    while len(moves)>=2:
      mymax=max(moves)
      mymin=min(moves)
      totmoves+=(mymax-mymin)
      moves.remove(mymax)
      moves.remove(mymin)
    if done and len(donewords)==len(words):
      return totmoves
    elif done:
      return "Fegla Won"

def main():
  f=open("A-small-attempt0.in",'r')
  lines=f.readlines()
  lines=lines[1:]
  i=0
  casen=1
  while i <len(lines):
    n=int(lines[i].strip("\n"))
    curlist=[]
    for j in range(n):
      curlist.append(lines[i+1+j].strip("\n"))
    #print curlist
    out=problem(curlist)
    print "Case #"+str(casen)+": "+str(out)
    casen+=1
    i=i+n+1

main()
