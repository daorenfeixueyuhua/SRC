urls = []
with open('../resource/备份.txt', 'r') as file:
    for line in file.readlines():
        urls.append(line)

print(urls[:10:])

with open('../resource/test.txt', 'a') as file:
    for line in urls:
        file.write(line)
