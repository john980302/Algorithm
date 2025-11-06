score_dict = {
    'A+': 4.5,
    'A0': 4.0,
    'B+': 3.5,
    'B0': 3.0,
    'C+': 2.5,
    'C0': 2.0,
    'D+': 1.5,
    'D0': 1.0,
    'F': 0.0,
}

n = 20
subject_score = 0
total_score = 0
for _ in range(n):
    name, score, grade = input().split()
    if grade != 'P':
        total_score += score_dict[grade] * float(score)
        subject_score += float(score)
print(total_score / subject_score)