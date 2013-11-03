C_FLAGS := -Wall -g -DNOROOTSESSION -m32

INC_DIR = ./

C_INCLUDES += -I$(INC_DIR) -I${ROOTSYS}/include

LIBS_ROOT =  -lm -L${ROOTSYS}/lib/ -lNew -lCore -lCint -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lGui -lm -ldl -rdynamic -lpthread -ldl

MYPROGRAM = createpath
APPL_SRCS = createpath.cc

all: $(MYPROGRAM)

$(MYPROGRAM): $(APPL_SRCS) 
	g++ $(LIBS_ROOT) $(C_FLAGS) $(C_INCLUDES) -o $(MYPROGRAM) $(APPL_SRCS) -g

clean:
	rm -f *.o $(MYPROGRAM)
