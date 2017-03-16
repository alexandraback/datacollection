num_case = int(input())
for case_t in range(1, num_case+1):
    N = int(input())
    Input = [int(i) for i in input().split(" ")]
    Parties = {chr(ord('A')+i): Input[i] for i in range(len(Input))}

    Res = []
    while len(Parties) > 0:
        OUT = []
        pre_len = len(Parties)
        for i in range(2):
            if pre_len > 2 and len(Parties) <= 2: break
            shd_out = sorted(Parties, key = Parties.get, reverse = True)[0]
            out1 = shd_out[0]
            Parties[out1] -= 1
            if Parties[out1] == 0: del Parties[out1]
            OUT.append(out1)
        Res.append(''.join(OUT))
    ANS = ' '.join(Res)
    print("Case #%d: %s"%(case_t, ANS))

