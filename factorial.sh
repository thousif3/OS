read -p "Enter the number to calculate factorial for: " n

if [[ $n -ge 0 ]]; then
  result=1
  for i in $(seq 2 $n); do
    result=$(( $result * $i ))
  done
  echo "The factorial of $n is $result"
else
  echo "Please enter a non-negative number."
fi
