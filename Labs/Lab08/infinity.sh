#Script to run and sleep for 15 seconds,
#Should output message to file still-going.txt

#!/bin/sh

#while will remain true hence the execution until process is killed
while :
do
          #write "Still going!" To file still-going.txt

            echo "Still going!" >> still-going.txt

              # sleep the thread for 15 seconds

                sleep 15s
        done
