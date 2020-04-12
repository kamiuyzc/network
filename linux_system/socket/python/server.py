#!/usr/bin/python3
 
import socket               
import sys
import time

 
s = socket.socket()        
s.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 4096)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#s.setsockopt(socket.SOL_SOCKET, socket.SO_DEBUG, 1)
s.bind(("127.0.0.2", 8000))       
s.listen(5)    
#c,addr = s.accept()    

#c.close()
#s.close()
