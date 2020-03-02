#!/bin/bash

function get_answer {
    unset ANSWER
    ASK_COUNT=0
    while [ -z "$ANSWER" ]
    do
        ASK_COUNT=$[ $ASK_COUNT + 1 ]
        case $ASK_COUNT in
            2)
                echo please input username
            ;;
            3)
                echo last time input
            ;;
            4)
                echo tuichu
                exit
            ;;
        esac

        if [ -n "$LINE2" ]
        then
            echo -e "$LINE1\c"
            echo -e "$LINE2\c"
        else
            echo -e "$LINE13\c"
        fi

        read -t 60 ANSWER
    done
    unset LINE2
    unset LINE1
}

function process_answer {
    case $ANSWER in
    y|Y|yes|YES)
        echo "aa"
    ;;
    *)
        echo $EXIT_LINE1
        echo $EXIT_LINE2
        exit
    ;;
    esac
    unset EXIT_LINE1
    unset EXIT_LINE2
}

LINE1="Please enter the username of the user "
LINE2="account you wish to delete from system:"
get_answer
EXIT_LINE1="error"
EXIT_LINE2="error1"
process_answer