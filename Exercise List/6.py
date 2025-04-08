def energy(floors, limit, acc=0):
    if len(floors) == 0:
        return acc
        
    acc = energy(floors[limit:], limit, acc + floors[0] * 2)
    
    return acc

cases = int(input())

for i in range(cases):
    num_floors, max_people, num_people = map(int, input().split())
    
    floors = list(map(int, input().split()))
    floors.sort(reverse=True)
    
    min_energy = energy(floors, max_people)
    print(min_energy)
