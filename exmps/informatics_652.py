n = 1000
table = [['#' for i in range(n)] for i in range(n)]
step = [[-1, 0], [1, 0], [0, 1], [0, -1]]
used = [[0 for i in range(n)] for i in range(n)]

def dfs (x, y):
    used[y][x] = 1
    for i, j in step:
        if (x + j < 0 or x + j >= n or y + i < 0 or y + i >= n):
            continue
        dfs(x + j, y + i)