#!/bin/bash
fun(){
echo "hello world !"
name="panjing"
myU1r="i know u are "$name"! "
myU1r_1="i know u are ${name}! "
echo $myU1r $myU1r_1 
echo ${#myU1r}
echo ${myU1r:2:3}
echo `expr index ${name} i`
array=(a bbbbbbbbbbbb c d)
value2=${array[2]}
echo ${value2}
echo ${array[@]}
echo ${#array[*]}
echo ${#array[1]}
var='www.baidu.com/12333.html'
echo ${var#*b}
echo ${var##*1}
echo ${var%.*}
echo ${var%%3*}
echo ${var:0-6}
echo ${var:3:8}
str1="abc"
str2="abc"
if [ "$str1" = "$str2" ]
then
	echo "same"
else
	echo "diff"
fi
str="www.baidu.com"
echo ${str:0-2:2}
}
s="woau"
d="sadsa"
a="$s""$d"
echo "$a"

