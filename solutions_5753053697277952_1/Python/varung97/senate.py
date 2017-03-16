import sys, math

def senate(numpart, sen):
    ans = ''
    while not done(sen):
        maxi = gettop(sen)
        if len(maxi) >= 4 or len(maxi) == 2:
            sen[maxi[0]] -= 1
            sen[maxi[1]] -= 1
            ans += chr(65 + maxi[0])
            ans += chr(65 + maxi[1])
        else:
            sen[maxi[0]] -= 1
            ans += chr(65 + maxi[0])
        ans += ' '
    return ans.strip()

def done(sen):
    for i in sen:
        if i != 0:
            return False
    return True

def gettop(sen):
    maxs = max(sen)
    maxi = []
    for i in range(len(sen)):
        if sen[i] == maxs:
            maxi.append(i)
    return maxi

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        numpart = int(test.readline().strip())
        sen = list(map(int, test.readline().strip().split()))
        print('Case #' + str(i + 1) + ': ' + str(senate(numpart, sen)))
