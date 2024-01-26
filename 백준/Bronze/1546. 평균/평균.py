a = int(input())
scores = list(map(int,input().split()))

new_score = []
max_scores = max(scores)
for score in scores:
    new_score.append(score/max_scores*100)

print("% 0.5f" % (sum(new_score)/a))