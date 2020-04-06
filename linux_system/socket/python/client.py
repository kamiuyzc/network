#!/bin/python3
import socket               # 导入 socket 模块
 
s = socket.socket()         # 创建 socket 对象
 
s.connect(("127.0.0.2", 8000))

s.close()
