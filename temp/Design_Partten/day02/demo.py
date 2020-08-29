# 设计思路
# 设计两个类：Rater和Palyer
# 属性方法设置：
# Rater：
#   grade_by_avg()
#   grade_by_no_max_min()
#   grade_by_median()
#   grade_by_statistical()
#
# Player:
#   scores[10]
#   name
#   id
#   final_score
#   ranking
#   __str__
import random

NUMBERS_PLAYER = 10
NUMBERS_RATER = 10
MAX_SCORE = 10
MIN_SCORE = 0


class Palyer():
    scores = []
    name = ''
    id = 0
    final_score = 0
    ranking = 0

    def __init__(self, name, id):
        ran = random.Random()
        self.scores = [ran.randint(MIN_SCORE, MAX_SCORE)
                       for i in range(NUMBERS_RATER)]
        self.scores = sorted(self.scores)
        self.name = name
        self.id = id

    def __str__(self):
        return 'id: ' + str(self.id) + ' name: ' + self.name + ' scores: ' + ' '.join(list(map(str, self.scores))) + ' final_score: ' + str(self.final_score) + ' rank: ' + str(self.ranking)


class Rater:

    def __print__(self, players):
        for p in players[::-1]:
            print(p)

    def __calculate__(self, players):
        players = sorted(players, key=lambda x: x.final_score)
        for i in range(1, len(players)+1):
            players[i-1].ranking = 10-i+1
        self.__print__(players)
    # 按平均数判定

    def grade_by_avg(self, players):
        for player in players:
            player.final_score = sum(player.scores)/NUMBERS_RATER
        self.__calculate__(players)
    # 按去除极值求平均数判定

    def grade_by_no_max_min(self, players):
        for player in players:
            player.final_score = sum(
                player.scores[1:NUMBERS_RATER-1])/NUMBERS_RATER
        self.__calculate__(players)
    # 按众数判定

    def grade_by_median(self, players):
        for player in players:
          # 因为下标中0 开始，因此需要-1
            player.final_score = player.scores[NUMBERS_RATER//2 - 1] if NUMBERS_RATER % 2 == 1 else (
                player.scores[NUMBERS_RATER//2] + player.scores[NUMBERS_RATER//2-1])/2
        self.__calculate__(players)

    # 按最大众数判定
    def grade_by_statistical(self, players):
        for player in players:
            temp = [0 for i in range(0, MAX_SCORE+1)]
            for i in player.scores:
                temp[i] += 1
            max = 0
            max_index = 0
            for i in range(0, len(temp)):
              # 此处 <= 为按最大众数判断
              #       < 为按最小众数判断
                if max <= temp[i]:
                    max = temp[i]
                    max_index = i
            player.final_score = max_index
        self.__calculate__(players)
        pass


if __name__ == "__main__":
    players = [Palyer('player'+str(i), i) for i in range(1, NUMBERS_PLAYER+1)]
    print('-----------------------------------------------------------------')
    print('学生分数：')
    for p in players:
        print(p)
    print('-----------------------------------------------------------------')
    rater = Rater()
    print('-----------------------------------------------------------------')
    print('按平均数判断：')
    rater.grade_by_avg(players)
    print('-----------------------------------------------------------------')
    print('-----------------------------------------------------------------')
    print('按去除极值平均数判断：')
    rater.grade_by_no_max_min(players)
    print('-----------------------------------------------------------------')
    print('-----------------------------------------------------------------')
    print('按中位数判断：')
    rater.grade_by_median(players)
    print('-----------------------------------------------------------------')
    print('-----------------------------------------------------------------')
    print('按最大众数判断：')
    rater.grade_by_statistical(players)
    print('-----------------------------------------------------------------')
