p = 28151

def is_primitive(g):
    for i in range(1, p - 1):
        if pow(g, i, p) == 1:
            return False
    return True

g = 2
while not is_primitive(g):
    g += 1

print("The smallest primitive element g is:", g)