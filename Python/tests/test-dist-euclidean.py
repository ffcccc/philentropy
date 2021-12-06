import numpy as np
import time

from philentropy import distances as dist
#
N=10000
P = np.random.normal(size = N)
Q = np.random.normal(size = N)

# Create n vectors of random numbers - length 10. This works ok.
start = time.time()

print("Timeit euclidean distance is computed fast ...")
dist.euclidean(P, Q, False)
end = time.time()
val = (end - start)
print(paste("Timing:", val))
