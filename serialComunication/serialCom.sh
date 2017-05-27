#!/bin/bash

# if there is any error exit
set -e

port="ttyUSB0";
baud="9600";

# run mannually in a shell
# find which port arduino uses
# ls -l /sys/bus/usb-serial/devices/

# change port's permissions
# sudo chmod 666 /dev/port



function viewMsg {
	stty -F /dev/$port $baud
	sleep 2
	stty -F /dev/$port raw
	sleep 2
	while true; do
		cat < /dev/$port
	done
}

# sendMsg function will only work if viewMsg is running too in some other tty 

function sendMsg {
	while true; do
		echo "Enter message >"
		read msg
		echo $msg > /dev/$port
		echo "wait"
		sleep 3 # wait for the buffer to get cleaned
	done
	
}

# use tmux to see in one pane the messages that the board sends
# and in another pane the commands prompt 
function openTmux {
	session="SerialCom"
	tmux -2 new-session -d -s $session
	tmux rename-window "main"
	tmux send-keys "./serialCom.sh 1" C-m
	tmux split-window -v # change to -h if your prefer horizontal
	tmux send-keys "./serialCom.sh 2" C-m
	tmux attach -t $session
}


if [ "$1" == "1" ]
then
	viewMsg
elif [ "$1" == "2" ]
then
	sendMsg
elif [ "$1" == "3" ]
then
	openTmux
else
	echo "unknown input"
fi
