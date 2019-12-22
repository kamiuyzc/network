#!/bin/bash


a=`echo {a..z}`
echo "orig value $a"
#sub
a=${a// /}
echo "after sub $a"
#length
echo "length ${#a}"
#match length
matchlength1=`expr match "$a" "abcde"`
matchlength2=`expr "$a" : "abcd"`
matchlength3=`expr "$a" : ".*"`
echo "match length $matchlength1 $matchlength2 $matchlength3"

#match index
echo $a
expr index "$a" '888z'
#echo $indexinfo

#子串提取
echo "sub ${a:1}"
echo "sub ${a:3:5}"
echo "sub ${a: -5:2}"
echo "expr substr `expr substr "$a" 4 5`"
arraya=(a b c d)
echo "array sub ${@:2:4}"

#"提取"
a=${a}abce
echo "abstract  start `expr "$a" : "\(abc[a-z]\)"`"
echo "abstract end `expr "$a" : ".*\(abc[a-z]\)"`"


#"sub move"
echo "before m ${a#a*c} ${a##a*c}"
echo "after m ${a%b*e} ${a%%b*e}"

#"subreplace"
echo "replace ${a/abc/***} ${a//abc/***}"
echo "replace before ${a/#abc/***} ${a/%abce/***}"

