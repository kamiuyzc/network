#!/bin/bash
#22.1.1.1
#gawk 'BEGIN{FS=","} {print  $1,$2,$3}' data1

#gawk 'BEGIN{FS=",";OFS="-"}{print $1,$2,$3}'  data1

#22.1.1.2
#gawk 'BEGIN{FIELDWIDTHS="3 5 2 5"}{print $1,$2,$3,$4}' data1b

#22.1.1.3
#gawk 'BEGIN{FS="\n";RS=""}{print $1,$4}' data2

#22.1.1.4
#gawk 'BEGIN{print ARGC,ARGV[0],ENVIRON["PATH"]}' data1

#22.1.1.5
#gawk 'BEGIN{FS=":";OFS=":"}{print NR,FNR,$1,$NF}' /etc/passwd /etc/passwd

#22.1.2.1
#gawk 'BEGIN{test=12345;test1="asdf";print test;print test1}'

#22.1.2.2
#gawk 'BEGIN{a=1;a=a*2+1;print a}'

#22.1.2.3
#gawk -f script1 n=2 data1
#gawk 'BEGIN{FS=","}{print $n}' n=3 data1

#22.1.2.4
gawk  -v nn=3 'BEGIN{print nn}'