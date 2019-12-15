#!/bin/bash

command="./stockfish"
# shellcheck disable=SC2164
eval cd .. && cd .. && cd .. && cd lib && cd stockfish-10 && cd src
# shellcheck disable=SC2162
# shellcheck disable=SC2002
cat ../../../src/Stockfish/stockfish-script/commands.txt | while read line
do
   eval "$command $line" >> ../../../src/Stockfish/stockfish-script/res.txt
done
