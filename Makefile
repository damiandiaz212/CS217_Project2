project2	:	project2.c	record.c
	gcc	project2.c	record.c	-o	project2

cleanall : project2 record
	rm program
