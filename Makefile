CFLAGS = -Imodules
SRC=$(wildcard */*/*.c) $(wildcard */*.c)

resizer: $(SRC)
	gcc -o ./bin/$@ $^ $(CFLAGS)