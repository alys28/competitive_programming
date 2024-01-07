
def main():
    n = int(input())
    result = 0
    while n >= 5:  
        n = n // 5
        result += n
    return result


print(main())


# def main2():
#     n = int(input())
#     fact = 1
#     for i in range(1, n+1):
#         fact = fact * i
#     strFact= str(fact)
#     i = 0
#     while strFact[-i-1] == "0":
#         i += 1
#     return i
 
 
# print(main2())