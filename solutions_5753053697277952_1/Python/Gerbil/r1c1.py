from collections import defaultdict

def result(input):
    nums = map(int, input.split(' '))
    rtn = []
    sizes = defaultdict(list)
    for i,size in enumerate(nums):
        sizes[size].append(chr(i+65))
    size_list = range(1, max(sizes.keys()) + 1)[::-1]
    while size_list:
        #print(sizes)
        #print(size_list)
        if len(sizes[size_list[0]]) == 0:
            del size_list[0]
        elif len(sizes[size_list[0]]) == 1:
            t = sizes[size_list[0]][0]
            if size_list[0] == 1:
                rtn.append(t)
                break
            else:
                rtn.append(t * 2)
                sizes[size_list[0] - 2].append(t)
                del sizes[size_list[0]][0]
        else:
            if size_list[0] == 1 and len(sizes[size_list[0]]) > 2:
                a = sizes[size_list[0]][0]
                rtn.append(a)
                sizes[size_list[0] - 1].append(a)
                del sizes[size_list[0]][0]
            else:
                a = sizes[size_list[0]][0]
                b = sizes[size_list[0]][1]
                rtn.append(a+b)
                sizes[size_list[0] - 1].extend([a, b])
                del sizes[size_list[0]][1]
                del sizes[size_list[0]][0]

    print(rtn)
    return ' '.join(rtn)

f = open('A-large.in')
r = f.readlines()
w = open('A-large.out','w')

i = 1
while i < len(r):
    i += 1
    w.write('Case #%s: %s\n' % (str(i//2), result(r[i].strip())))
    i += 1
f.close()
w.close()
