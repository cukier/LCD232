CC=wine ccsc
PK2=pk2cmd

MFLAGS=+FM +LN -T -A -M -Z +DF +Y=9 +STDOUT
HFLAGS=+FH +LN -T -A -M -Z +DF +Y=9 +STDOUT

DEVICE=PIC16F628A

PK2FLAGS=-E -P$(DEVICE) -M -R -J -F

all: LCD232 CTRL

LCD232: lcd232.c
	$(CC) $(MFLAGS) lcd232.c
	
CTRL: ctrl.c
	$(CC) $(HFLAGS) ctrl.c
	
burn:
	$(PK2) $(PK2FLAGS) lcd232.hex

clean:
	rm *.ccspjt *.cof *.err *.esym *.hex *.lst *.xsym