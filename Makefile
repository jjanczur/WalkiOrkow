# W przypadku nowych plików, należy dodać je do zmiennej OBJECTS z 
# zmienionym rozszerzeniem z .cpp na .o (+ sciezka wzgledna).
#
# Następnie należy dodać regułę wg schematu:
# NazwaPliku.o: NazwaPliku.cpp
# <TAB>	$(CXX) $(CFLAGS) NazwaPliku.cpp 
#
# (Oczywiscie NazwaPliku.cpp wraz z ewent. sciezka wzgledna).

OBJECTS=main.o Aplikacja.o Dokument.o Ork.o TopOrk.o OrkAdiusz.o OrkNitolog.o Wyjatki.o Orkhybryda.o
CXX=g++ -std=c++11
CFLAGS=-c -Wall -pedantic
EXEC=Project

# Finalny projekt wykonywalny
$(EXEC): $(OBJECTS)
	$(CXX) -o $(EXEC) $(OBJECTS)

# Pliki źrodłowe projektu	
main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp
	
Aplikacja.o: Aplikacja.cpp
	$(CXX) $(CFLAGS) Aplikacja.cpp

Dokument.o: Dokument.cpp
	$(CXX) $(CFLAGS) Dokument.cpp

Ork.o: Ork.cpp
	$(CXX) $(CFLAGS) Ork.cpp

TopOrk.o: TopOrk.cpp
	$(CXX) $(CFLAGS) TopOrk.cpp

OrkAdiusz.o: OrkAdiusz.cpp
	$(CXX) $(CFLAGS) OrkAdiusz.cpp

OrkNitolog.o: OrkNitolog.cpp
	$(CXX) $(CFLAGS) OrkNitolog.cpp

Orkhybryda.o: Orkhybryda.cpp
	$(CXX) $(CFLAGS) Orkhybryda.cpp

# Traktuje ponizsze wyrazy jaki instrukcje, nie nazwy plikow
.PHONY: clean del

# Czysci wszystkie pliki posrednie
clean:
	rm -rf $(OBJECTS)

# Usuwa wykonywalny plik projektu
del:
	rm -rf $(EXEC)
