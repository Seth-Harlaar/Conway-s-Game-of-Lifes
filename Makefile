
cgol: prettyPrint.o cgol.o nextGen.o
	gcc -ansi -Wall prettyPrint.o cgol.o nextGen.o -o cgol

cgol.o:
	gcc -ansi -Wall -c cgol.c -o $@

prettyPrint.o: 
	gcc -ansi -Wall -c prettyPrint.c -o $@

nextGen.o:
	gcc -ansi -Wall -c nextGen.c -o $@

clean: 
	rm *.o cgol