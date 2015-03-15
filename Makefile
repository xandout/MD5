all:
	gcc *.c -o xanmd5

commit:
	git commit -a

clean:
	rm -rf *.out *.o *.s *.c~