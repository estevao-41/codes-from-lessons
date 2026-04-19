#include <iostream>
#include <string>
using namespace std;
class book{
private:
    string title;
    string author;
    int page;
    static int bookcount;

public:
    book(){
        bookcount++;
    }
    book(const book &obj){
        title = obj.title;
        author = obj.author;
        page = obj.page;
        bookcount++;
    }
    void setdata(string t, string a, int p){
        title = t;
        author = a;
        page = p;
    }
    bool operator==(const book &obj){
        if(title==obj.title && author==obj.author){
            return true;
        }
        else{
            return false;
        }
    }
    static int getbookcount(){
        return bookcount;
    }
};
int book::bookcount = 0;
int main() {
    const int size = 3;
    book kniga[size];
    int i, p; string t, a;
    for(i = 0; i<size; i++){
        getline(cin, t);
        getline(cin, a);
        cin>>p;
        cin.ignore();
        kniga[i].setdata(t, a, p);
    }
    cout<<"Copy of which book you want:";
    cin>>i;
    cin.ignore();
    book niga = kniga[i-1];
    cout<<"Which books you want to compare:";
    cin>>i;
    cin.ignore();
    if(niga==kniga[i-1]){
        cout<<"Books are same"<<endl;
    }
    else{
        cout<<"Books are not same"<<endl;
    }
    cout<<"Total amount of books: "<<book::getbookcount();
}
