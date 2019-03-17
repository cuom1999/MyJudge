from collections import defaultdict
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

write("nothing", [-1] * 9, [[-1] * 100 for i in range(10)], [(i+1, j+1) for i in range(100) for j in range(10)])

