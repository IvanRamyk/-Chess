#!/bin/bash

command="./stockfish"
# shellcheck disable=SC2164
eval cd .. && cd .. && cd .. && cd lib && cd stockfish-10 && cd src
# shellcheck disable=SC2162
# shellcheck disable=SC2002

eval "cat ../../../src/Stockfish/stockfish-script/commands.txt | ./stockfish >> ../../../src/Stockfish/stockfish-script/res.txt"