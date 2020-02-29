main.elf: main.o function.o
	gcc -o main.elf $^

	
%.o : %.S
	gcc -o $@ $< -c

%.o : %.c
	gcc -o $@ $< -c 

clean:
	rm *.o *.elf 
