def bubble_sort(l):
    num_swaps = 0
    for i in range(len(l)):
        swap = False
        for j in range(0, len(l) - 1 - i):
            if l[j] > l[j + 1]:
                l[j], l[j + 1] = l[j + 1], l[j]
                swap = True
                num_swaps += 1
        if not swap:
            return num_swaps
    return num_swaps

num_cases = int(input())

for i in range(num_cases):
    num_trains = int(input())
    trains = list(map(int, input().split()))
    print(f"Optimal train swapping takes {bubble_sort(trains)} swaps.")