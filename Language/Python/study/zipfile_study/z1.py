import zipfile

zip_dir = 'C:\\Users\\Lenovo\\OneDrive\\Projects\\SRC\\Language\\Python\\study\\zipfile_study\\'

with zipfile.ZipFile(zip_dir + 'spam.zip', 'w') as myzip:
    myzip.write(zip_dir + 'eggs.txt')
