CC=ccsc
PK2=pk2cmd
CFLAGS=+FM +LN -T -A -M -Z +DF +Y=9 +STDOUT

DEVICE=PIC16F628A

PK2FLAGS=-E -P$(DEVICE) -M -R -J -F

all: LCD232

LCD232: lcd232.c
	$(CC) $(CFLAGS) lcd232.c
	
burn:
	$(PK2) $(PK2FLAGS) lcd232.hex

clean:
	rm *.cof *.err *.esym *.hex *.lst