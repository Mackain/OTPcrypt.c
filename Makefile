all: clean
	gcc main.c OTPcrypt.c -o cryptoTest
clean:
	rm -f test
