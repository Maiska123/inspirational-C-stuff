ifeq ($(BUILD),debug)   
# "Debug" build - no optimization, and debugging symbols
CFLAGS += -O0 -g
else
# "Release" build - optimization, and no debug symbols
CFLAGS += -O2 -s -DNDEBUG
endif
#
# make BUILD=debug
#

all: App

debug:
    make "BUILD=debug"

ifeq ($(BUILD),debug)   

App: main.o
	@mkdir -p build\Debug
	g++ main.o test.o meeting.o user.o -o build\Debug\outDebug
else

App: main.o
	@mkdir -p build\Release
	g++ main.o test.o meeting.o user.o -o build\Release\releaseApplication
endif


main.o: test.o meeting.o user.o 
	g++ $(CFLAGS) -I . -c -std=c++17 -Wall -Wextra -Wpedantic -Werror main.cpp -Iclasses test.cpp .\classes\meeting.cpp .\classes\user.cpp 

test.o:
	g++ $(CFLAGS) -c -std=c++17 -Wall -Wextra -Wpedantic -Werror test.cpp

meeting.o: # if we want to describe buildable depenencies add after like: meeting.cpp
	g++ $(CFLAGS) -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\classes\meeting.cpp

user.o:
	g++ $(CFLAGS) -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\classes\user.cpp

# meeting.cpp:
# 	g++ -c -std=c++17 -Wall -Wextra -Wpedantic -Werror .\classes\meeting.cpp

.PHONY: clean

clean: rm *.o 
