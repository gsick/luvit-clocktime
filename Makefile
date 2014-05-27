LUVIT  = luvit
CFLAGS = $(shell $(LUVIT) --cflags | sed s/-Werror//)
LIBS   = $(shell $(LUVIT) --libs)

all: bin/clocktime.luvit

bin/%.luvit: src/%.c
	mkdir -p bin
	$(CC) ${CFLAGS} -Isrc -o $@ $^ ${LIBS}

test: test-lua

test-lua:
	mkdir -p test/modules
	ln -s ../../../luvit-clocktime/ test/modules/clocktime
	${LUVIT} test/test.lua

clean:
	rm -fr bin
