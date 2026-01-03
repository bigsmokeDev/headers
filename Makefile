CC = clang

CCFLAGS = -std=c99 -Wall -D_GNU_SOURCE
LDFLAGS = -lX11 -lGLX -lGL

all: build

build:
	$(CC) $(CCFLAGS) $(LDFLAGS) -O0 -g \
		-o bin/out src/main.c
	./bin/out

release:
	$(CC) $(CCFLAGS) $(LDFLAGS) -O3 \
		-o bin/out src/main.c
