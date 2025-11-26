from queue import *

n, m = map(int, input().split())

res_x = n // 5 * 2
res_y = m // 5 * 2

n %= 5
m %= 5

parents = [[(-1, -1) for i in range(0, 10)] for j in range(0, 10)]

parents[0][0] = (0, 0)

q = Queue()
q.put((0, 0))

mov_set = [[1, 2], [2, 1]]

while not q.empty():
    cur_x, cur_y = q.get()

    for dx, dy in mov_set:
        next_cur_x = cur_x + dx
        next_cur_y = cur_y + dy
        if (next_cur_x < 10) : #проверка что остались внутри поля
            pass
        if (parents[next_cur_x][next_cur_y] ==(-1, -1)):
            continue
        parents[next_cur_x][next_cur_y] = (cur_x, cur_y)
        q.put((next_cur_x, next_cur_y))


