#!/bin/bash
#find the montecarlo method
#hw1 bash scripting
numberoftrials=1000 #t find pie
value=0
deviation=0
exact=`echo "3.14" | bc -l`
i=0  #inside the circle
j=0  #outside the circle
sqrt1=1
  for ((i = 0; i<numberoftrials; i++));
  do
  a=$(awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}')
  b=$(awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}') 
  valuex=`echo "scale=3; $a*$a" | bc -l`
  valuey=`echo "scale=3; $b*$b" | bc`
  sum=`echo "$valuex+$valuey" | bc -l`
  ssqrt=`echo "scale=3; sqrt($sum)"  | bc -l`
  #if (($(echo "$ssqrt <= $sqrt") -eq 1 | bc))
  d=$(echo "$ssqrt < $sqrt1" | bc)
  if [ $d -eq 1 ];
  then
  count=$(($count+1))
  fi 
 i=$(($i+1))
  
  done
#echo $1
#echo $j
value=`echo "scale=3; ($count/$numberoftrials)*4.0" | bc -l`
#pie=`echo "scale=3; $value*4.0" | bc -l`
echo estimated value of pie= $value
deviation=$(echo "scale=3; $exact-$value" | bc -l)
echo deviation= $deviation
#abs=${deviation}
error=`echo "scale=3; $deviation/$exact"| bc -l`
error1=`echo "scale=3; $error*100.0" | bc -l`
echo error= $error1 "%"
exit 0

