n = int(input())
v = list(map(int, input().split()))
moves = 0

for i in range(1, n):
    if v[i - 1] > v[i]:
        moves += v[i - 1] - v[i]

print(moves)