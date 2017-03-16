def gcd(x, y):
  while(y):
    x, y = y, x % y
  return x

def process():
  [B, N] = map(int, raw_input().split())
  M = map(int, raw_input().split())
  
  # Base case
  if N <= B:
    return N
  if len(set(M)) == 1:
    return N % B if N % B !=0 else B

  # Reducing the problem
  lcm = reduce(lambda x,y: x*y, M) // reduce(gcd, M)
  reset = sum([lcm//x for x in M])
  while reset < N:
    N -= reset 

  index = 1
  shop = [0 for item in M]
  """
  while index <= N - B:
    print shop
    mini = min(shop)
    newShop = [val-mini+M[idx] for idx, val in enumerate(shop)]
    print newShop
    shop = newShop
    index += B
  """
  while index < N:
    idx = shop.index(min(shop))
    shop[idx] += M[idx]
    index += 1
  return shop.index(min(shop)) + 1
  

def main():
  T = int(raw_input())
  tc = T
  while tc > 0:
    tc -= 1
    ans = process()
    print u"Case #{}: {}".format(T-tc, ans)

if __name__ == "__main__":
  main()
