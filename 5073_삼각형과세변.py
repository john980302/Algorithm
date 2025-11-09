while True:
    x, y, z = map(int, input().split())
    
    # end condition
    if x == y and y == z and x == 0:
        break

    # Invalid
    if max([x, y, z]) * 2 >= sum([x, y, z]):
        print('Invalid')
    
    # Equilateral :  세 변의 길이가 모두 같은 경우
    elif x == y and y == z:
        print('Equilateral')

    # Isosceles : 두 변의 길이만 같은 경우
    elif x == y or y == z or x == z:
        print('Isosceles')

    # Scalene : 세 변의 길이가 모두 다른 경우
    else:
        print('Scalene')