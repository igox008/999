#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: mleak <process_name>"
    exit 1
fi

process_name="$1"

while true
do
    clear
    leaks $process_name
    sleep 1
done
