all: keyb2000.hex

keyb2000.hex: keyb2000.c
	sdcc $^
	packihx keyb2000.ihx > keyb2000.hex

clean:
	rm -f *.asm *.hex *.ihx *.lnk *.lst *.map *.rel *.rst *.sym *.bin *.mem *.cdb *.lk

