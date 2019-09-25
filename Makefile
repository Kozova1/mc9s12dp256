CC=gcc
CFLAGS=-I -Wall -lncurses -O2

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

DEPS=cpu.h includes.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cpu12emu: *.c *.h
	$(CC) $(CFLAGS) -o mc9s12dp256-emu main.c cpu.c set.c mount_eeprom.c instructions/*.c

header-update:
	echo "" > instructions_includes.h
	 find ./instructions/ -type f -exec echo "#include \"{}\"" \; | grep "\.h" > instructions_includes.h

.PHONY: clean install uninstall

clean:
	rm -f mc9s12dp256-emu

install:
	install -Dm755 mc9s12dp256-emu $(PREFIX)/bin/mc9s12dp256-emu

uninstall:
	rm -f $(PREFIX)/bin/mc9s12dp256-emu
