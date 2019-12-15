#!/bin/bash

# define suitable post and prefixes for testing options
case $1 in
  --valgrind)
    echo "valgrind testing started"
    prefix=''
    exeprefix='valgrind --error-exitcode=42'
    postfix='1>/dev/null'
    threads="1"
  ;;
  --valgrind-thread)
    echo "valgrind-thread testing started"
    prefix=''
    exeprefix='valgrind --error-exitcode=42'
    postfix='1>/dev/null'
    threads="2"
  ;;
  --sanitizer-undefined)
    echo "sanitizer-undefined testing started"
    prefix='!'
    exeprefix=''
    postfix='2>&1 | grep "runtime error:"'
    threads="1"
  ;;
  --sanitizer-thread)
    echo "sanitizer-thread testing started"
    prefix='!'
    exeprefix=''
    postfix='2>&1 | grep "WARNING: ThreadSanitizer:"'
    threads="2"

cat << EOF > tsan.supp
race:TTEntry::move
race:TTEntry::depth
race:TTEntry::bound
race:TTEntry::save
race:TTEntry::value
race:TTEntry::eval

race:TranspositionTable::probe
race:TranspositionTable::hashfull

EOF

    export TSAN_OPTIONS="suppressions=./tsan.supp"

  ;;
  *)
    prefix=''
    exeprefix=''
    postfix=''
    threads="1"
  ;;
esac



#######################

command="cd .. && cd .. && cd lib && cd stockfish-10 && cd src && ./stockfish"
# shellcheck disable=SC2162
# shellcheck disable=SC2002
cat commands.txt | while read line
do
   eval "$command $line" >> res.txt
   command="./stockfish"
done
