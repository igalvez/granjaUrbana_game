#!/bin/bash

processos=`ps | grep "granja" | cut -d"p" -f1`

for p in $processos
do
	kill -KILL $p
done
