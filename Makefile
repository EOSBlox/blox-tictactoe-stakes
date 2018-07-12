CONTRACT=TicTacToe
SOURCE=${CONTRACT}.cpp

all: wast abi

wast:
	eosiocpp -o ${CONTRACT}.wast ${SOURCE}

abi:
	eosiocpp -g ${CONTRACT}.abi ${SOURCE}

clean:
	rm -fv *.wast *.wasm *.abi
