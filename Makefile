all:
	gcc *.c

commit:
	git commit -a

clean:
	rm -rf *.out *.o *.s *.c~