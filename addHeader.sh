#!/bin/bash

FILES=$(find ./ -name "*.h")

for file in $FILES
do 
    sed '4d' $file > $file.bak
    mv $file.bak $file
done
