#!/usr/bin/python3
 
import socket               
import sys
import time

 
s = socket.socket()        
s.bind(("127.0.0.2", 8000))       
s.listen(5)    
c,addr = s.accept()    

c.close()
s.close()
