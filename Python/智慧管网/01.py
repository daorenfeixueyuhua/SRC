import requests
url = 'http://localhost:8080/Intelligent_pipe_network/adim/homepage?regionId=7081'
payload = 'userName=123&passWord=123'
headers = {
    'Content-Type': 'application/x-www-form-urlencoded'
}
response = requests.get(url)
print(response.text)
