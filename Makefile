BlackJack: Cardset.o Player.o Main.o
	g++ -o BlackJack Cardset.o Player.o Main.o

Cardset.o: Cardset.cpp Cardset.h Deck.h
	g++ -c  Cardset.cpp

Player.o: Player.cpp Player.h Deck.h
	g++ -c Player.cpp

Main.o: Main.cpp Cardset.h Player.h Deck.h
	g++ -c Main.cpp

clean:
	rm *.o BlackJack