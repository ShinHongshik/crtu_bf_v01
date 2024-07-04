import os
import sys
import time
import serial


com_port  = "COM34"
file_name = "../build/pes_acc"


def open_port(port, baudrate=1200, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE, timeout=None, xonxoff=False, rtscts=False, dsrdtr=False):
    ser = serial.Serial()

    ser.port = port
    ser.baudrate = baudrate
    ser.bytesize = bytesize
    ser.parity = parity
    ser.stopbits = stopbits
    ser.timeout = timeout
    ser.xonxoff = xonxoff
    ser.rtscts = rtscts
    ser.dsrdtr = dsrdtr

    try:      
      ser.open()      
      ser.close()    
    except(OSError, serial.SerialException):
      pass
    return ser


if __name__ == '__main__':
  time.sleep(1.0)  
  open_port(com_port)
  time.sleep(1.0)
  print("reset pico")   
  time.sleep(1.0)  
 # os.chdir("tools")
 # os.system('rp2040load.exe' + " -v -D " + file_name)
  time.sleep(1.0)  

  
