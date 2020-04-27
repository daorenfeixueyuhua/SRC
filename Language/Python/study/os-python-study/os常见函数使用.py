import os

print('系统目录分割符', os.sep)

print('当前操作系统', os.name)

print('当前工作目录', os.getcwd())

# print('Path环境变量', os.getenv('PATH'))

# 如果 path=None 显示当前工作目录
print('当前目录下所有文件', os.listdir())


# 删除文件
# os.remove('D:/test.file')

# 运行shell或者cmd命令
os.system('dir')

# 获取当前平台的使用行终止符

print(os.linesep)

# 获取 一个列表, list[0]是路径， list[1]是文件名
path = 'C:/Users\\Lenovo\OneDrive\Projects\SRC\Language\Python\study\os-python-study\os常见函数使用.py'
print(os.path.isdir(os.path.split(path)[0]))
print(os.path.isfile(path))


# 判断是不是目录/文件

# 判断路径是否存在

print('路径是否存在', os.path.exists(path))

# 切换工作目录，相当于path
# os.chdir('D:/')

print('获取文件大小', os.path.getsize(path))

print('获取绝对路径', os.path.abspath('.gitignore'))

print('规范路径', os.path.normpath(path))

print('获取文件名和扩展名', os.path.splitext(path))

# 连接目录和文件名
# os.path.join(path, name='')

print('获取路径中的文件名', os.path.basename(path))
print('获取路径中的目录名', os.path.dirname(path))