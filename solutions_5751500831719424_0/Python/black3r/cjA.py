T = int(input())
for I in range(1, T+1):
    result = "Fegla Won"
    stringinfo = []
    n = int(input())
    for i in range(0, n):
        s = input() # string
        lastchar = ''
        sinfo = {'chars': [], 'counts': []}
        for c in s:            
            if c != lastchar:
                if lastchar != '':
                    sinfo['chars'].append(lastchar)
                    sinfo['counts'].append(count)
                count = 1
                lastchar = c
            else:
                count += 1
        sinfo['chars'].append(lastchar)
        sinfo['counts'].append(count)
        stringinfo.append(sinfo)
    charcount = len(stringinfo[0]['chars'])
    valid = True
    for x in stringinfo:
        if len(x['chars']) != charcount:
            valid = False
        else:
            for i in range(0, charcount):
                if stringinfo[0]['chars'][i] != x['chars'][i]:
                    valid = False

    total = 0    
    if valid:
        for i in range(0, charcount):
            arr = []
            for x in stringinfo:
                arr.append(x['counts'][i])
            arr.sort()
            mean = arr[len(arr)//2]
            subtotal = 0
            for x in arr:
                subtotal += abs(x - mean)
            total += subtotal
        result = str(total)
                
    print("Case #%d: %s" % (I, result))
