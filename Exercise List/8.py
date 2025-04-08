import sys

sys.setrecursionlimit(5000)

def int_list(valor):
    return [int(valor), False]

def procura(matrix, visited, i=0, j=0):
    if i >= 0 and i < 5 and j >= 0 and j < 5:
        visited[i][j] = True
        if i == 4 and j == 4:
            return True
        else:
            
            print(i, j)
            
            result = False
            
            if j + 1 < 5 and matrix[i][j + 1] == 0 and not visited[i][j + 1]:
                result = result or procura(matrix, i, j + 1)
                if result:
                    return result
                
            if i + 1 < 5 and matrix[i + 1][j] == 0 and not visited[i + 1][j]:
                result = result or procura(matrix, i + 1, j)
                if result:
                    return result
            
            if i - 1 >= 0 and matrix[i - 1][j] == 0 and not visited[i - 1][j]:
                result = result or procura(matrix, i - 1, j)
                if result:
                    return result
                
            if j - 1 >= 0 and matrix[i][j - 1] == 0 and not visited[i][j - 1]:
                result = result or procura(matrix, i, j - 1)
                if result:
                    return result
            
            return result
            

matrix = [None] * 5

visited = [[False] * 5] * 5

print(*visited)

cases = int(input())

for i in range(cases):
    input()
    for j in range(5):
        matrix[j] = list(map(int, input().split()))

    if(procura(matrix, visited)):
        print("COPS")
    else:
        print("ROBBERS")
