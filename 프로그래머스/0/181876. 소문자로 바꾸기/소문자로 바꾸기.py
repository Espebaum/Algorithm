def solution(myString):
    return ''.join([chr(ord(c) + 32) if 'A' <= c <= 'Z' else c for c in myString])
    # return ''.join([chr(ord(c) + 32) for c in myString if 'A' <= c <= 'Z']) # 틀림