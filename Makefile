export CC = g++
INCPATH = -I$(CURDIR)/include -I$(CURDIR)/src 
LIBS =
#-lpthread 
#-lmysqlcppconn 
export DEFINES = -DCOLORS -DNDEBUG
export FLAGS = -Wall -og -std=c++0x $(INCPATH) $(LIBS) $(DEFINES)
export TOP = $(CURDIR)
export OBJ_DIR = $(TOP)/obj

SRC = $(wildcard *.c*)
OBJ = $(SRC:.cpp=.o) $(SRC:*.cpp=.o)

SUBDIRS = src obj

export EXEC = Mgf
export LIB  = libmgf
export STATIC = $(LIB).a
export SHARED = $(LIB).so


CLEANDIRS = $(SUBDIRS:%=clean-%)

.PHONY: subdirs $(SUBDIRS)
.PHONY: subdirs $(CLEANDIRS)

all: src $(OBJ) obj

static : src
	$(MAKE) static -C obj

shared :
	$(MAKE) -C src FLAGS="$(FLAGS) -fPIC"
	$(MAKE) shared -C obj


install :
	cp -f $(STATIC) /usr/local/lib/$(STATIC)
	cp -f $(SHARED) /usr/local/lib/$(SHARED)
	cp -rf include/mgf /usr/local/include/mgf
	cp -rf src/mgf/*.hh /usr/local/include/mgf

uninstall:
	rm -f /usr/local/lib/$(STATIC)
	rm -f /usr/local/lib/$(SHARED)
	rm -rf /usr/local/include/mgf

doc : doc/html 

doc/html :
	cd doc && doxygen

src:
	$(MAKE) -C $@

obj:
	$(MAKE) -C $@

.cpp.o:
	$(CC) $(FLAGS) -o $@ -c $^;
	@mv $@ "$(OBJ_DIR)"

.c.o :
	$(CC) $(FLAGS) -o $@ -c $^;
	@mv $@ "$(OBJ_DIR)"


clean: $(CLEANDIRS)

$(CLEANDIRS): 
	$(MAKE) -C $(@:clean-%=%) clean
	@rm -f *.o
	#@rm -f $(SHARED)
	#@rm -f $(STATIC)
	@rm -f $(EXEC)

