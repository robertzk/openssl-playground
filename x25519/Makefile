CC=gcc
# CFLAGS=-I/usr/local/opt/openssl/include
CFLAGS=-I$$HOME/dev/tmp/openssl/include
LDFLAGS=-L$$HOME/dev/tmp/openssl/lib -lcrypto

ODIR=obj
_OBJ=x25519.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: clean

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ core

example: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)



