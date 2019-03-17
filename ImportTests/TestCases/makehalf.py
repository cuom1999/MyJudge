from random import randint, uniform, seed
seed(42)
from collections import defaultdict
from fractions import Fraction as F
import sys

bybase = defaultdict(int)

def write(basename, inflation, prices, queries, answer = None):
    bybase[basename] += 1
    testcase = bybase[basename]
    if answer:
        print "cat > %s%03d.ans << EOF" % (basename, testcase)
        for a in answer:
            print "%.10f" % (a)
        print "EOF"

    print "cat > %s%03d.in << EOF" % (basename, testcase)

    print "%d %d %d" % (len(inflation) + 1, len(prices[0]), len(queries))
    for i in range(len(inflation)):
        print "%.10f" % inflation[i]
    for i in range(len(prices)):
        print " ".join(map(lambda p : "%.10f" % (p), prices[i]))
    for a, b in queries:
        print a, b
    print "EOF"

def make_base_mod_price(y, c, inflationrange, yearrange, modrange):
    realinflation = [uniform(*inflationrange) for yy in range(y-1)]
    inflationmultiplier = [1]
    for i in realinflation:
        inflationmultiplier.append(inflationmultiplier[-1] * i)
    year0 = [uniform(*yearrange) for i in range(c)]
    modifier = [uniform(*modrange) for i in range(c)]
    realprices = [[modifier[cc]**(yy) * year0[cc] * inflationmultiplier[yy] for cc in range(c)] for yy in range(y)]
    assert all(all(_p < 1000000.0 for _p in pp) for pp in realprices)
    if not all(all(1 < _p for _p in pp) for pp in realprices):
        print realprices
    assert all(all(1 < _p for _p in pp) for pp in realprices)
    return realinflation, year0, modifier, realprices

def makenoinflationgiven(y, c, inflationrange, yearrange, modrange):
    realinflation, year0, modifier, realprices = make_base_mod_price(y, c, inflationrange, yearrange, modrange)

    needtoknow = 2 * c + y - 1
    candelete = y * c - needtoknow
    leftincol = [y] * c
    queries = []
    answer = []
    LEAVE_IN_COLUMN = 3
    while len(queries) < candelete and not all(leftincol[col] <= LEAVE_IN_COLUMN for col in range(c)):
        col = randint(0, c-1)
        if leftincol[col] > LEAVE_IN_COLUMN:
            while True:
                yy = randint(0, y-1)
                if realprices[yy][col] != -1:
                    break
            leftincol[col] -= 1
            answer.append(realprices[yy][col])
            realprices[yy][col] = -1
            queries.append((col+1,yy+1))

    inflation = [-1 for yy in range(y-1)]
    return inflation, realprices, queries, answer

# 
# make what may or may not be unique solutions
#
def makewhoknowswhat(y, c, infrange = (1.0, 1.5), yearrange = (1, 5), modrange = (1, 2.5), fraction = F(1, 2)):
    realinflation, year0, modifier, realprices = make_base_mod_price(y, c, infrange, yearrange, modrange)
    inflation = realinflation

    inflationdeleted = randint(0, y-1)
    needtoknow = 2 * c + y - 1 - inflationdeleted
    candelete = y * c * fraction
    leftincol = [y] * c
    queries = []
    while inflation.count(-1) < inflationdeleted:
        i = randint(0, len(inflation)-1)
        inflation[i] = -1.0

    while len(queries) < candelete:
        col = randint(0, c-1)
        if leftincol[col] > 0:
            while True:
                yy = randint(0, y-1)
                if realprices[yy][col] != -1:
                    break
            leftincol[col] -= 1
            realprices[yy][col] = -1
            queries.append((col+1,yy+1))

    # None means I don't know the answer here.
    return inflation, realprices, queries, None

def makeallknown(y, c, infrange = (1.0, 1.5), yearrange = (1, 5), modrange = (1, 2.5)):
    realinflation, year0, modifier, realprices = make_base_mod_price(y, c, infrange, yearrange, modrange)
    inflation = realinflation
    answers = []
    queries = []
    for yy in range(y):
        for cc in range(c):
            queries.append((cc+1, yy+1))
            answers.append(realprices[yy][cc])

    return inflation, realprices, queries, answers

for i in range(5):
    write("partial", *makewhoknowswhat(10, 100, infrange = (1.4, 1.5), yearrange = (1, 10), modrange = (1, 2.4), fraction = F(3+i, 10)))

write("allknown", *makeallknown(10, 100, infrange = (1.4, 1.5), yearrange = (1, 10), modrange = (1, 2.4)))

write("large-inflation", *makenoinflationgiven(10, 100,
                        inflationrange = (1e10, 1.0e10), 
                        yearrange = (999900, 999999), 
                        modrange = (1e-10, 1e-10)))

write("extreme-inflation", *makenoinflationgiven(10, 100,
                        inflationrange = (1e20, 1.0e20), 
                        yearrange = (999900, 999999), 
                        modrange = (1e-20-5e-21, 1e-20)))

