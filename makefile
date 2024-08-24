CC=g++

CFLAGS= -std=c++11 -Wall -g

LFLAGS= -lm

TARGET= PA2


C_SRCS := \
	$(wildcard *.cpp)\
	$(wildcard src/*.cpp)\
	$(wildcard src/**/*.cpp)

HDRS := \
	$(wildcard *.h)\
	$(wildcard src/*.h)\
	$(wildcard src/**/*.h)

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))


#default target
all: build
	@echo "All Done!"


#Link all built objects
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)


#Catch root directory src files
bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


#Catch all nested directory files
bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


#Allows for quick execution and refreshes the makefile
clean:
	rm -f $(TARGET)
	rm -rf bin


#Running the build target
run: build
	./$(TARGET) watercraft.txt


#Just printing out the sources, headers, and objects
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"
