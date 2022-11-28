IDIR =../include
CC=gcc
BDIR=../bin
ODIR=../obj
SDIR=../src
OFILES=$(ODIR)/list_menu.o $(ODIR)/list_func.o $(ODIR)/valid_func.o

listapp: $(OFILES)
	$(CC) -o $(BDIR)/listapp $(OFILES)

$(ODIR)/list_menu.o:$(SDIR)/list_menu.c $(IDIR)/*
	gcc -o $(ODIR)/list_menu.o -c $(SDIR)/list_menu.c


$(ODIR)/list_func.o:$(SDIR)/list_func.c $(IDIR)/*
	gcc -o $(ODIR)/list_func.o -c $(SDIR)/list_func.c


$(ODIR)/valid_func.o:$(SDIR)/valid_func.c $(IDIR)/*
	gcc -o $(ODIR)/valid_func.o -c $(SDIR)/valid_func.c

clean:
	rm $(ODIR)/*
