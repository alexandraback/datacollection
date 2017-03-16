def meth1(lst):
    count = 0
    for x in range(1, len(lst)):
        if lst[x] < lst[x-1]:
            count += lst[x-1] - lst[x]
    return count


def meth2(lst):

    rate = 0

    for x in range(1, len(lst)):
        if lst[x-1] - lst[x] > rate:
            rate = lst[x-1] - lst[x]

    count = 0
    for x in range(0, len(lst)-1):
        if lst[x] < rate:
            count += lst[x]
        else:
            count += rate
    return count

with open('A-large.in') as f:
    stuff = f.readlines()

x = 2
case = 1

while x < len(stuff):
    nums = list(map(int, stuff[x].split()))
    m1 = meth1(nums)
    m2 = meth2(nums)
    print('Case #'+str(case)+": "+str(m1)+" "+str(m2))
    x += 2
    case += 1