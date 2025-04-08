def swap(nomes, steps):
    for i in range(len(nomes)):
        min_index = i
        for j in range(i + 1, min(i + steps + 1, len(nomes))):
            if nomes[j] < nomes[min_index]:
                min_index = j

        for j in range(min_index, i, -1):
            nomes[j], nomes[j - 1] = nomes[j - 1], nomes[j]
            steps -= 1

            if steps <= 0:
                break

        if steps <= 0:
            break

instancia = 1

while True:
    num_nomes, steps = map(int, input().split())

    if num_nomes == steps == 0:
        break

    nomes = input().split()
    
    swap(nomes, steps)

    print(f"Instancia {instancia}")
    print(*nomes, "\n")

    instancia += 1