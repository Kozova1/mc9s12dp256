CC=gcc
LIBFLAGS=-lncurses
WARNING=-Wall -Wno-unused-variable
CFLAGS=-I ${WARNING} ${LIBFLAGS} -O2

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

cpu12emu: *.c *.h
	$(CC) ${CFLAGS} -o mc9s12dp256-emu main.c cpu.c set.c mount_eeprom.c instructions/*.c

.PHONY: clean install uninstall header-update

header-update:
	echo "" > instructions_includes.h
	 find ./instructions/ -type f -exec echo "#include \"{}\"" \; | grep "\.h" > instructions_includes.h


clean:
	rm -f mc9s12dp256-emu

install:
	install -Dm755 mc9s12dp256-emu $(PREFIX)/bin/mc9s12dp256-emu

uninstall:
	rm -f $(PREFIX)/bin/mc9s12dp256-emu
