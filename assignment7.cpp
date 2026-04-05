#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct employee{
    int id;
    string name;
    double salary;
};
int main() {
    const int size = 3;
    employee arr[size];
    employee tread[size];
    int i;
    cout<<"Enter details for 3 employees:"<<endl;
    for(i = 0; i<size; i++){
        cout<<"Employee "<<i+1<<":"<<endl;
        cout<<"ID:";
        cin>>arr[i].id;
        cin.ignore();
        cout<<"Name:";
        getline(cin, arr[i].name);
        cout<<"Salary:";
        cin>>arr[i].salary;
        cin.ignore();
        cout<<endl;
    }
    fstream output("output.txt", ios::in |ios::out);
    cout<<"Contents of text file (employees.txt):"<<endl;
    for(i = 0; i<size; i++){
        output<<arr[i].id;
        output<<arr[i].name<<"\n";
        output<<arr[i].salary<<" ";
    }
    output.seekg(0);
    for(i = 0; i<size; i++){
        output>>tread[i].id;
        getline(output, tread[i].name);
        output>>tread[i].salary;
    }
    for(i = 0; i<size; i++){
        cout<<"ID: "<<tread[i].id<<", ";
        cout<<"Name: "<<tread[i].name<<", ";
        cout<<"Salary: "<<tread[i].salary<<endl;
    }
    fstream binar("output.dat", ios::in | ios::out | ios::binary);
    binar.write(reinterpret_cast<char *>(&tread), sizeof(employee)*size);
    binar.seekg(0);
    employee three[size];
    binar.read(reinterpret_cast<char *>(&three), sizeof(three));
    cout<<endl;
    cout<<"Contents of binary file (employees.dat):"<<endl;
    for(i = 0; i<size; i++){
        cout<<"ID: "<<three[i].id<<", ";
        cout<<"Name: "<<three[i].name<<", ";
        cout<<"Salary: "<<three[i].salary<<endl;
    }
    int cid;
    double news;
    cout<<"Enter Employee ID to update salary: ";
    cin>>cid;
    cout<<"Enter new salary:";
    cin>>news;
    employee emp;
    binar.seekg(0);
    while(binar.read(reinterpret_cast<char *>(&emp), sizeof(emp))){
        if(cid==emp.id){
            emp.salary = news;
            binar.seekp(-static_cast<int>(sizeof(emp)), ios::cur);
            binar.write(reinterpret_cast<char*>(&emp), sizeof(emp));
            break;
        }
    }
    binar.seekg(0);
    employee four[size];
    binar.read(reinterpret_cast<char *>(&four), sizeof(four));
    cout<<endl;
    cout<<"Contents of binary file (employees.dat):"<<endl;
    for(i = 0; i<size; i++){
        cout<<"ID: "<<four[i].id<<", ";
        cout<<"Name: "<<four[i].name<<", ";
        cout<<"Salary: "<<four[i].salary<<endl;
    }
    output.close();
}
