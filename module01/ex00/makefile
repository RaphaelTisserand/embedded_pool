SRCS_DIR	:= srcs
BUILD_DIR	:= .build

SRCS		:=	main.c
SRCS		:= $(SRCS:%=$(SRCS_DIR)/%)
BINS		:= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.bin)
HEXS		:= $(BINS:.bin=.hex)

CC			:= avr-gcc
CPY			:= avr-objcopy
DUDE		:= avrdude
MAKEFLAGS	+= --silent --no-print-directory
DIR_DUP		= mkdir -p $(@D)

GREEN		:= $(shell tput setaf 2)
RED			:= $(shell tput setaf 1)
RESET		:= $(shell tput sgr0)

all: hex flash

.PHONY: hex
hex: $(BINS) $(HEXS)

$(BUILD_DIR)/%.bin: $(SRCS_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(SRCS) -o $(BINS) -DF_CPU=16000000 -mmcu=atmega328p -O0
	$(info $(GREEN)CREATED$(RESET) $@)

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.bin
	$(DIR_DUP)
	$(CPY) $(BINS) $(HEXS)
	$(info $(GREEN)CREATED$(RESET) $@)

.PHONY: flash
flash: $(HEXS)
	$(DUDE) -U $(HEXS) -p ATmega328P -b 115200 -c arduino -P /dev/ttyUSB0
	$(info $(GREEN)COPIED$(RESET) $@)

.PHONY: re
re: clean all

.PHONY: stop
stop:
	echo "int	main(void) {}" > empty.c
	$(CC) empty.c -o empty.bin -DF_CPU=16000000 -mmcu=atmega328p
	$(CPY) empty.bin empty.hex
	$(DUDE) -U empty.hex -p ATmega328P -b 115200 -c arduino -P /dev/ttyUSB0
	$(RM) empty.*

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	$(info '$*'='$($*)')

.PHONY: clean
clean:
	$(RM) $(BINS) $(HEXS)
	$(info $(RED)DELETED$(RESET) $(BINS) $(HEXS))

.SILENT:
