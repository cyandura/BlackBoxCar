#!/bin/bash
echo "Forwards"
python car_control.py 1
sleep 3

echo "Left"
python car_control.py 2
sleep 3

echo "Right"
python car_control.py 3
sleep 3

echo "Reverse Reverse"
python car_control.py 4
sleep 2

echo "Go Grizhacks"
python car_control.py "GrizzHacks4!"
sleep 2
