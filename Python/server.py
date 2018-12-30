import socket
import sys

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()

port = 9999

serverSocket.bind(host, port)

serverSocket.listen(5)

while True:
    clientSocket, addr = serverSocket.accept()
    print("连接地址：%s" % addr)
    msg = "我是你大爷"
    clientSocket.send(msg.encode('utf-8'))
    clientSocket.close()
    