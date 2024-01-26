N = int(input())
words = []

for _ in range(N):
    words.append(input())

a = list(set(words))
a.sort()
a.sort(key=len)
for i in a:
    print(i)