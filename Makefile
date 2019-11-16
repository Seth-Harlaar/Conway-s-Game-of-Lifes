
cgol: prettyPrint.o cgol.o
	gcc -ansi -Wall prettyPrint.o cgol.o -o cgol

cgol.o:
	gcc -ansi -Wall -c cgol.c -o $@

prettyPrint.o: 
	gcc -ansi -Wall -c prettyPrint.c -o $@


clean: 
	rm *.o cgol