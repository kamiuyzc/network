#!/bin/bash


function get_answer {
    unset ANSWER
    count=0
    while [ -z "$ANSWER" ]
    do
        count=$[ $count + 1 ]
        echo $coumt
        case $count in
        2)
            echo 'Please input '
        ;;
        3)
            echo 'last chance'
        ;;
        4)
            echo 'exit'
            exit
        ;;
        esac

        if [ -n "$LINE2" ]
        then
            echo -e "$LINE1\c"
            echo -e "$LINE2\c"
        fi
        read ANSWER
    done
    unset LINE1
    unset LINE2
}

function process_answer {
  case $ANSWER in
  y|Y|yes|YES)
    echo "right"
  ;;
  *)
    echo $EXITLINE1
    exit
  ;;
  esac
  unset EXITLINE1
}
LINE1="input somethine "
LINE2="Please"
get_answer

EXITLINE1="lalalala"
process_answer