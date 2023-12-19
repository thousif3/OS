a=0
b=1

read -p "Enter the number of Fibonacci numbers to generate: " n

for i in $(seq 1 $n); do
  echo $a
  temp=$a
  a=$b
  b=$((a + temp))
done
