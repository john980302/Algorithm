n, m = map(int, input().split())

my_dict = {}
for _ in range(n):
    word = input()
    my_dict[word] = 1

result = 0
for _ in range(m):
    check_word = input()

    try:
        if my_dict[check_word] == 1:
            result += 1
    except KeyError:
        pass

print(result)