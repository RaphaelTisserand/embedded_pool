all: hex flash

hex:
	avr-gcc main.c -o main.bin -DF_CPU=1000000 -mmcu=atmega328p
	avr-objcopy main.bin main.hex

flash:
	avrdude -U main.hex -p ATmega328P -b 115200 -c arduino -P /dev/ttyUSB0

clean:
	rm -f main main.bin main.hex
