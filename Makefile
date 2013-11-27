export CC = g++
INCPATH = -I$(CURDIR) 
LIBS =
#-lpthread 
#-lmysqlcppconn 

export DEFINES = -DCOLORS 
#export DEFINES = -DNDEBUG
export FLAGS = -g -Wall -std=c++0x $(INCPATH) $(LIBS) $(DEFINES)
export TOP = $(CURDIR)
export OBJ_DIR = $(TOP)/obj

SRC = $(wildcard *.c*)
OBJ = $(SRC:.cpp=.o) $(SRC:*.cpp=.o)

SUBDIRS = mgf obj

export EXEC = Mgf


CLEANDIRS = $(SUBDIRS:%=clean-%)

.PHONY: subdirs $(SUBDIRS)
.PHONY: subdirs $(CLEANDIRS)

all: mgf $(OBJ) obj

doc : doc/html 

doc/html :
	cd doc && doxygen

mgf:
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
	@rm -f $(EXEC)

