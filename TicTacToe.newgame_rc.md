# CONTRACT FOR tictactoe::newgame

## ACTION NAME: newgame

### Parameters
Input parameters:

* `player1` (person initiating game as player 1)
* `player2` (person initiating game as player 2)
* `stake` (the asset each player must pay initially and the winner gets)

### Intent
INTENT. The intent of the `{{newgame}}` action is to create a new game of Tic Tac Toe in which `{{player1}}` plays against `{{player2}}`, competing to win the `{{stake}}`. The two players cannot be the same player!

The `{{stake}}` is transferred from `{{player1}}` and `{{player2}}` to This Contract to keep while the game is active. Once a winner is found, the stakes of both players are transferred to said winner. If the game is a draw, the stakes are returned to both players.

I understand that `{{player1}}` pays for the RAM used to store the game state. Additionally, both `{{player1}}` and `{{player2}}` can only be part of _one_ game at any one time, as either first or second player.

### Term
TERM. This Contract expires after the game is finished, either by winning, losing, draw, or early termination via the `{{endgame}}` function.
