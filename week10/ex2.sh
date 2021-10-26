link ~/asiia/week01/file.txt ex2.txt      
find ../week01/ -inum 5012985
find .. -inum 5012985 -exec rm {} \; 
