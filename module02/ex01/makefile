NAME			:= ex01

INCS			:= incs

SRC_DIR			:= srcs
SRC				:= \
	main.c \
	uart/uart_tx.c \
	uart/uart_init.c \
	uart/uart_printstr.c
SRC				:= $(SRC:%=$(SRC_DIR)/%)

BUILD_DIR		:= .build
OBJ				:= $(SRC:$(SRC_DIR)/%=$(BUILD_DIR)/%.o)
DEPS			:= $(OBJ:.o=.d)
BIN				:= $(BUILD_DIR)/$(NAME).bin
HEX				:= $(BUILD_DIR)/$(NAME).hex

CC				:= avr-gcc
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS		:= $(addprefix -I,$(INCS)) -MMD -MP
CPY				:= avr-objcopy
DUDE			:= avrdude

RM			+= -r
MAKEFLAGS		+= --silent --no-print-directory
DIR_DUP			= mkdir -p $(@D)

GREEN			:= $(shell tput setaf 2)
RED				:= $(shell tput setaf 1)
RESET			:= $(shell tput sgr0)

F_CPU			:= 16000000UL
UART_BAUDRATE	:= 115200

all: $(HEX)
	$(DUDE) -U $(HEX) -p ATmega328P -b $(UART_BAUDRATE) -c arduino -P /dev/ttyUSB0

$(HEX): $(BIN)
	$(CPY) $(BIN) $(HEX)
	$(info $(GREEN)CREATED$(RESET) $@)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -mmcu=atmega328p -o $(BIN)
	$(info $(GREEN)CREATED$(RESET) $@)

$(BUILD_DIR)/%.c.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -DF_CPU=$(F_CPU) -mmcu=atmega328p -Os -c -o $@ $<
	$(info $(GREEN)CREATED$(RESET) $@)

clean:
	$(RM) $(BUILD_DIR)

re: clean all

stop:
	echo "int	main(void) {}" > empty.c
	$(CC) empty.c -o empty.bin -mmcu=atmega328p
	$(CPY) empty.bin empty.hex
	$(DUDE) -U empty.hex -p ATmega328P -b $(UART_BAUDRATE) -c arduino -P /dev/ttyUSB05
	$(RM) empty.*

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	$(info '$*'='$($*)')

-include $(DEPS)

.SILENT:
.PHONY: re stop clean
