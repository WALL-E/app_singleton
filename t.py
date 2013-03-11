#!/usr/bin/env python
#
#
#create by zhangz @2013-03-11
#
import app_singleton
import time

def main():
	print "Start MyApp"
	try:
		app_singleton.app_singleton("/tmp/zz.pid")
		time.sleep(100)
	except Exception,msg:
		print msg
	print "End MyApp"

if __name__ == "__main__":
        main()
