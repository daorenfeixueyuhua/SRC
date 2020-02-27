import os

base_path = 'C:\\Users\Lenovo\Downloads\BAIDUDisk\女神\\0M5H88\[全彩经典] 女神露出 “Zumi”作品1-26(12月薪)+旧图集\旧图集\Artist - Zumi (November 2018 - February 2019)\\'

desktop_target_path = 'C:\\Users\Lenovo\OneDrive\桌面\电脑壁纸\\'
phone_target_path = 'C:\\Users\Lenovo\OneDrive\桌面\手机壁纸\\'
target_path = ''
file_list = os.listdir(base_path)
delete = False
remove = False


def remove():
    print(file_list[0:20])
    #
    # print(file_list[0].index('V01.jpg'))

    for file in file_list:
        if 'V01.jpg' in file:
            if '4KDesktop_V01.jpg' in file:
                print('电脑壁纸')
                # target_path = desktop_target_path
            else:
    # 删除整个文件
                target_path = phone_target_path
                print('手机壁纸')
                print(file)
                os.rename(base_path + file, target_path + file)
    return None


def delete():
    if delete is True:
        for file in file_list:
            os.remove(base_path + file)
        os.removedirs(base_path)
    return None

if __name__ == '__main__':
    if delete is True:
        delete()