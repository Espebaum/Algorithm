def solution(myString):
    lst = myString.split('x')
    return [len(str) for str in lst]
