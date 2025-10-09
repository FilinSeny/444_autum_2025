G1 = [[1],
      [2, 3],
      [0], 
      [4], 
      [5],
      [3]]

RG = [[1],
      [2],
      [0], 
      [4, 1], 
      [5],
      [3]]

order = []
used = [0] * 6

def dfs1(cur):
    used[cur] = 1
    for next in G1[cur]:
        if not used[next]:
            dfs1(next)

    order.append(cur)

dfs1(0)

order = reversed(order)

components = []
used = [0] * 6

def dfs2(cur, i):
    used[cur] = 1
    for next in RG[cur]:
        if not used[next]:
            dfs2(next, i)

    components[i].append(cur)


for i in order:
    if not used[i]:
        components.append([])
        dfs2(i, len(components) - 1)

print(components)
