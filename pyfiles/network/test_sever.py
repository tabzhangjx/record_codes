#!/usr/bin/python
# -*- coding: UTF-8 -*-
# 文件名：server.py

import socket
s = socket.socket()         # 创建 socket 对象
host = socket.gethostname() # 获取本地主机名
print(host)
port = 12345                # 设置端口
s.bind((host, port))        # 绑定端口

s.listen(500)
while True:
	c, addr = s.accept()
	print('连接地址：', addr)
	str = 'hello'
	str=str.encode(encoding='utf-8')
	c.send(bytes(str))
	c.close()