Poker game

The model folder contains classes of the basic building blocks of the different components of a poker game. These are designed to hold data and provide an API to manipulate said data.

The table class can be considered as the MainModel class that holds all the different components. I holds most of the data of a poker game and provides higher level API to process a poker game.

The Game folder holds classes defining the buisness logic of a poker game. The definition of the flow of a hand is defined in this class. It interacts with the Table or Main model to manipulate the data.

The overarching architecture ressembles a MVC pattern. The view was not implemented, the controller(s) would be the game folder classes and the model would be the table class.


-- Future Work --
Testing 
Implementation of the value of a given hand
Implementation of the showdown
Implementation of replaying rounds until a winner is decided
Decision on error handling, current direction is to throw for any unexpected actions and crash the app but a high uptime alternative is possible by handling exceptions and returning to viable application states.


-- notes --
Not having played poker has made this all the more interesting to learn and try to implement. Especially learning about the variations.