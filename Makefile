all: parking_lot.cpp
	g++ -std=c++11 parking_lot.cpp -o parking_lot

clean:
	$(RM) parking_lot
