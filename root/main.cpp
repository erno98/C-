

 #include "CafeLib.h"

using namespace std;

int main() {

// tests
    Cafe cafe1("Warsaw", "01-102", "Nowowiejska", 3);
    Cafe cafe2("Warsaw", "01-103", "Krucza", 18);
    Cafe cafe3("New York", "11-312", "15th Street", 22);
    Cafe cafe4("Los Angeles", "43-001", "Kenwyn Ct", 17);
    cafe2.displayAddress();
    cafe4.displayAddress();


    cout << "================================" << endl;

    CafeList cafeList1("Warsaw");
    cafeList1.addCafe(cafe1);
    cafeList1.addCafe(cafe2);

    cafeList1.addCafe(cafe4);

    cafeList1.displayCafes();


    cout << "================================" << endl;

    cafeList1.removeCafe(1);
    cafeList1.displayCafes();


    Beverage cola("Coca Cola", 3.50, true);
    Beverage beer("Beer", 8.90, true);
    beer.getBeverageInfo();
    Cake cake("Cake", 25, true);
    Coffee coffee(4, 1, "Kopi Luwak", 890, false);

    ProductDatabase database;
    database.add(cola);
    database.add(beer);
    database.add(cake);
    database.add(coffee);
    database.add("Banana Cupcakes", 15.30);
    database.displayProducts();

    cout << "--------------------------------" << endl;

    database.removeByName("Water");
    database.displayProducts();

    cout << "================================" << endl;

    Order order1;

    order1.add(cola, 15, database);
    order1.add("Beer", 30, database);
    order1.add("Wine", 10, database);

    order1.displayInfo();

    cout << "--------------------------------" << endl;

    order1.removeProduct("Wine");
    order1.displayInfo();

    Order order2;
    order2.add(cake, 5, database);
    order2.add(coffee, 60, database);

    cout << "================================" << endl;

    OrderList orderDatabase1;
    orderDatabase1.addOrder(order1);
    orderDatabase1.addOrder(order2);
    orderDatabase1.displayStatus();

    cout << "--------------------------------" << endl;

    orderDatabase1.removeOrder(2);
    orderDatabase1.displayStatus();

    cafe1.setOrderAsDefault(1, orderDatabase1);
    cafe1.executeOrder();
    cafe1.addToBudget(10000);
    cafe1.executeOrder();
    cafe1.executeOrder(order2, orderDatabase1);



    cout << "================================" << endl;

    CitiesList citiesList;
    citiesList.addCity(cafeList1);

    CafeList cafeList2("Los Angeles");
    cafeList2.addCafe(cafe4);

    Cafe cafe5("Warsaw", "01-122", "Nowowiejska", 2);
    cafeList1.addCafe(cafe5);

    citiesList.addCity(cafeList2);
    citiesList.displayStatus();

    return 0;
}