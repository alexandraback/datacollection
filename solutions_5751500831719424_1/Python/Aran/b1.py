def st(x):
  z1 = []
  z2 = []
  y = ''
  for c in x:
    if y != c:
      y = c
      z1.append(c)
      z2.append(1)
    else:
      z2[-1] += 1
  return z1, z2

def median(x):
  return sorted(x)[len(x)//2]

def A(z):
  zs = [st(x) for x in z]
  x = {tuple(x[0]) for x in zs}
  if not len(x) == 1:
    return False
  lengths = [x[1] for x in zs]
  lengths = [[x[i] for x in lengths] for i in range(len(lengths[0]))]
  medians = [median(l) for l in lengths]
  dist = sum(sum(abs(l-m) for l in ll) for ll,m in zip(lengths, medians))
  return dist


def main():
  T = int(input())
  for i in range(T):
    N = int(input())
    strs = []
    for j in range(N):
      strs.append(input())
    x = A(strs)
    print("Case #{}: {}".format(i+1, x if x is not False else "Fegla Won"))


main()
