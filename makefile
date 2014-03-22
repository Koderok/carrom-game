CC = g++
CFLAGS =-lglut -lGLU -lGL -w #-lGLEW
INCLUDES = include/Graphics/*.h  include/CarromRules/*.h include/Common/*.h #include/AI/*.h include/Physics/*.h
LFLAGS = 
LIBS = 
SRCS = src/Graphics/*.cpp  src/CarromRules/*.cpp src/Common/*.cpp src/Physics/*.cpp
OBJS = $(SRCS:.c=.o)
MAIN = carrom

.PHONY: depend clean

all:    $(MAIN)
	@pdflatex carrom.tex > ~/null
	

$(MAIN): $(OBJS) 
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	@$(RM) *.o *~ $(MAIN) *.pdf *.aux *.log

depend: $(SRCS)
	makedepend $(INCLUDES) $^

