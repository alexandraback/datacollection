def solve(N):
 k=sorted([(N[i],chr(65+i)) for i in range(len(N))],reverse=True); out=[]
 while k[0][0]:
  c1=k[0][1]; k=sorted([(k[0][0]-1,k[0][1])]+k[1:],reverse=True)
  if sum([t[0] for t in k])!=2:
   c2=k[0][1]; k=sorted([(k[0][0]-1,k[0][1])]+k[1:],reverse=True)
  else: c2=''
  out.append(c1+c2)
 return ' '.join(out)

inp=file('A-small-attempt0.in','rb+'); out=file('A-small-attempt0.out','wb+')

T=int(inp.readline().strip())

for i in range(1,T+1):
 n=int(inp.readline().strip())
 N=[int(s) for s in inp.readline().strip().split(' ')]
 outline='Case #%i: %s'%(i,solve(N))
 print outline
 out.write(outline+'\r\n')