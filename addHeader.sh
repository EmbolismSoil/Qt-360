#!/bin/bash

FILES=$(find ./ -name "*.h")

for file in $FILES
do 
    sed '4i\#include "overloadNew.h"' $file
done    
