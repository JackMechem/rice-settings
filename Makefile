IDIR=/usr/local/include
CC=g++
CFLAGS=-I$(IDIR)

LIBDIR=-L/usr/local/lib
LIBS=-lyaml-cpp

OBJ=main.o
ODIR=obj

BINDIR=bin

all: clean rice-settings

rice-settings: main.cpp
	$(CC) $(CFLAGS) $(LIBDIR) $(LIBS) -o $(BINDIR)/$@ $^

install: rice-settings
	sudo cp bin/rice-settings /usr/bin/rice-settings

remove:
	sudo rm /usr/bin/rice-settings

clean:
	rm -f bin/*


# all: rice-settings
# 	./bin/rice-settings
# 
# $(ODIR)/%.o: %.cpp
# 	$(CC) -c $(CFLAGS) $(LIBDIR) $(LIBS) -o $@ $^
# 
# rice-settings: $(ODIR)/$(OBJ)
# 	$(CC) $(CFLAGS) $(LIBDIR) $(LIBS) -o $(BINDIR)/$@ $^
# 
# 

# .PHONY: clean
# 
# clean:
# 	rm -f $(ODIR)/*.o
# 	rm -f $(BINDIR)/*.o
