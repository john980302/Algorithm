
ll = []
for i in range(5):
    x = int(input())
    ll.append(x)


ll.sort()

print(int(sum(ll)/5))
print(ll[2])