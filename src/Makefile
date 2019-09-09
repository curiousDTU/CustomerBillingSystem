IDIR =../include
CC = gcc
CFLAGS= -I$(IDIR)

ODIR=obj

LIBS=-lncurses

_DEPS = billingFunctions.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  CustomerBilling.o billingFunctions.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bill: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean: 
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

