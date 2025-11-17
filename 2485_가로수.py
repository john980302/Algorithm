from math import gcd

n = int(input())

start_tree = int(input())
diff_distance = []
for i in range(1, n, 1):
    end_tree = int(input())
    diff_distance.append(end_tree - start_tree)
    start_tree = end_tree

# 최대공약수를 구해서 해당 값으로 나눌까
diff_gcd = gcd(*diff_distance)

result = 0
for diff_distance_i in diff_distance:
    result += diff_distance_i // diff_gcd - 1

print(result)