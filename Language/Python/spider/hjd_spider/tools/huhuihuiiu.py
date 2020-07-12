# show your code!
import enum
import random


class Receiver:
    CLASS_TEACHER = 0
    COUNSELLOR = 1
    COLLAGE_LEADER = 2
    SCHOOL_LEADER = 3

    # 规则：课时单位：天
    # 小于 0.5天 teacher 办理
    # 小于等于 1天 counsellor办理
    # 小于等于7天 COLLAGE_LEADER 办理
    # 大于7天 SCHOOL_LEADER 办理


class Application:
    name = None
    idd = None
    # 申请时间
    app_time = None
    # 申请理由
    app_reason = None

    def __init__(self, ):
        pass

    def __init__(self, name, idd, app_time, app_reason):
        self.name = name
        self.idd = idd
        self.app_time = app_time
        self.app_reason = app_reason

    def __str__(self):
        s = ''
        s += '申请人：{0}'.format(self.name) + '\n'
        s += '学号：{0}'.format(self.idd) + '\n'
        s += '申请时间：{0}'.format(self.app_time) + '\n'
        s += '申请理由：{0}'.format(self.app_reason) + '\n'
        return s



class Teacher:
    level = None
    nextT = None
    maxTime = 99

    def __str__(self, ):
        s = ''
        s += 'level:{0}'.format(self.level) + '\n'
        s += 'next:{0}'.format(self.nextT) + '\n'
        s += 'maxTime:{0}'.format(self.maxTime) + '\n'
        return s

    def judge(self, app: Application):
        pass

    def setRecevier(self, app: Application):
        time = app.app_time
        if time <= self.maxTime:
            print('审核人：{0}'.format(self.level))
            self.judge(app)
        elif self.nextT != None:
            print(self.nextT)
            self.nextT.setRecevier(app)

    def setNextT(self, nextT):
        self.nextT = next


class Class_Teacher(Teacher):
    def __init__(self, ):
        self.level = Receiver.CLASS_TEACHER

        self.maxTime = 0.5

    def judge(self, app: Application):
        t = random.randint(0, 10)
        print('教师意见：')
        if t <= 7:
            print('虽然你的理由有点扯，但是我还是允许了')
        else:
            print('你想上啥呢？回去撸码')

    def __str__(self):
        return super().__str__()


class Counsellor(Teacher):
    def __init__(self, ):
        self.level = Receiver.COUNSELLOR
        self.maxTime = 1

    def judge(self, app: Application):
        t = random.randint(0, 10)
        print('辅导员意见：')

        if t <= 5:
            print('允许')
        else:
            print('不允许')
    def __str__(self):
        return super().__str__()

class CollageLeader(Teacher):
    def __init__(self, ):
        self.level = Receiver.COLLAGE_LEADER
        self.maxTime = 7

    def judge(self, app: Application):
        t = random.randint(0, 10)
        print('学院领导意见：')

        if t <= 3:
            print('看你觉悟很好，批了')
        else:
            print('你这个诚意怕是不够啊')
    def __str__(self):
        return super().__str__()

class SchoolLeader(Teacher):
    def __init__(self, ):
        self.level = Receiver.SCHOOL_LEADER
        self.maxTime = 999

    def judge(self, app: Application):
        t = random.randint(0, 10)
        print('学校领导意见：')

        if t <= 2:
            print('pass')
        else:
            print('no pass')
    def __str__(self):
        return super().__str__()

class TeacherFactory:
    def getTeacher(self, ):
        teacher = Class_Teacher()
        counsellor = Counsellor()
        collage = CollageLeader()
        school = SchoolLeader()
        teacher.setNextT(counsellor)
        counsellor.setNextT(collage)
        collage.setNextT(school)
        return teacher


factory = TeacherFactory()
teacher = Class_Teacher()
counsellor = Counsellor()
teacher.setNextT(counsellor)

ap1 = Application('张三', 11, 2, '出去玩')
print(ap1)
print(teacher)

teacher.setRecevier(ap1)
