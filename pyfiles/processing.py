import os
import time
if __name__=='__main__':
    print 'current Process (%s) start ...'%(os.getpid())
    pid=os.fork()
    if pid<0:
        print 'error in fork'
    elif pid==0:
        print 'I am child process(%s) and my parent process is (%s)'%(os.getpid(),os.getppid())
    else:
        time.sleep(10)
        print 'I (%s) creat a child process (%s).'%(os.getpid(),pid)
