


def main():
    n = int(input())
    actions = []
    curr = 0
    t_max = 0
    for i in range(n):
        begin, end = [int(x) for x in input().split()]
        actions.append((begin, 1))
        actions.append((end,-1))
    actions.sort()
    for i in range(n*2):
        curr += actions[i][1]
        t_max = max(curr, t_max)
            
    
    return t_max
        
print(main())
