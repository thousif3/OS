#!/bin/bash

read -p "Enter a decimal number: " num

binary=""

while [[ $num -gt 0 ]]; do
  remainder=$((num % 2))  
  binary="${remainder}${binary}"  
  num=$((num / 2))  
done

echo "The binary equivalent is: $binary"
