#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct employee{
    int id;
    char name[50];
    double salary;
};
void text(employee arr[], int size){
    int i;
    cout<<"Enter details for 3 employees:"<<endl;
    for(i = 0; i<size; i++){
        cout<<"Employee "<<i+1<<":"<<endl;
        cout<<"ID:";
        cin>>arr[i].id;
        cin.ignore();
        cout<<"Name:";
        cin.getline(arr[i].name, 50);
        cout<<"Salary:";
        cin>>arr[i].salary;
        cin.ignore();
        cout<<endl;
    }
}
void writetext(employee arr[], int size, const string& filename){
    int i;
    fstream output(filename, ios::in |ios::out);
    cout<<"Contents of text file (employees.txt):"<<endl;
    for(i = 0; i<size; i++){
        output<<arr[i].id;
        output<<arr[i].name<<"\n";
        output<<arr[i].salary<<" ";
    }
    output.seekg(0);
    output.close();
}
void readtext(int size, const string& filename){
    int i;
    employee tread;
    fstream output(filename, ios::in | ios::out);
    for(i = 0; i<size; i++){
        output>>tread.id;
        output.getline(tread.name, 50);
        output>>tread.salary;
        cout<<"ID: "<<tread.id<<", ";
        cout<<"Name: "<<tread.name<<", ";
        cout<<"Salary: "<<tread.salary<<endl;
    }
    output.close();
}


void binar(employee arr[], const string& filename, int size){
    fstream binar(filename, ios::in | ios::out | ios::binary);
    binar.write(reinterpret_cast<char *>(arr), sizeof(employee)*size);
    binar.close();
}
void readbinar(const string& filename){
    employee three;
    fstream binar(filename, ios::in | ios::out | ios::binary);
    cout<<"Contents of binary file (employees.dat):"<<endl;
    while(binar.read(reinterpret_cast<char *>(&three), sizeof(three))){
        cout<<"ID: "<<three.id<<", ";
        cout<<"Name: "<<three.name<<", ";
        cout<<"Salary: "<<three.salary<<endl;
    }
    binar.close();
}
void fix(const string &filename, int cid, double news){
    fstream binar(filename, ios::in | ios::out | ios::binary);
    employee emp;
    while(binar.read(reinterpret_cast<char *>(&emp), sizeof(emp))){
        if(cid==emp.id){
            emp.salary = news;
            binar.seekp(-static_cast<int>(sizeof(emp)), ios::cur);
            binar.write(reinterpret_cast<char*>(&emp), sizeof(emp));
            break;
        }
    }
    binar.close();
}
int main() {
    const int size = 3;
    employee arr[size];
    string textfile = "output.txt";
    string binaryfile = "output.dat";
    text(arr, size);
    writetext(arr, size, textfile);
    cout<<endl;
    readtext(size, textfile);
    binar(arr, binaryfile, size);
    cout<<endl;
    readbinar(binaryfile);
    cout<<endl;
    int cid;
    double news;
    cout<<"Enter Employee ID to update salary: ";
    cin>>cid;
    cout<<"Enter new salary:";
    cin>>news;
    fix(binaryfile, cid, news);
    cout<<endl;
    readbinar(binaryfile);
}
