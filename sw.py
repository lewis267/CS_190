import bisect

first_line = input()
(n, k) = tuple(map(int, first_line.split()))

class sorted_list:
    def __init__(self, items):
        self.items = sorted(items, reverse=True)

    def shift(self, new, old):
        self.items.remove(old)
        bisect.insort(self.items, new)

    def max(self):
        return self.items[0]

all_items = list(map(int, input().split()))
all_items.append(0)

for start in range(n - k + 1):
    window = all_items[start : start + k]
    window = sorted_list(window)

    print(window.max())
    window.shift(all_items[start+k], all_items[start])
    
