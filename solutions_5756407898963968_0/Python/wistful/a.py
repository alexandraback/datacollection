for t in xrange(1, int(raw_input()) + 1):
    cnt = [0] * 17
    for p in xrange(2):
      r = int(raw_input()) - 1
      for i in xrange(4):
        l = map(int, raw_input().split())
        if i == r:
          for j in xrange(4):            
            cnt[l[j]] += 1
    a = "Volunteer cheated!"
    for v in xrange(17):
      if cnt[v] == 2:
        if str(a)[0] != 'V':
          a = "Bad magician!"
          break
        a = v
    print "Case #{}: {}".format(t, a)