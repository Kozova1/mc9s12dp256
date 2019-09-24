CC=gcc
CFLAGS=-I -Wall

ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

DEPS=cpu.h includes.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cpu12emu: *.c *.h
	$(CC) -o mc9s12dp256-emu main.c cpu.c loadprogram.c set.c instructions/*

.PHONY: clean install uninstall

clean:
	rm -f mc9s12dp256-emu

install:
	install -Dm755 mc9s12dp256-emu $(PREFIX)/bin/mc9s12dp256-emu

uninstall:
	rm -f $(PREFIX)/bin/mc9s12dp256-emu
