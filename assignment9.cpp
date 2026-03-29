#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct student{
    int id;
    char name[30];
    double gpa;
};
void write(const student s[], int size){
    fstream output;
    output.open("input.dat", ios::out | ios::binary);
    if(output){
        output.write(reinterpret_cast<const char *>(s), sizeof(student)*size);
        output.close();
    }
    else{
        cout<<"ERROR";
    }
}
void read(){
    fstream input;
    input.open("input.dat", ios::in | ios::binary);
    const int size = 3;
    student s1[size];
    int i;
    if(input){
        input.read(reinterpret_cast<char *>(s1), sizeof(s1));
        for(i = 0; i<size; i++){
            cout<<"ID: "<<s1[i].id<<" ";
            cout<<"Name: "<<s1[i].name<<" ";
            cout<<"GPA: "<<s1[i].gpa<<" ";
            cout<<endl;
        }
    }
    else{
        cout<<"ERROR";
    }
}
double cal(const student s[], int size){
    int i;
    double x = 0;
    for(i = 0; i<size; i++){
        x += s[i].gpa;
    }
    x = x/size;
    return x;
}
int main() {
    const int size = 3;
    student s[size];
    int i;
    for(i = 0; i<size; i++){
        cin>>s[i].id;
        cin.ignore();
        cin.getline(s[i].name, 30);
        cin>>s[i].gpa;
        cin.ignore();
    }
    write(s, size);
    cout<<endl;
    read();
    cout<<"Average GPA: ";
    double gpa = cal(s, size);
    cout<<gpa;
}
