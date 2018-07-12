#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>

#include <vector>

namespace tictactoe {

class TicTacToe : public eosio::contract {
public:
  TicTacToe(account_name self);

  // @abi action
  void newgame(const account_name player1, const account_name player2, eosio::asset stake);

  // @abi action
  void endgame(const account_name player1, const account_name player2);

  // @abi action
  void play(const account_name player1, const account_name player2, uint8_t row, uint8_t col);

private:
  enum class State : uint8_t {
    PlayerTurn, ///< A player's turn.
    Draw,       ///< Game finished as a draw.
    Won         ///< Game finished with a winner.
  };

  // @abi table game i64
  struct game {
    uint64_t player1, player2;
    uint8_t state;   ///< Cannot use enum in ABI so we cast to/from uint8_t.
    uint64_t winner; ///< If the state is Won this will contain the winner.
    uint64_t turn;   ///< If the state is PlayerTurn this will contain the player.
    uint8_t moves;
    std::vector<char> board;
    eosio::asset stake; ///< What's at stake for the winner.

    uint64_t primary_key() const;
    void play(const uint8_t coord);
    void setState(const State state);

    EOSLIB_SERIALIZE(game, (player1)(player2)(state)(winner)(turn)(moves)(board)(stake))

  private:
    void updateState();
    void payStake();

    bool isFree(const uint8_t row, const uint8_t col) const;
    bool isCross(const uint8_t row, const uint8_t col) const;
    bool isNought(const uint8_t row, const uint8_t col) const;

    // Check if (r1,c1) == (r2,c2) but not free.
    bool isSame(const uint8_t row1, const uint8_t col1, const uint8_t row2,
                const uint8_t col2) const;

    char rowWinner(const uint8_t row) const;
    char colWinner(const uint8_t col) const;
    char diagWinner() const;
  };

  using games = eosio::multi_index<N(game), game>;
};

EOSIO_ABI(TicTacToe, (newgame)(endgame)(play))

} // tictactoe
