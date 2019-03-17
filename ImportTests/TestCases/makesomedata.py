#
# make test cases
#
from random import randint, uniform, seed
seed(42)
from collections import defaultdict
import sys

bybase = defaultdict(int)

def write(basename, inflation, prices, queries, answer):
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
    assert all(all(1 < _p for _p in pp) for pp in realprices)
    return realinflation, year0, modifier, realprices

# 
# make what should be unique solutions for all commodities
# without making any of the inflation rates known
# The idea is to make sure each commodity/column has at least 3 values.
#
def makenoinflationgiven(y, c):
    realinflation, year0, modifier, realprices = make_base_mod_price(y, c, (1.0, 1.5), (1, 5), (1, 2.5))

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
# make what should be unique solutions for all commodities
# when all inflation rates are given
# The idea is to make sure each commodity/column has at least 2 values.
#
def makeinflationgiven(y, c):
    realinflation, year0, modifier, realprices = make_base_mod_price(y, c, (1.0, 1.5), (1, 5), (1, 2.5))
    assert all(all(1 <= p <= 1000000 for p in row) for row in realprices)
    inflation = realinflation

    needtoknow = 2 * c
    candelete = y * c - needtoknow
    leftincol = [y] * c
    queries = []
    answer = []
    LEAVE_IN_COLUMN = 2
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

    return inflation, realprices, queries, answer

# 
# make what may or may not be unique solutions
#
def makewhoknowswhat(y, c, infrange = (1.0, 1.5), yearrange = (1, 5), modrange = (1, 2.5)):
    realinflation, year0, modifier, realprices = make_base_mod_price(y, c, infrange, yearrange, modrange)
    inflation = realinflation

    inflationdeleted = randint(0, y-1)
    needtoknow = 2 * c + y - 1 - inflationdeleted
    candelete = y * c - needtoknow
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

###########################################################################################################33
#
# toy
write("no-inflation-given", *makenoinflationgiven(4, 4))
# full size
for i in range(9):
    write("no-inflation-given", *makenoinflationgiven(10, 100))

write("inflation-given", *makeinflationgiven(4, 4))
for i in range(9):
    write("inflation-given", *makeinflationgiven(10, 100))

write("random", *makewhoknowswhat(4, 4))
for i in range(9):
    write("random", *makewhoknowswhat(10, 100))

write("randombig", *makewhoknowswhat(10, 100, infrange = (1.4, 1.5), yearrange = (1, 10), modrange = (1, 2.4)))
write("randombig", *makewhoknowswhat(10, 100, infrange = (1.4, 1.5), yearrange = (1, 10), modrange = (1, 2)))
write("randombig", *makewhoknowswhat(10, 100, infrange = (1.4, 1.5), yearrange = (1, 10), modrange = (1, 2.4)))
