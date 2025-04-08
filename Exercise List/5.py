cases = int(input())

for i in range(cases):
    input()
    lista = map(int, input().split())
    lista.sort()
    print(*lista)