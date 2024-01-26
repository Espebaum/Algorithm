a, b = map(list, input().split())

a.reverse()
b.reverse()

c = "".join(a)
d = "".join(b)
print(max(c,d))