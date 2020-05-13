if __name__ == '__main__':
    urls = []
    path = '../resources/proxies.txt'
    with open(path, 'r') as file:
        for url in file.readlines():
            if '\n' in url:
                url.replace('\n', '')
            urls.append(url)
        file.close()

    for i in range(len(urls)):
        urls[i] = 'https://' + urls[i]

    with open(path, 'w') as file:
        for i in range(len(urls)):
            if '\n' not in urls[i]:
                urls[i] = urls[i] + '\n'
            file.write(urls[i])
        file.close()
