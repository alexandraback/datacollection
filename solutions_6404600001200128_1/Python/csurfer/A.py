def process():
  l = int(input())
  arr = map(int, raw_input().split())
  res1 = 0
  res2 = 0
  largeDrop = 0
  for i in xrange(1, l):
    if arr[i] < arr[i-1]:
      largeDrop = max(largeDrop, arr[i-1] - arr[i])
      res1 += arr[i-1] - arr[i]
  for i in xrange(l-1):
    res2 += min(arr[i], largeDrop)
  return str(res1) + " " + str(res2)

def main():
  T = int(raw_input())
  tc = T
  while tc > 0:
    tc -= 1
    ans = process()
    print u"Case #{}: {}".format(T-tc, ans)

if __name__ == "__main__":
  main()
