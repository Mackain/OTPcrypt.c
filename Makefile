all: clean
	gcc program.c OTPcrypt.c -o test
clean:
	rm -f test
