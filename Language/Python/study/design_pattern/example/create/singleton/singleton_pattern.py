# 直接继承该该类，即可实现单例
class Singleton:
    def __new__(cls, *args, **kwargs):
        if not hasattr(cls, '__instance'):
            orig = super(Singleton, cls)
            cls.__instance = orig.__new__(cls)
            return cls


class Desk(Singleton):
    name = 1


if __name__ == '__main__':
    s1 = Singleton()

    s2 = Singleton()

    print(s1 == s2)

    d1 = Desk()
    d2 = Desk()
    print(d1 == d2)
