#Python基本函数调用
def func1():
    print("请求班主任批准！")


def func2():
    print("请求系主任批准！")


def func3():
    print("请求院长批准！")


def main_func(day):
    if day <= 7:
        func1()
    elif day <= 15:
        func2()
    elif day <= 30:
        func3()
    else:
        print("教务申请休学")


if __name__ == "__main__":
    main_func(10)
