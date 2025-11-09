n, m = map(int, input().split())

poketmon_dict = dict()

for i in range(1, n + 1, 1):
    poketmon = input()
    poketmon_dict[poketmon] = i
    poketmon_dict[str(i)] = poketmon

for j in range(1, m + 1, 1):
    question = input()
    print(poketmon_dict[question])