import urllib.request

m3ud8_url = 'https://qq.com-ixx-qq.com/20200427/8960_112045cf/1000k/hls/index.m3u8'
data = urllib.request.urlopen(m3ud8_url)
s = data.read().decode('UTF-8').split('\n')
print(s)
for s1 in s:
    if '#' not in s1:
        print(s1)
