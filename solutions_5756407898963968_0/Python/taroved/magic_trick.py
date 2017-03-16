import sys

input_file = sys.argv[1]
output_file = "%s.out" % input_file.split('.')[0]
print "INPUT FILE: %s" % input_file
print "OUTPUT FILE: %s" % output_file

def read_cards(file):
    answer_row = int(f.readline())
    for j in xrange(0, 4):
        if (answer_row == j+1):
            cards = f.readline().split()
        else:
            f.readline()
    return cards

case_no = 1
results = []
with open(input_file) as f:
    case_cout = int(f.readline())
    for i in xrange(0,case_cout):
        cards1 = read_cards(f)
        cards2 = read_cards(f)
        
        current_found_card = None
        cards_found = 0
        for card1 in cards1:
            for card2 in cards2:
                if (card1 == card2):
                    cards_found += 1
                    current_found_card = card1
        
        if (cards_found == 1):
            results.append(current_found_card)
        elif (cards_found > 1):
            results.append("Bad magician!")
        else: #0
            results.append("Volunteer cheated!")

with open(output_file, 'w') as f:
    i = 1
    for result in results:
        f.write("Case #%s: %s\n" % (i, result))
        i += 1