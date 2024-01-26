S = list(input())

alphabet = [0] * 26
for i in range(26):
    alphabet[i] = chr(i + 97)

for x in alphabet:
    if x in S:
        print(S.index(x), end = ' ')
    else:
        print(-1, end = ' ')
