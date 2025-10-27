all: hex flash

hex:
	avr-gcc main.c -o main.bin -F_CPU=1000000
	avr-objcopy main.bin main.hex

flash:
	avrdude -U main.hex -p ATmega328P -b 115200 -c arduino -P /dev/ttyUSB0

clean:
	rm main main.bin main.hex
