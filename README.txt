READ ME (TICTACTOE - LAB 2)
Tommy Peng
424763

I decided to use the old code from lab 1 and combined with a text file called tictactoe.txt that creates a 6 by 6 gameboard to give the initial gameboard state.
This text file includes the co-ordinate printouts.

The board is designed to by 6 by 6, this is to include the numbers to be printed by the side.
Using a similar scheme to label vector indices to gameboard co-ordinates, the equation for vector index is
(x_coord + 1) * width + 1 + y_coord.

I made it so that X goes first, the game remembers whose turn it is by keeping a current_turn unsigned int, which is 1 if
it is X, 0 if it is O.

The checking of the winning state of the game by done() checks through the connect 3 that can result from the newest modified square,
this is because any winning move's co-ordinates must be a part of the winning connect 3.

Build 1
Keeps get stuck in prompt() loop during turn.
Character comparison keeps failing, so that the "," in the input string is not getting replaced.
Fixed by actually assigning the ' ' char to the position in the string rather than using replace();

Build 2
Keeps getting stuck at ensuring the input numbers are digits.
Forgot that the characters can also be ' ' (spaces), which are used to seperate the two co-ordinates. Added that in.

Build 3
No messages print during prompt, annoying to debug and play.
Added additional help messages that prompt the user what is wrong. 

Build 4
Seems stable, can quit and returns errorlevel 999, the quit code.
C:\Users\Tommy\Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacT
oe
4
3
2
1
0
 01234
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
quit
You have quit.

C:\Users\Tommy\Documents\Visual Studio 2013\Projects\lab2\Debug>echo %errorlevel
%
999

Build 5
Draws after first input.
Turns out the all_fill() check for empty space was coded backwards, if it had an empty space, it was returning true.
Changed it to return true if no spaces are in the bounds, else return false.

Build 6
Seems stable, can be played until winning.
C:\Users\Tommy\Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacT
oe
4
3
2
1
0
 01234
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,1
4
3
2
1 X
0
 01234

Player X: 1, 1
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,2
4
3
2
1 XO
0
 01234

Player O: 1, 2
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,3
4
3
2
1 XOX
0
 01234

Player X: 1, 3
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
2,1
4
3
2 O
1 XOX
0
 01234

Player O: 2, 1
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
2,2
4
3
2 OX
1 XOX
0
 01234

Player X: 2, 2
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
2,3
4
3
2 OXO
1 XOX
0
 01234

Player O: 2, 3
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
3,1
4
3 X
2 OXO
1 XOX
0
 01234

Player X: 3, 1
Player X wins.

More testing:
C:\Users\Tommy\Documents\Visual Studio 2013\Projects\lab2\Debug>lab2.exe TicTacT
oe
4
3
2
1
0
 01234
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,1
4
3
2
1 X
0
 01234

Player X: 1, 1
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
2,2
4
3
2  O
1 X
0
 01234

Player O: 2, 2
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,3
4
3
2  O
1 X X
0
 01234

Player X: 1, 3
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,2
4
3
2  O
1 XOX
0
 01234

Player O: 1, 2
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
3,2
4
3  X
2  O
1 XOX
0
 01234

Player X: 3, 2
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
1,3
Co-ordinate already taken.
<x co-ord, y co-ord> to make move or <quit> to end game:
1,4
Co-ordinate out of bounds.
<x co-ord, y co-ord> to make move or <quit> to end game:
-1,3
The format of the co-ordinate is incorrect.
<x co-ord, y co-ord> to make move or <quit> to end game:
2,1
4
3  X
2 OO
1 XOX
0
 01234

Player O: 2, 1
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
2,3
4
3  X
2 OOX
1 XOX
0
 01234

Player X: 2, 3
Player O turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
3,3
4
3  XO
2 OOX
1 XOX
0
 01234

Player O: 3, 3
Player X turn...
<x co-ord, y co-ord> to make move or <quit> to end game:
3,1
4
3 XXO
2 OOX
1 XOX
0
 01234

Player X: 3, 1
After 9 moves, game is a draw.