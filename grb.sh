#!/bin/bash
while [[ 1 ]]
do
cat fastgreen.dat | ./fastlights
sleep .05
cat fastred.dat | ./fastlights
sleep .05
 cat fastlights.dat | ./fastlights
sleep .05
done
