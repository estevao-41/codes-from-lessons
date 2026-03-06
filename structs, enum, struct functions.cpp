#include <iostream>
#include <string>
using namespace std;
struct PersonInfo{
    string name;
    string city;
};
enum year{
    freshman = 1, sophomore, junior, senior
};
struct student{
    int studentid;
    PersonInfo pData;
    year yearinschool;
    double gpa;
};
student fun(){
    student s;
    int x;
    cout<<"studentID: ";
    cin>>s.studentid;
    cout<<"name: ";
    getline(cin>>ws, s.pData.name);
    cout<<"city: ";
    getline(cin>>ws, s.pData.city);
    cout<<"year number: ";
    cin>>x;
    s.yearinschool = static_cast<year>(x);
    cout<<"gpa: ";
    cin>>s.gpa;
    cout<<endl;
    return s;
}
void printstudent(const student *s){
    cout<<"studentID: ";
    cout<<s->studentid<<endl;
    cout<<"name: ";
    cout<<s->pData.name<<endl;
    cout<<"city: ";
    cout<<s->pData.city<<endl;
    cout<<"year number: ";
    switch(s->yearinschool){
        case 1: cout<<"freshman"<<endl; break;
        case 2: cout<<"sophomore"<<endl; break;
        case 3: cout<<"junior"<<endl; break;
        case 4: cout<<"senior"<<endl; break;
        default: cout<<"freshman"<<endl; break;
    }
    cout<<"gpa: ";
    cout<<s->gpa<<endl;
    cout<<endl;
}
double averagegpa(const student arr[], int size){
    cout<<"Average GPA: ";
    int i;
    double x = 0;
    for(i = 0; i<size; i++){
        x = x + arr[i].gpa;
    }
    x = x/size;
    cout<<x<<endl;
    return 0;
};
int topstudent(const student arr[], int size){
    cout<<"Top student ID: ";
    int i, j, x = 0;
    for(i = 0; i<size; i++){
        x = 0;
        for(j = 0; j<size; j++){
            if(arr[i].gpa>arr[j].gpa){
                x = x + 1;
            }
        }
        if(x==size-1){
            const student *pointer = &arr[i];
            cout<<pointer->studentid;
            return 0;
        }
    }
    cout<<endl;
}
void updategpa(student &s, double newgpa){
    s.gpa = newgpa;
}
int main(){
    const int size = 3;
    student s[size];
    int i;
    for(i = 0; i<size; i++){
        s[i] = fun();
    }
    student *pointer[size];
    for(i = 0; i<size; i++){
        pointer[i] = &s[i];
        printstudent(pointer[i]);
    }
    averagegpa(s, size);
    cout<<endl;
    topstudent(s, size);
    cout<<endl;
    int c;
    double newgpa;
    cout<<"Which students GPA you want to change: ";
    cin>>c;
    cout<<"what GPA: ";
    cin>>newgpa;
    updategpa(s[c-1], newgpa);
    cout<<"New GPA of student "<<c<<" is: "<<s[c-1].gpa;
}
