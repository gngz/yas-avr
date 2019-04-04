#	Makefile YAS-AVR Project
#	Author: Gonçalo Passos
#	Copyright:
#	License:
#	Website: https://diogopassos.pt

# Project Configs

TARGET = yas-bin
SERIAL = COM3
BAUD = 57600 
DEVICE = atmega328p
CLOCK = 16000000

# Files 

YAS-CFILES = main.c
HEADER-LOC = yas/includes
HEADER-LOC += -I drivers/includes
# Compiler UTILS

CC = avr-gcc
LD = avr-ld
OBJCOPY= avr-objcopy
SIZE= avr-size


CFLAGS = -Wall -g -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -I $(HEADER-LOC)

AVRDUDE = avrdude -c arduino -p $(DEVICE) -P $(SERIAL) -b $(BAUD) -U flash:w:..\bin\$(TARGET).hex:i


COMPILE = $(CC) $(CC-FLAGS)




all: compile-os compile-drivers compile genbin genhex



compile-os: yas/*.c
	$(CC) $(CFLAGS) -c $^
	mv -t ../obj *.o

compile-drivers: drivers/*.c
	$(CC) $(CFLAGS) -c $^
	mv -t ../obj *.o

compile: *.c
	$(CC) $(CFLAGS) -c $^ 
	mv -t ../obj *.o

genbin:	
	$(CC) -mmcu=atmega328p -o ../bin/$(TARGET).bin ../obj/*.o

genhex: ../bin/$(TARGET).bin
	${OBJCOPY} -j .text -j .data -O ihex ..\bin\${TARGET}.bin ..\bin\${TARGET}.hex

upload:
	$(AVRDUDE)
	


# Clean Obj and Executable Files
clean:
	rm -f ../bin/* ../obj/*

# Check executable size
checksize:
	$(SIZE) -C ../bin/$(TARGET).bin --mcu=$(DEVICE)