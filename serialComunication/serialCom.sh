#!/bin/bash

port="ttyUSB0";
baud="9600";


function viewMsg {
	stty -F /dev/$port $baud
	sleep 2
	stty -F /dev/$port raw
	sleep 2
	cat < /dev/$port
}

# sendMsg function will only work if viewMsg is running too in some other tty 

function sendMsg {
	while true; do
		echo "Enter message >"
		read msg
		echo $msg > /dev/$port
		sleep 3 # wait for the buffer to get cleaned
	done
	
}

echo  "Enter 1 to view messages| 2 to send messages"
read option

if [ $option == 1 ]
then
	viewMsg
elif [ $option == 2 ]
then
	sendMsg
else
	echo "unknown input"
fi
