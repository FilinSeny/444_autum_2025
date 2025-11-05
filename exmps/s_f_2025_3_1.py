n = int(input())

breaks = []

for i in range(n):
    s, f = input().split('-')
    sh, sm = map(int, s.split(':'))
    s = sh * 60 + sm
    fh, fm = map(int, f.split(':'))
    f = fh * 60 + fm
    breaks.append((s, f))

work_time = 0
need_rest = 0

now = 10 * 60

for s, f in breaks:
    work_time += (s - now) // 30 * 20
    work_time += min((s - now) % 30, 20)
    need_rest = 10
    need_rest -= max(0, (s - now) % 30 - 20)

    need_rest -= min(need_rest, f - s)
    now = f

time_end = 19 * 60
work_time += (time_end - now) // 30 * 20
work_time += min((time_end - now) % 30, 20)

print(work_time)

