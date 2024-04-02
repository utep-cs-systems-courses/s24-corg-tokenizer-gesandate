OBJS= tokenizer.o history.o uimain.o

CFLAGS=-g -O3

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokenize

run:tokenize
	./tokenize
