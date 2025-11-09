n, m = map(int, input().split())

no_hear_dict = dict()
no_hear_see_list = []

for i in range(n):
    no_hear_name = input()
    no_hear_dict[no_hear_name] = 1

for j in range(m):
    no_see_name = input()
    try:
        if no_hear_dict[no_see_name] == 1:
            no_hear_see_list.append(no_see_name)
    except KeyError:
        pass

# sort
no_hear_see_list.sort()

print(len(no_hear_see_list))
for no_hear_see_name in no_hear_see_list:
    print(no_hear_see_name)