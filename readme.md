Poker game

The model folder contains classes of the basic building blocks of the different components of a poker game. These are designed to hold data and provide an API to manipulate said data.

The table class can be considered as the MainModel class that holds all the different components. I holds most of the data of a poker game and provides higher level API to process a poker game.

The Game folder holds classes defining the buisness logic of a poker game. The definition of the flow of a hand is defined in this class. It interacts with the Table or Main model to manipulate the data.

The overarching architecture ressembles a MVC pattern. The view was not implemented, the controller(s) would be the game folder classes and the model would be the table class.


The hold em class and the table class don't have a clear seperation of roles and with the current implementation, it is difficult to properly split responsibilities. 
However, as it is, there should be enough to highlight the intended direction. The view should handle user actions during betting round fed into the controller (holdem / IPokerGame) with triggers model changes (Table)

The IPokerGame class is intended as the interface class to hold commonality between poker variations.
The update plan for this class would be to implement a new game class of a poker variation such as Draw poker. As commonality between this new varaition and the texas hold em currently implement, portions would move to the interface class.
As poker variations are added, the interface class will more easily show its responsibility.

-- Future Work --
Testing 
Implementation of the value of a given hand
Implementation of the showdown tie breaker
Implementation of replaying rounds until a winner is decided
Decision on error handling, current direction is to throw for any unexpected actions and crash the app but a high uptime alternative is possible by handling exceptions and returning to viable application states.
Implement poker variations to get insight on common aspects of game and start testing model limits / missing features


-- notes --
Not having played poker has made this all the more interesting to learn and try to implement. Especially learning about the variations.