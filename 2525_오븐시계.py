# 입력
time, minute = map(int, input().split())
cook_minute = int(input())

# 오븐 시간 계산
minute = minute + cook_minute

time = time + minute // 60
minute = minute % 60

time = time % 24

# 출력
print(time, minute)