#!/usr/bin/env python
#
#
#create by zhangz @2013-03-11
#
import ctypes

def app_singleton(pid_file):
	handle = ctypes.CDLL('./singleton.so')
	func = handle.app_singleton
	ret = func(pid_file)

	if ret == -1:
		raise OSError,"Failed to create singleton"
def main():
	import time
	app_singleton("/tmp/zz_2013_03_11_16_06.pid")
	time.sleep(100)

if __name__ == "__main__":
        main()
