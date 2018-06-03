cafe : main.o Beverage.o Cafe.o CafeList.o Coffee.o Order.o OrderList.o Product.o ProductDatabase.o Cake.o CitiesList.o
	g++ -Wall -g -o cafe main.o Beverage.o Cafe.o CafeList.o Coffee.o Order.o OrderList.o Product.o ProductDatabase.o Cake.o CitiesList.o
	
	
Product.o : Product.cpp Product.h
	g++ -Wall -g -c Product.cpp
	
Beverage.o : Beverage.cpp Beverage.h  Product.h
	g++ -Wall -g -c Beverage.cpp

Cafe.o : Cafe.cpp Cafe.h OrderList.h
	g++ -Wall -g -c Cafe.cpp
	
CafeList.o: CafeList.cpp CafeList.h  Cafe.h
	g++ -Wall -g -c CafeList.cpp
	
Cake.o: Cake.cpp Cake.h Product.h
	g++ -Wall -g -c Cake.cpp
	
CitiesList.o: CitiesList.cpp CitiesList.h  CafeList.h
	g++ -Wall -g -c CitiesList.cpp	
	
Coffee.o: Coffee.cpp Coffee.h  Product.h
	g++ -Wall -g -c Coffee.cpp
	
Order.o: Order.cpp Order.h ProductDatabase.h
	g++ -Wall -g -c Order.cpp
	
OrderList.o: OrderList.cpp OrderList.h Order.h
	g++ -Wall -g -c OrderList.cpp
	
main.o : main.cpp CafeLib.h
	g++ -Wall -g -c main.cpp

clean:
	rm -f *.o

distclean:
	rm -f cafe
