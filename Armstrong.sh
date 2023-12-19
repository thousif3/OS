read -p "Enter a number: " n
t=$n
sum=0
while [ $n -gt 0 ]
do
   sum=$((sum + ((n%10) * (n%10) * (n%10))))  
   n=$((n/10))
done
if [ $sum == $t ]
then
   echo "$t is an Armstrong Number"
else
   echo "$t is not an Armstrong Number"
fi
