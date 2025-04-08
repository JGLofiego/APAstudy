from itertools import product

try:
    while True:
        n, m = map(int, input().split())

        pesos = list(map(int, input().split()))

        possible_combinations = list(product(range(1, m + 1), repeat=n))

        possible_results = []
        value = 0

        for i in range(len(possible_combinations)):
            value = 0
            for j in range(n):
                value += possible_combinations[i][j] * pesos[j]

            check = value in possible_results
            
            if check:
                print("Try again later, Denis...")
                break
            else:
                possible_results.append(value)

        if not check:
            print("Lucky Denis!")
except (EOFError):
    exit()