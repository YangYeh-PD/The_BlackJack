# The BlackJack
## Introduction
This <a href = "https://en.wikipedia.org/wiki/Blackjack">BlackJack game</a> allows user to play against a computer dealer.  

<img src="https://upload.wikimedia.org/wikipedia/commons/e/e4/BlackJack6.jpg" width="250">

The goal is to make the sum of the player’s card values as close to 21 as possible, without going over.  
If the player makes 21 exactly, he/she has **"Blackjack"**, which cannot be beat.  
If the player goes over 21, he/she **"busts"** and lose the game.  
The player is allowed to stop hitting at any time point.  

## Rules and Procedure
1. **Both player and dealer** receive two cards from a shuffled deck of 52 cards.
2. The player is asked if they want another card (called **"hitting"**), or he/she are happy with the cards they have already (called **"staying"**).  
3. The number cards (2 through 10) are worth the number displayed.  
Facecard (JACK, QUEEN, and KING) are worth 10, and an ACE can be worth either 1 or 11.  
The program will find the best value for you automatically.
4. Once the player’s hand is finished, the dealer will keep hitting until it gets to **17**.  
5. decide whether you want to play it again or not.  

## Sample Outout
<img src="https://raw.githubusercontent.com/YangYeh-PD/The_BlackJack/master/Output_Sample.jpg" width="500" height="750" />  

- Complie  
```
gcc -o BlackJack BlackJack.c
./BlackJack 
```    
Or use the command `make` to compile it.  
Use `make clean` to clean all out and execution files.  