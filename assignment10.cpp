#include <iostream>
#include <string>
using namespace std;
class item{
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    item();
    void setdata(int, string, int, double);
    int getid() const;
    string getname() const;
    int getquantity() const;
    double getprice() const;

    double total() const;
};
item::item() {}
void item::setdata(int i, string n, int q, double p){
    id = i;
    name = n;
    quantity = q;
    price = p;
}
int item::getid() const{
    return id;
}
string item::getname() const{
    return name;
}
int item::getquantity() const{
    return quantity;
}
double item::getprice() const {
    return price;
}
double item::total() const {
    return quantity*price;
}
int main() {
    const int size = 3;
    item stuff[size];
    int id;
    string name;
    int quantity;
    double price;
    int i;
    for(i = 0; i<size; i++){
        cin>>id;
        cin.ignore();
        getline(cin, name);
        cin>>quantity;
        cin.ignore();
        cin>>price;
        cin.ignore();
        stuff[i].setdata(id, name, quantity, price);
    }
    for(i = 0; i<size; i++){
        cout<<"ID: "<<stuff[i].getid()<<" ";
        cout<<"Name: "<<stuff[i].getname()<<" ";
        cout<<"Quantity: "<<stuff[i].getquantity()<<" ";
        cout<<"Price: "<<stuff[i].getprice()<<" ";
        cout<<"Total: "<<stuff[i].total()<<endl;
    }
    double x = 0;
    for(i = 0; i<size; i++){
        x += stuff[i].total();
    }
    cout<<"Total Inventory Value: "<<x;
}
