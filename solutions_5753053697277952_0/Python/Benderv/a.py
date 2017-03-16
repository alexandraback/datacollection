import itertools

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

t = int(input())

def evacuation(parties):
    if sum(parties.values()) == 0:
        return
    to_evac = []
    for p in parties:
        if parties[p] > (sum(parties.values()) - 1)/2:
            to_evac.append(p)
    if not to_evac:
        for p in parties:
            if parties[p] > 0:
                to_evac = p
            continue
    print(''.join(to_evac), end='')
    for s in to_evac:
        parties[s] -= 1
    print(' ', end='')
    return evacuation(parties)


for i in range(t):
  number_of_parties = input().strip()
  parties_pop = [int(i) for i in input().strip().split(' ')]

  parties = {alphabet[i]: p for i, p in enumerate(parties_pop)}
  print("Case #"+str(i+1)+": ", end="")
  evacuation(parties)
  print('')

