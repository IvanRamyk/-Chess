#!/bin/bash

command="./stockfish"
# shellcheck disable=SC2164
eval cd .. && cd .. && cd .. && cd lib && cd stockfish-10 && cd src
# shellcheck disable=SC2162
# shellcheck disable=SC2002
com=" "
cat ../../../src/Stockfish/stockfish-script/commands.txt | while read line
do
   echo "$line"
   com+="$line"
done

com="position startpos moves e2e4 go depth 15"
echo "com = $com"	 
eval "$command $com \n go depth 15" >> ../../../src/Stockfish/stockfish-script/res.txt

