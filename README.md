# blox-tictactoe-stakes
Two-player TicTacToe winner-takes-all with EOS stakes via smart contract.

## Actions
The smart contract has three actions:
  * `newgame(player1, player2, stake)`: Creates a new game between `player1` and `player2` for a
    defined stake.  Each player automatically transfers this emount to the contract to keep. On a
    draw, both players get back their stakes. If a  winner is found then that player gets double the
    initial stake.
  * `endgame(player1, player2)`: Ends game and removes entries from table. If game is not finished
    then players get their stakes back, but _only_ if no moves have been made.
  * `play(player1, player2, row, col)`: Current player takes turn at row and column position.

## Compilation
EOSIO is expected to be compiled and available on the system, especially `eosiocpp`:
```
% make
eosiocpp -o TicTacToe.wast TicTacToe.cpp
eosiocpp -g TicTacToe.abi TicTacToe.cpp
Generated TicTacToe.abi ...
```

## Prerequisites
In order for the smart contract to function, the blockchain it is uploaded to must also have the
`eosio.token` contract in order to be able to transfer stakes to winning players from the losers.

Additionally, all attending players must set permission `eosio.code` for this smart contract. If
this contract is uploaded to account `tictactoe` and `user` wants to set the permission:
```
% cleos set account permission user active \
'{"threshold": 1,
  "keys": [{
    "key": "PUBKEY_OF_user",
    "weight": 1
  }],
  "accounts": [{
    "permission": {"actor": "tictactoe",
                   "permission": "eosio.code"},
                   "weight": 1
  }]}' owner -p user
```
