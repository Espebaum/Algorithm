def solution(board, k):
    s = 0
    r = len(board)
    c = len(board[0])
    for i in range(r):
        for j in range(c):
            if i+j <= k:
                s += board[i][j]
    return s