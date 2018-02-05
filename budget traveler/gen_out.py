import sys, time
from subprocess import call

if len(sys.argv) != 2:
    exit(1)

nTest = int(sys.argv[1])
for i in range(1, nTest+1):
    startTime = time.time()
    
    call(["./bin/sol"],
        stdin = open("data/" + str(i) + ".in"),
        stdout = open("data/" + str(i) + ".ans", 'w+')
    )

    endTime = time.time()
    print("Test case #%2d: %0.4f s" % (i, endTime - startTime))
