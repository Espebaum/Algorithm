import sys
input = sys.stdin.readline

M = int(input())
s1 = set([])
s2 = set([i for i in range(1, 21)])

def add(x):
    if x in s1:
        pass
    else:
        s1.add(x)

def remove(x):
    if x not in s1:
        pass
    else:
        s1.remove(x)

def check(x):
    if x in s1:
        print(1)
    else:
        print(0)
    
def toggle(x):
    if x in s1:
        s1.remove(x)
    else:
        s1.add(x)

def all():
    s1.clear()
    s1.update(s2)

def empty():
    s1.clear()

for _ in range(M):
    command = input().split()
    if command[0] == 'add':
        add(int(command[1]))
    elif command[0] == 'remove':
        remove(int(command[1]))
    elif command[0] == 'check':
        check(int(command[1]))
    elif command[0] == 'toggle':
        toggle(int(command[1]))
    elif command[0] == 'all':
        all()
    elif command[0] == 'empty':
        empty()