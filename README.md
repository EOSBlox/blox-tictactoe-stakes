# blox-tictactoe-stakes
Two-player TicTacToe winner-takes-all with EOS stakes via smart contract.

## Actions
The smart contract has three actions:
  * `newgame(player1, player2, stake)`: Creates a new game between `player1` and `player2` where the
     winner gets `stake` ("1.0000 EOS" for instance).
  * `endgame(player1, player2)`: Ends game and removes entries from table.
  * `play(player1, player2, row, col)`: Current player takes turn at row and column position. If the
    player wins the game, `stake` is transferred from the losing player's balance.

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
