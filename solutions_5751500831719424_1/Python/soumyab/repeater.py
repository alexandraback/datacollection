T = int(input())

format_string = "Case #{0}: {1}"

def median(blah):
    blah.sort()
    return blah[len(blah)//2]

def find_min_edit(blah):
    med = median(blah)
    edit = 0
    for item in blah:
        edit += abs(item-med)
    return edit

def run_length_encoding(string):
    first_chr = None
    this_string = list()
    characters = list()
    for char in string:
        if char == first_chr:
            this_string[-1] += 1
        else:
            first_chr = char
            this_string.append(1)
            characters.append(char)
    return this_string, characters

for i in range(T):
    N = int(input())
    string_rep = list()
    printed = False
    list_of_characters = list()
    for q in range(N):
        string = input()
        x, y = run_length_encoding(string)
        string_rep.append(x)
        if q == 0:
            list_of_characters = y
        else:
            if len(y) != len(list_of_characters):
                if not printed:
                    print(format_string.format(i+1, "Fegla won"))
                printed = True
            else:
                for index in range(len(list_of_characters)):
                    if y[index] != list_of_characters[index]:
                        if not printed:
                            print(format_string.format(i+1, "Fegla won"))
                        printed = True
                        break
    length = len(string_rep[0])
    if not printed:
        distance = 0
        grouped_by_letter = [list() for x in range(length)]
        for q in range(length):
            for string in string_rep:
                grouped_by_letter[q].append(string[q])
        print(format_string.format(i+1, sum([find_min_edit(blah) for blah in grouped_by_letter])))
