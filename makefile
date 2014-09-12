CC=ccsc
CFLAGS=+FM +LN -T -A -M -Z +DF +Y=9 +STDOUT

all: LCD232

LCD232: lcd232.c
	$(CC) $(CFLAGS) lcd232.c

clean:
	rm *.cof *.err *.esym *.hex *.lst