

# 3 5 5 7 8

# Naive implementation

def main():
    n, m = [int(i) for i in input().split()]
    tickets = sorted([int(i) for i in input().split()])
    customers = ([int(i) for i in input().split()])
    count = {}
    new_tickets = []
    for i in range(len(tickets)):
        if tickets[i] in count:
            count[tickets[i]] += 1
        else:
            count[tickets[i]] = 1
            new_tickets.append(tickets[i])
   
    tickets = new_tickets
    for i in range(len(customers)):
        prev = 0
        for j in range(len(tickets)):
            print(prev)
            if tickets[j] > customers[i]:
                if prev == 0 or count[prev] == 0:
                    print(-1)
                else:
                    print(prev)
                break
            else:
                if prev == 0 or count[prev] != 0:  
                    prev = tickets[j]
                    
                


print(main())