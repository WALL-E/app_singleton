all:py_singleton c_singleton
py_singleton:singleton.c
	gcc -shared -fPIC -o singleton.so singleton.c
	strip singleton.so

c_singleton:singleton.c
	gcc -o t singleton.c t.c
	strip t

clean:
	rm -f singleton.so t.o t *.pyc
