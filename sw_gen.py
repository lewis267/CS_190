import random
from datetime import datetime
random.seed(datetime.now())
n = random.randint(1, 2 * 10000)
k = random.randint(1, n)
print(n, k)
for i in range(n):
    print(random.randint(-10000, 10000), end=' ')
print()
