t = int(input())
for i in range(1, t + 1):
    output = ''
    number_of_parties = int(input())
    party_numbers = input().split(" ")


    for j in range(0,len(party_numbers)):
        party_numbers[j] = int(party_numbers[j])



    active_parties = number_of_parties
    while active_parties >= 3:
        z = ""
        biggest_party = 0
        smallest_party = 100000

        for j in range(0, len(party_numbers)):
            if (party_numbers[j]) < smallest_party:
                smallest_party = party_numbers[j]


        for j in range(0, len(party_numbers)):
            if (party_numbers[j]) > biggest_party:
                biggest_party = party_numbers[j]

                z1 = j
                z = chr(j + 65)

        if smallest_party == biggest_party:
            break
            # all parties same size

        output += z + ' '
        party_numbers[z1] -= 1
    while active_parties >= 3:
        for j in range(0, len(party_numbers)):
            if party_numbers[j] != 0:
                save = j
                break
        for j in range(0, party_numbers[save]):
            output += chr(save + 65) + ' '
            party_numbers[save] -= 1
        active_parties -= 1






    while active_parties == 2:

        #print the two parties till empty


        for j in range(0,len(party_numbers)):
            if (party_numbers[j]) >0:
                first = chr(j + 65)
                save = j
                party_numbers[j] -= 1
                if party_numbers[j] == 0:
                    active_parties -= 1

                break
        for j in range(save+1, len(party_numbers)):
            if (party_numbers[j]) > 0:
                second = chr(j + 65)
                party_numbers[j] -= 1
                if party_numbers[j] == 0:
                    active_parties -= 1

        output += first+second+" "


    output = output[:-1]

    print("Case #{}: {}".format(i, output))