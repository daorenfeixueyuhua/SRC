import math
import random
import os
fd = os.open("./Python/algorithm/GA/f1.txt", os.O_RDWR | os.O_CREAT)
        # os.write(fd, bytes('我是你爸爸', encoding='UTF-8'))


class Population(object):
    # 种群的设计
    def __init__(self, size, chrom_size, cp, mp, gen_max):
        # 种群信息合
        self.individuals = []          # 个体集合
        self.fitness = []              # 个体适应度集
        self.selector_probability = []  # 个体选择概率集合
        self.new_individuals = []      # 新一代个体集合

        self.elitist = {'chromosome': [0, 0],
                        'fitness': 0, 'age': 0}  # 最佳个体的信息

        self.size = size  # 种群所包含的个体数
        self.chromosome_size = chrom_size  # 个体的染色体长度
        # 个体之间的交叉概率
        self.crossover_probability = cp
        self.mutation_probability = mp    # 个体之间的变异概率

        self.generation_max = gen_max  # 种群进化的最大世代数
        self.age = 0                  # 种群当前所处世代

        # 随机产生初始个体集，并将新一代个体、适应度、选择概率等集合以 0 值进行初始化
        v = 2 ** self.chromosome_size - 1
        for i in range(self.size):
            self.individuals.append(
                [random.randint(0, v), random.randint(0, v),  random.randint(0, v),  random.randint(0, v)])
            self.new_individuals.append([0, 0, 0, 0])
            self.fitness.append(0)
            self.selector_probability.append(0)
    # def __str__(self):
    #   return '种群个数: ' + str(self.size) + '\n'
    #         + '个体染色体长度: ' + str(self.chromosome_size) + '\n'
    #         + '个体之间的交叉概率: ' + str(self.crossover_probability) +'\n'
    #         + '个体之间的变异概率: ' + str(self.mutation_probability)+'\n'
    #         + '种群进化的最大世代数: ' + str(self.generation_max)+'\n'
      

    # 基于轮盘赌博机的选择
    # interval 区间
    # chromosome 染色体
    def decode(self, interval, chromosome):
        '''将一个染色体 chromosome 映射为区间 interval 之内的数值'''
        d = interval[1] - interval[0]
        n = float(2 ** self.chromosome_size - 1)
        return (interval[0] + chromosome * d / n)

    # 此处需要进行修改
    def fitness_func(self, chrom1, chrom2, chrom3, chrom4):
        '''适应度函数，可以根据个体的两个染色体计算出该个体的适应度'''
        interval = [-5.0, 5.0]
        # (x, y) = (self.decode(interval, chrom1),
        #           self.decode(interval, chrom2))

        # def n(x, y): return math.sin(math.sqrt(x*x + y*y)) ** 2 - 0.5
        # def d(x, y): return (1 + 0.001 * (x*x + y*y)) ** 2
        # def func(x, y): return 0.5 - n(x, y)/d(x, y)
        (x1, x2, x3, x4) = (self.decode(interval, chrom1),
                            self.decode(interval, chrom2),
                            self.decode(interval, chrom3),
                            self.decode(interval, chrom4))
        # print((x1, x2, x3, x4))
        def func(x1, x2, x3, x4): return 1/(x1*x1+x2*x2+x3*x3+x4*x4+1)
        return func(x1, x2, x3, x4)

    def evaluate(self):
        '''用于评估种群中的个体集合 self.individuals 中各个个体的适应度'''
        sp = self.selector_probability
        for i in range(self.size):
            self.fitness[i] = self.fitness_func(self.individuals[i][0],   # 将计算结果保存在 self.fitness 列表中
                                                self.individuals[i][1],
                                                self.individuals[i][2],
                                                self.individuals[i][3])
            # print('个体', i, '中适应度=', self.fitness[i])
        ft_sum = sum(self.fitness)
        for i in range(self.size):
            sp[i] = self.fitness[i] / float(ft_sum)   # 得到各个个体的生存概率
        for i in range(1, self.size):
            sp[i] = sp[i] + sp[i-1]   # 需要将个体的生存概率进行叠加，从而计算出各个个体的选择概率

    # 轮盘赌博机（选择）
    def select(self):
        (t, i) = (random.random(), 0)
        for p in self.selector_probability:
            if p > t:
                break
            i = i + 1
        return i

    # 交叉
    def cross(self, chrom1, chrom2):
        p = random.random()    # 随机概率
        n = 2 ** self.chromosome_size - 1
        if chrom1 != chrom2 and p < self.crossover_probability:
            t = random.randint(1, self.chromosome_size - 1)   # 随机选择一点（单点交叉）
            mask = n << t    # << 左移运算符
            # & 按位与运算符：参与运算的两个值,如果两个相应位都为1,则该位的结果为1,否则为0
            (r1, r2) = (chrom1 & mask, chrom2 & mask)
            mask = n >> (self.chromosome_size - t)
            (l1, l2) = (chrom1 & mask, chrom2 & mask)
            (chrom1, chrom2) = (r1 + l2, r2 + l1)
        return (chrom1, chrom2)

    # 变异
    def mutate(self, chrom):
        p = random.random()
        if p < self.mutation_probability:
            t = random.randint(1, self.chromosome_size)
            mask1 = 1 << (t - 1)
            mask2 = chrom & mask1
            if mask2 > 0:
                chrom = chrom & (~mask2)  # ~ 按位取反运算符：对数据的每个二进制位取反,即把1变为0,把0变为1
            else:
                chrom = chrom ^ mask1   # ^ 按位异或运算符：当两对应的二进位相异时，结果为1
        return chrom

    # 保留最佳个体
    def reproduct_elitist(self):
        # 与当前种群进行适应度比较，更新最佳个体
        j = -1
        for i in range(self.size):
            if self.elitist['fitness'] < self.fitness[i]:
                j = i
                self.elitist['fitness'] = self.fitness[i]
        if (j >= 0):
            self.elitist['chromosome'][0] = self.individuals[j][0]
            self.elitist['chromosome'][1] = self.individuals[j][1]
            self.elitist['age'] = self.age

    # 进化过程
    def evolve(self):
        indvs = self.individuals
        new_indvs = self.new_individuals
        # 计算适应度及选择概率
        self.evaluate()
        # 进化操作
        i = 0
        while True:
            # 选择两个个体，进行交叉与变异，产生新的种群
            idv1 = self.select()
            idv2 = self.select()
            # print('选择个体： ', idv1, idv2)
            # 交叉
            (idv1_x, idv1_y) = (indvs[idv1][0], indvs[idv1][1])
            (idv1_x1, idv1_x2, idv1_x3, idv1_x4) = (
                indvs[idv1][0], indvs[idv1][1], indvs[idv1][2], indvs[idv1][3])
            (idv2_x, idv2_y) = (indvs[idv2][0], indvs[idv2][1])
            (idv2_x1, idv2_x2, idv2_x3, idv2_x4) = (
                indvs[idv2][0], indvs[idv2][1], indvs[idv2][2], indvs[idv2][3])
            # print('个体', idv1, idv1_x1, idv1_x2, idv1_x3, idv1_x4)
            # print('个体', idv2, idv2_x1, idv2_x2, idv2_x3, idv2_x4)
            (idv1_x1, idv2_x1) = self.cross(idv1_x1, idv2_x1)
            (idv1_x2, idv2_x2) = self.cross(idv1_x2, idv2_x2)
            (idv1_x3, idv2_x3) = self.cross(idv1_x3, idv2_x3)
            (idv1_x4, idv2_x4) = self.cross(idv1_x4, idv2_x4)
            # 变异
            (idv1_x1, idv1_x2, idv1_x3, idv1_x4) = (
              self.mutate(idv1_x1),
              self.mutate(idv1_x2),
              self.mutate(idv1_x3),
              self.mutate(idv1_x4),
            )
            (idv2_x1, idv2_x2, idv2_x3, idv2_x4) = (
                self.mutate(idv2_x1),
                self.mutate(idv2_x2),
                self.mutate(idv2_x3),
                self.mutate(idv2_x4),
            )
            # 将计算结果保存于新的个体集合self.new_individuals中
            # (new_indvs[i][0], new_indvs[i][1]) = (idv1_x, idv1_y)
            # (new_indvs[i+1][0], new_indvs[i+1][1]) = (idv2_x, idv2_y)
            (new_indvs[i][0], new_indvs[i][1], new_indvs[i][2],
             new_indvs[i][3]) = idv1_x1, idv1_x2, idv1_x3, idv1_x4
            (new_indvs[i+1][0], new_indvs[i+1][1], new_indvs[i+1][2],
             new_indvs[i+1][3]) = idv2_x1, idv2_x2, idv2_x3, idv2_x4
            # 判断进化过程是否结束
            i = i + 2         # 循环self.size/2次，每次从self.individuals 中选出2个
            if i >= self.size:
                break

        # 最佳个体保留
        # 如果在选择之前保留当前最佳个体，最终能收敛到全局最优解。
        self.reproduct_elitist()

        # 更新换代：用种群进化生成的新个体集合 self.new_individuals 替换当前个体集合
        for i in range(self.size):
            self.individuals[i][0] = self.new_individuals[i][0]
            self.individuals[i][1] = self.new_individuals[i][1]
            self.individuals[i][2] = self.new_individuals[i][2]
            self.individuals[i][3] = self.new_individuals[i][3]

    def run(self):
        '''根据种群最大进化世代数设定了一个循环。
        在循环过程中，调用 evolve 函数进行种群进化计算，并输出种群的每一代的个体适应度最大值、平均值和最小值。'''
        for i in range(self.generation_max):
            self.evolve()
            print('进化世代数', i, '最大适应度',max(self.fitness), '平均适应度', sum(self.fitness) /
                  self.size, '最小适应度',min(self.fitness))
            temp = str(i)+' '+ str(max(self.fitness))+' '+ str(sum(self.fitness)/self.size)+' '+ str(min(self.fitness))+'\n'
            os.write(fd, bytes(temp,encoding='UTF-8'))


if __name__ == '__main__':
    # 种群的个体数量为 200，染色体长度为 27，交叉概率为 0.8，变异概率为 0.1,进化最大世代数为 500
    pop = Population(200, 28, 0.8, 0.1, 500)
    print(pop)
    pop.run()
