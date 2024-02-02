all: triInsertion triFusion triRapide csvWriter

triInsertion: algos/triInsertion.c
	gcc -o bin/triInsertion -Wall algos/triInsertion.c

triFusion: algos/triFusion.c
	gcc -o bin/triFusion -Wall algos/triFusion.c

triRapide: algos/triRapide.c
	gcc -o bin/triRapide -Wall algos/triRapide.c

csvWriter: csvWriter.c
	gcc -o bin/csvWriter -Wall csvWriter.c lib/arrayManager.c lib/triInsertion.c lib/triFusion.c lib/triRapide.c
