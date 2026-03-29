#include <iostream>
#include <string>
using namespace std;
struct getinfo{
    string name;
    string city;
};
enum status{
    pending, shipped, delivered
};
struct package{
    int id;
    double weight;
    getinfo get;
    status stat;
};
package input(){
    package p;
    int x;
    cin>>ws>>p.id;
    cin>>p.weight;
    getline(cin>>ws, p.get.name);
    getline(cin>>ws, p.get.city);
    cin>>ws>>x;
    p.stat = static_cast<status>(x);
    return p;
}
void show(const package &p){
    cout<<"ID: "<<p.id<<endl;
    cout<<"Weight: "<<p.weight<<endl;
    cout<<"Receiver: "<<p.get.name<<endl;
    cout<<"City: "<<p.get.city<<endl;
    cout<<"Status: ";
    switch(p.stat){
        case 0: cout<<"PENDING"; break;
        case 1: cout<<"SHIPPED"; break;
        case 2: cout<<"DELIVIRED"; break;
        default: break;
    }
    cout<<endl;
}
double total(const package p[], int size){
    int i;
    double x = 0;
    for(i = 0; i<size; i++){
        x += p[i].weight;
    }
    return x;
}
int delivired(const package p[], int size){
    int x = 0;
    int i;
    for(i = 0; i<size; i++){
        if(p[i].stat==2){
            x += 1;
        }
    }
    return x;
}

int main() {
    const int size = 3;
    package p[3];
    int i;
    for(i = 0; i<size; i++){
        p[i] = input();
    }
    cout<<endl;
    for(i = 0; i<size; i++){
        cout<<"Package: "<<i+1<<endl;
        show(p[i]);
        cout<<endl;
    }
    double totalw = total(p, size);
    cout<<"Total weight: "<<totalw<<endl;
    int d = delivired(p, size);
    cout<<"Delivered packages: "<<d;
}
