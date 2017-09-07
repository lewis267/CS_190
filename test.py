def gcd(a, b):
    while b:
        a,b = b,a%b
    return a

def reduce(res):
    GCD = gcd(res[0], res[1])
    while GCD > 1 and res[0] >= 1:
        res = (res[0]/GCD, res[1]/GCD)
        GCD = gcd(res[0], res[1])
    return res
        
def mediant(a, b):
    if a == None or b == None:
        return (None, None)
    return reduce((a[0]+b[0],a[1]+b[1]))
    
class Node:
    def __init__(self, lhs, rhs):
        if type(lhs) is int or type(rhs) is int:
            self.value = reduce((lhs, rhs))
            self.lhs = None
            self.rhs = None
        else:
            self.value = mediant(lhs.value, rhs.value)
            self.lhs = lhs
            self.rhs = rhs
        
    def right(self):
        return Node(self, self.rhs)
    
    def left(self):
        return Node(self.lhs, self)

    def eval(self):
        return float(self.value[0])/float(self.value[1])

def nearest_common_ancestor(root, a, b):
    root_val = root.eval()
    a_val = a.eval()
    b_val = b.eval()
    
    if (root_val > a_val and root_val > b_val):
        return nearest_common_ancestor(root.left(), a, b)

    if (root_val < a_val and root_val < b_val):
        return nearest_common_ancestor(root.right(), a, b)

    return root

def fca(a, b):
    root = Node(Node(0,1), Node(1,0))
    a = Node(a[0], a[1])
    b = Node(b[0], b[1])
    result = nearest_common_ancestor(root, a, b)
    return result.value

if __name__ == '__main__':
    count=int(input())
    output = []
    for i in range(count):
        vals = list(map(int, input().split()))
        res = fca((vals[0], vals[2]),(vals[1], vals[3]))
        output.append(str(res[0])+'/'+str(res[1]))
        
    for i in range(count):
        print(output[i])
