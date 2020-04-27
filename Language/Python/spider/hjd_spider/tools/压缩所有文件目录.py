import os
import zipfile

IMAGES_STORE = 'C:\sources\hjd\img - 副本/'


def list_dir():
    print(os.listdir(IMAGES_STORE))


# into all dir
def into_dir(dir):
    print(dir)
    child_dir_list = os.listdir(dir)
    for child_dir in child_dir_list:
        dir = dir + child_dir + '/'
        # print(dir)
        if os.path.isdir(dir) == True:
            into_dir(dir)


# 删除所有文件
def view_file(dir):
    delete_file_num = 0
    # print(dir)
    child_dir_list = os.listdir(dir)
    dir_list = []
    for child_dir in child_dir_list:
        tmp = dir + child_dir + '/'
        # print(dir)
        if os.path.isdir(tmp) == True:
            # 递归访问子目录
            dir_list.append(tmp)
            view_file(tmp)

    # 过滤目录
    file_list = []
    for child_file in child_dir_list:
        file = dir + child_file
        if os.path.isfile(file):
            file_list.append(file)

    # if len(file_list) == 0:
    #     print('all dir is ', dir_list)
    # else:
    #     print('all file is ', file_list)
    # 删除原本文件
    for file in file_list:
        delete_file_num += 1
        os.remove(file)
    return delete_file_num


if __name__ == "__main__":
    # list_dir()
    # into_dir(IMAGES_STORE)
    print('delete file ', view_file(IMAGES_STORE))
