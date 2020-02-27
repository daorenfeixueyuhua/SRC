import os

base_path = r'C:\\Users\Lenovo\OneDrive\桌面\snmp'

"""
    功能说明：
    删除base_path目录下所有空文件夹
    思路：
    １.获取base_path目录下所有文件
    ２.判断是否为目录
    ３.若为目录进入该目录
    ４.统计该目录子文件个数
    ４.若为０，删除该目录，并返回删除目录个数
"""


def delete(base_path):
    # print(base_path)
    delete_sum = 0
    empty = True
    for filename in os.listdir(base_path):
        filename = os.path.join(base_path, filename)
        if os.path.isdir(filename):
            empty = False
            # print(filename)
            delete_sum += delete(filename)
    if empty is True:
        print(base_path, 'is', empty)
        os.removedirs(base_path)
        return delete_sum
    else:
        return 0


if __name__ == '__main__':
    print('成功删除空文件夹啊个数', delete(base_path))
