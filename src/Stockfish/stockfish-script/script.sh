#!/bin/bash

command="cd .. && cd .. && cd .. && cd lib && cd stockfish-10 && cd src && ./stockfish"
# shellcheck disable=SC2162
# shellcheck disable=SC2002
cat commands.txt | while read line
do
   eval "$command $line" >> res.txt
   command="./stockfish"
done
