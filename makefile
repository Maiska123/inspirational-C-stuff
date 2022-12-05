all: App

App: main.o
	g++ main.o test.o meeting.o user.o -o build\Debug\outDebug

main.o: test.o meeting.o user.o 
	g++ -I . -c -std=c++17 -Wall -Wextra -Wpedantic -Werror main.cpp -Iclasses test.cpp .\classes\meeting.cpp .\classes\user.cpp 

test.o:
	g++ -c -std=c++17 -Wall -Wextra -Wpedantic -Werror test.cpp

meeting.o: # if we want to describe buildable depenencies add after like: meeting.cpp
	g++ -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\classes\meeting.cpp

user.o:
	g++ -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\classes\user.cpp

# meeting.cpp:
# 	g++ -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\classes\meeting.cpp