import random
from datetime import datetime
random.seed(datetime.now())
lines = random.randint(1,10000)
print(lines)
for i in range(lines):
    A1 = random.randint(1, 100)
    A2 = random.randint(1, 100)
    B1 = random.randint(1, 100)
    B2 = random.randint(1, 100)
    print(A1, A2, B1, B2)
