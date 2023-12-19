echo -n "Enter a number: "
read n
t=$n
sum=0
while [ $n -gt 0 ]
do 
    rem=$((n%10))
    cube=$((rem*rem*rem))
    sum=$((sum+cube))
    n=$((n/10))
done
if [ $sum == $t ]
then
    echo "$t is a Armstrong Number"
else
    echo "$t is not a Armstrong Number"
fi
