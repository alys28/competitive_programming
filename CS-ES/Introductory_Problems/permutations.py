

def main():
    n = int(input()) 
    if n == 2 or n == 3:
        print("NO SOLUTION")
    else:
         # print evens
        j = 2
        while j <= n:
            print(j, end=" ")
            j += 2
        # print odds
        i = 1
        while i <= n:
            print(i, end=" ")
            i += 2
       



main()