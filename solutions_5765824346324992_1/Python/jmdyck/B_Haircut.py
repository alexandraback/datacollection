#!/usr/bin/python

import sys, math

INPUT = sys.stdin
INPUT = open(sys.argv[1],'r')

def getline():
    return INPUT.readline()[:-1]

class Bunch:
    def __init__( self, **kwds ):
        self.__dict__ = kwds


pause_after_trace = False
def mtrace(*strs):
    return
    atrace(*strs)

def atrace(*strs):
    f = sys.stderr
    print >> f, '..',
    for str in strs:
        print >> f, str,
    print >> f
    if pause_after_trace:
        response = raw_input('? ')
        if response == 'q':
            sys.exit(1)

def memoize(f):
    memos = {}
    def memoized_f( *args ):
        try:
            result = memos[args]
            mtrace(args, ": got result from memo")
        except KeyError:
            result = f(*args)
            mtrace(args, ": got result by calling")
            memos[args] = result
        return result
    return memoized_f

# ------------------------------------------------------------------------------

n_cases = int(getline())
mtrace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    mtrace()
    atrace( 'Case #', case_num )

    (n_barbers, my_place_in_line) = map(int,getline().split())
    duration_for_barber_ = map(int, getline().split())
    assert len(duration_for_barber_) == n_barbers

    def solve():

        mtrace("my_place_in_line =", my_place_in_line)
        mtrace("n_barbers =", n_barbers)
        mtrace("duration_for_barber_ =", duration_for_barber_)

        if my_place_in_line <= n_barbers:
            return my_place_in_line

        # There are my_place_in_line-1 people ahead of me.
        #
        # I will be served when a barber finishes.
        # In general, the other n_barbers-1 barbers will still be busy,
        # and so (my_place_in_line-1) - (n_barbers-1) people
        # have been completed.

        D = (my_place_in_line-1) - (n_barbers-1)
        assert D > 0
        mtrace("need to complete", D, "cuts")

        # So figure out what state the shop is in when that occurs,
        # i.e. when the shop finishes its n_done'th haircut.

        speed_for_barber_ = [ 1/float(d) for d in duration_for_barber_ ]
        mtrace("speed_for_barber_ =", speed_for_barber_ )

        total_speed_of_shop = sum(speed_for_barber_)
        mtrace("total_speed_of_shop =", total_speed_of_shop, "(customers/minute)")

        min_time_to_do_D = D / total_speed_of_shop
        mtrace("min_time_to_do_D =", min_time_to_do_D)
        # But that's the time to do D haircuts
        # *including* haircuts-in-progress.
        # In general, it'll take longer to finish D customers.

        T = int(math.floor(min_time_to_do_D))
        mtrace('rounded down =', T)

        # At that time, what state is each barber in?
        mtrace('at that time...')
        total_n_done = 0
        for (i,d) in enumerate(duration_for_barber_):
            n_completed = T / d
            n_minutes_in = T % d
            mtrace('   barber', i+1, 'has finished', n_completed, 'customers and is', n_minutes_in, 'minutes into the next')
            total_n_done += n_completed
        mtrace('total_n_done =', total_n_done)
        remaining = D - total_n_done
        mtrace('remaining =', remaining)

        events = []

        for (i,d) in enumerate(duration_for_barber_):
            n_completed = T / d
            n_minutes_in = T % d
            if n_completed > 0:
                events.append( (n_completed*d, i+1, n_completed) )

            # if this barber alone
            for c in range(n_completed+1, n_completed+remaining+2):
                events.append( (c*d, i+1, 1) )

        events.sort()

        total_n_done = 0
        for (t, bn, nc) in events:
            total_n_done += nc
            mtrace(
                'at time', t,
                'barber', bn,
                'completes', nc,
                'for a total of', total_n_done,
                'and seats cust #', total_n_done + n_barbers)

            if total_n_done + n_barbers == my_place_in_line:
                mtrace("that's me, so returning barber #", bn)
                return bn

        assert 0

    n = solve()

    print 'Case #%d: %s' % (case_num, n)
    sys.stdout.flush()

assert INPUT.readline() == ''

# vim: sw=4 ts=4 expandtab
