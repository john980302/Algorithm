n = int(input())

users = dict()

for _ in range(n):
    user, status = input().split()
    if status == 'enter':
        users[user] = status
    
    elif status == 'leave':
        users.pop(user, 'None')
    
users_name = list(users.keys())
users_name.sort(reverse=True)

for user in users_name:
    print(user)
