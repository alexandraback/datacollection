from sys import stdin


def read_str(): return stdin.readline().rstrip('\n')
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())
def read_floats(): return map(float, stdin.readline().split())


def get_chars(w):
    chars = [w[0]]
    for i in range(1, len(w)):
        if w[i] != chars[-1]:
            chars.append(w[i])
    return chars
            
def get_norm(w):
    v = []
    current = 1
    for i in range(1, len(w)):
        if w[i] != w[i - 1]:
            v.append(current)
            current = 1
        else:
            current += 1
    v.append(current)
    return v
            

def solve_case():
    n = read_int()
    words = []
    for i in range(n):
        words.append(read_str())
    #print('\n', words)
        
    chars = []
    norm = []
    for w in words:
        chars.append(get_chars(w))
        norm.append(get_norm(w))
        
    #print(chars)
    #print(norm)
        
    for i in range(1, n):
        if chars[i] != chars[i - 1]:
            return 'Fegla Won'
        
    sum = 0
    for i in range(len(norm[0])):
        avg = 0
        for j in range(len(norm)):
            avg += norm[j][i]
        avg //= len(norm)
        for j in range(len(norm)):
            sum += abs(avg - norm[j][i])
    return sum

    
def main():
    cases = read_int()
    for case in range(1, cases + 1):
        print('Case #{}: {}'.format(case, solve_case()))

        
main()
