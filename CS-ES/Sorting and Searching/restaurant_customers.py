times = []
for _ in range(int(input())):
	start, end = map(int, input().split())
	times.append((start, 1))
	times.append((end, -1))

times.sort()

curr_ppl = 0
max_ppl = 0

for t in times:
	curr_ppl += t[1]
	max_ppl = max(max_ppl, curr_ppl)

print(max_ppl)


# def main():
#     n = int(input())
#     actions = []
#     curr = 0
#     t_max = 0
#     for i in range(n):
#         begin, end = [int(x) for x in input().split()]
#         actions.append((begin, 1))
#         actions.append((end,-1))
#     actions.sort()
#     for i in range(n*2):
#         curr += actions[i][1]
#         t_max = max(curr, t_max)
            
    
#     return t_max
        
# print(main())
