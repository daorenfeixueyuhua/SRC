import json

item = []

with open('../resource/2020-05-03.json', 'r') as file:
    item = json.load(file)

print(item[:5:])
