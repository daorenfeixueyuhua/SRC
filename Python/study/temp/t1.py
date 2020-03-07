import datetime

format = "%Y-%m-%d %H:%M:%S"
end_time = '2020-03-07 11:27:00'
time = '2020-03-07 00:00:00'
print(end_time > time)
end_time = datetime.datetime.strptime(end_time, format)


print(datetime.datetime.now().strftime(format))
