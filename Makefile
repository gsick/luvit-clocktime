LUVIT  = luvit
CFLAGS = $(shell $(LUVIT) --cflags | sed s/-Werror//)
LIBS   = $(shell $(LUVIT) --libs)

all: bin/clocktime.luvit

bin/%.luvit: src/%.c
	mkdir -p bin
	$(CC) ${CFLAGS} -Isrc -o $@ $^ ${LIBS}

test:
	mkdir -p test/modules
	ln -s ../../../luvit-clocktime/ test/modules/clocktime
	luvit test/test.lua

clean:
	rm -fr bin
