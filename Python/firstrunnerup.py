if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())

    arrTmp = [x for x in arr if x < max(arr)]
    print(arrTmp)
