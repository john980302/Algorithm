n = int(input())
s_cards = list(map(int, input().split()))
s_dict = {s_card: 1 for s_card in s_cards}
m = int(input())
check_cards = map(int, input().split())

for check_card in check_cards:
    try:
        print(s_dict[check_card], end=' ')
    except KeyError:
        print(0, end=' ')