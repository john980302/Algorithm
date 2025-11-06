t = int(input())

# Quarter $0.25 = 25C
# Dime $0.10 = 10C
# Nickel $0.05 = 5C
# Penny $0.01 = 1C
for _ in range(t):
    d = int(input())
    quarter, d = d // 25, d % 25
    dime, d = d // 10, d % 10
    nickel, d = d // 5, d % 5
    penny, d = d // 1, d % 5
    print(quarter, dime, nickel, penny)
