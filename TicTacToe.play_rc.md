# CONTRACT FOR tictactoe::play

## ACTION NAME: play

### Parameters
Input parameters:

* `player1` (person playing a turn in the game as player 1 depending on turn)
* `player2` (person playing a turn in the game as player 2 depending on turn)
* `row` (row on 3x3 board to place cross or nought depending on turn)
* `col` (colum on 3x3 board to place cross or nought depending on turn)

### Intent
INTENT. The intent of the `{{play}}` action is to place a cross, for `{{player1}}`, or a nought (a circle), for `{{player2}}`, at `{{row}}` and `{{col}}`, and thus making a move - playing a turn of the game. It is only the player having the current turn that makes a play when the `{{play}}` action is invoked.

The position must not be preoccupied (by cross or nought) on the board and the total amount of moves cannot exceed 9, where a maximum of 5 can be made by `{{player1}}` as the first player and 4 by `{{player2}}` as the second player.

I understand that `{{player1}}` or `{{player2}}`, depending on whose turn it is, pays for the RAM used to alter the game state.

### Term
TERM. This Contract expires at the conclusion of code execution.
