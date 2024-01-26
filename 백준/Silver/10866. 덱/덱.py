import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
stack = deque([])

def push_front(x):
    stack.appendleft(int(x))

def push_back(x):
    stack.append(x)

def pop_front():
    if len(stack) == 0:
        print(-1)
    else:
        print(stack.popleft())

def pop_back():
    if len(stack) == 0:
        print(-1)
    else:
        print(stack.pop())

def size():
    print(len(stack))

def empty():
    if len(stack) == 0:
        print(1)
    else: 
        print(0)

def front():
    if len(stack) == 0:
        print(-1)
    else:
        print(stack[0])

def back():
    if len(stack) == 0:
        print(-1)
    else:
        print(stack[-1])


for _ in range(N):
    command = input().split()
    if command[0] == 'push_front':
        push_front(command[1])
    elif command[0] == 'push_back':
        push_back(command[1])
    elif command[0] == 'pop_front':
        pop_front()
    elif command[0] == 'pop_back':
        pop_back()
    elif command[0] == 'size':
        size()
    elif command[0] == 'empty':
        empty()
    elif command[0] == 'front':
        front()
    elif command[0] == 'back':
        back()