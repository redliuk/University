SOURCE	= QuicksortLV.cpp
OUT		= LVQuickSort
CC		= g++
EX		= ./
PY		= python3

all:
	
	$(CC) QuicksortLV.cpp
	@echo "Inizio programma: si prega di attendere l'esecuzione delle 100000 ripetizioni di Quicksort"
	$(EX)a.out
	$(PY) PlotIstogramma.py
	@echo "Programma terminato, istogramma creato"

histogram:
	$(PY) PlotIstogramma.py

clean:
	rm -f IstogrammaNormalizzato.png a.out conteggioConfronti.txt