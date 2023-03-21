CXX		  := g++ 
CXX_FLAGS :=   -std=c++17 -ggdb 

all: AES

AES: 
	$(CXX)  -o ./AES ./*.cpp 

clean:

	rm -f ./AES