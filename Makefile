SRCS = $(wildcard *.cpp)
OUT = $(SRCS:.cpp=)

.PHONY: all
all: $(OUT)

%: %.cpp
	g++ -g -o $@ $<

.PHONY: clean
clean:
	rm -f $(OUT)
