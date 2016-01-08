#!/bin/bash

FILES=$(find ./ -name "*.cpp")

for file in $FILES
do 
    sed '1i\#include "overloadNew.h"' $file > $file.bak
    mv $file.bak $file
done
