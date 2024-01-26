a = []

for i in range(10):
    a.append(int(input()))

b = [0] * 42
for x in a:
    b[x % 42] = 1
print(sum(b))