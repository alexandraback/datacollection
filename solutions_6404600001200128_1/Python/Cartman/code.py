for case in range(int(raw_input())):
    n = int(raw_input())
    states = map(int, raw_input().split(' '))

    nr_eaten = [(states[i-1] - states[i])*(states[i] <= states[i-1]) for i in range(1,n)]
    res_method1 = sum(nr_eaten)
    maxRate = max(nr_eaten)
    res_method2 = sum([min([states[i], maxRate]) for i in range(n-1)])

    print 'Case #%s: %s %s' % (case + 1, res_method1, res_method2)
