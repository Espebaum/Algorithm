a = list(input())

l_a = []
for i in a:
    l_a.append(ord(i.lower()))

bin = [0] * max(l_a)
for i in l_a:
    bin[i-1] += 1

jb = list(filter(lambda x: bin[x] == max(bin), range(len(bin))))

if len(jb) >= 2:
    print('?')
elif len(jb) == 1:
    print(chr(jb[0]+1).upper())
