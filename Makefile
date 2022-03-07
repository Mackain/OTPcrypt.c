all: clean
	gcc program.c OTPcrypt.c -o cryptoTest
clean:
	rm -f test
