CC=g++
FLAGS=-g
SOURCE_FILE=lcs.cpp
OUTPUT_FILE=a

all: $(OUTPUT_FILE)

$(OUTPUT_FILE): $(OUTPUT_FILE).o
	$(CC) $(FLAGS) $< -o $@

$(OUTPUT_FILE).o: $(SOURCE_FILE)
	$(CC) -c $(FLAGS) $< -o $@

debug: $(OUTPUT_FILE).exe
	cgdb $<

clean:
	rm *.o *.exe
