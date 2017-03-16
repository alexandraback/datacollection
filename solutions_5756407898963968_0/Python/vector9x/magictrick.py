def read_mat():
    return [raw_input().split() for i in xrange(4)]

for _t in xrange(int(raw_input())):
    row1 = int(raw_input())
    set1 = set(read_mat()[row1-1])
    row1 = int(raw_input())
    set2 = set(read_mat()[row1-1])

    inter = set1 & set2

    if len(inter)==1:
        res = inter.pop()
    elif len(inter)>1 :
        res =  "Bad magician!"
    else :
        res = "Volunteer cheated!"

    print "Case #%d: %s"%(_t+1,res)