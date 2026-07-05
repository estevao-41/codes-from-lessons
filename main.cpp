#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct CourseData{
    int courseID;
    string courseName;
    string instName;
    int credits;
    int capacity;
    string timeslot;
    int enrolled;
};
struct StudentData{
    int studentID;
    int courseID;
    string timeslot;
};
class Courses{
private:
    vector<CourseData> course;
    vector<StudentData> student;
    void loadfiletovec(){
        course.clear();
        CourseData c;
        ifstream file("courses.txt");
        while(file >> c.courseID >> c.courseName >> c.instName >> c.credits >> c.capacity >> c.enrolled >> c.timeslot){
            course.push_back(c);
        }
        file.close();
    }

public:
    Courses(){
        loadfiletovec();
    };
    void AddCourse() {
        CourseData c;
        cout<<"Course ID:";
        cin>>c.courseID;
        for(int i = 0; i<course.size(); i++){
            if(c.courseID==course[i].courseID){
                cout<<"Type unique ID:";
                cin>>c.courseID;
            }
        }
        cin.ignore();
        cout<<"Course Name:";
        getline(cin, c.courseName);
        cout<<"Instructor Name:";
        getline(cin, c.instName);
        cout<<"Credits:";
        cin>>c.credits;
        if(c.credits>6 || c.credits<1){
            cout<<"Credits must be between 1 and 6:";
            cin>>c.credits;
        }
        cin.ignore();
        cout<<"Capacity:";
        cin>>c.capacity;
        if(c.capacity<0){
            cout<<"Capacity must be positive:";
            cin>>c.capacity;
        }
        cin.ignore();
        cout<<"Time Slot:";
        getline(cin, c.timeslot);
        c.enrolled = 0;
        course.push_back(c);

        fstream file("courses.txt", ios::out);
        for(int i = 0; i<course.size(); i++){
            file << course[i].courseID
            <<" "<< course[i].courseName
            <<" "<< course[i].instName
            <<" "<< course[i].credits
            <<" "<<course[i].capacity
            <<" "<<course[i].enrolled
            <<" "<<course[i].timeslot<<endl;
        }
        file.close();
    }
    void ViewAllCourses(){
        CourseData c;
        fstream file("courses.txt", ios::in);
        if(!file || file.peek() == EOF){
            cout<<"No courses available.";
            return;
        }
        cout<<"ID | Name | Instructor | Credits | Capacity | Enrolled | Time"<<endl;
        while(file>>c.courseID>>c.courseName>>c.instName>>c.credits>>c.capacity>>c.enrolled>>c.timeslot){
            cout<< c.courseID
            <<" | "<< c.courseName
            <<" | "<< c.instName
            <<" | "<< c.credits
            <<" | "<<c.capacity
            <<" | "<<c.enrolled
            <<" | "<<c.timeslot<<endl;
        }
        file.close();
    }

    void registration(){
        int studentID, courseID;
        cout<<"CourseID:";
        cin>>courseID;
        cout<<"StudentID:";
        cin>>studentID;
        int index = -1;
        for(int i = 0; i<course.size(); i++){
            if(course[i].courseID == courseID){
                index = i;
                break;
            }
        }
        if(index<0){
            cout<<"Course dont exist"<<endl;
            return;
        }
        if(course[index].capacity<=course[index].enrolled){
            cout<<"capacity is full"<<endl;
            return;
        }
        ifstream file("registration.txt");
        int sid, cid;
        string timeslot;
        while(file>>sid>>cid>>timeslot){
            if(studentID==sid && course[index].timeslot==timeslot){
                cout<<"student has time conflict"<<endl;
                file.close();
                return;
            }
        }
        file.close();

        course[index].enrolled++;
        fstream cfile("courses.txt", ios::out);
        for(int i = 0; i<course.size(); i++){
            cfile << course[i].courseID
                  <<" "<< course[i].courseName
                  <<" "<< course[i].instName
                  <<" "<< course[i].credits
                  <<" "<<course[i].capacity
                  <<" "<<course[i].enrolled
                  <<" "<<course[i].timeslot<<endl;
        }
        cfile.close();
        fstream rfile("registration.txt", ios::app);
        rfile << studentID <<" "<<courseID<<" "<<course[index].timeslot<<endl;
        cout<<"Registration was successful"<<endl;

    }
    void dropCourse(){
        int courseID, studentID;
        cout<<"CourseID:";
        cin>>courseID;
        cout<<"StudentID:";
        cin>>studentID;
        ifstream file("registration.txt");
        StudentData s;
        while(file>>s.studentID>>s.courseID>>s.timeslot){
            student.push_back(s);
        }
        file.close();
        int cindex = -1;
        for(int i = 0; i<course.size(); i++){
            if(courseID==course[i].courseID){
                cindex = i;
                break;
            }
        }
        if(cindex==-1){
            cout<<"Course dont exist"<<endl;
            return;
        }

        int sindex = -1;
        for(int i = 0; i<student.size(); i++){
            if(courseID==student[i].courseID && studentID==student[i].studentID){
                sindex = i;
                break;
            }
        }
        if(sindex==-1){
            cout<<"Student is not enrolled"<<endl;
            return;
        }
        course[cindex].enrolled--;
        fstream cfile("courses.txt", ios::out);
        for(int i = 0; i<course.size(); i++){
            cfile << course[i].courseID
                  <<" "<< course[i].courseName
                  <<" "<< course[i].instName
                  <<" "<< course[i].credits
                  <<" "<<course[i].capacity
                  <<" "<<course[i].enrolled
                  <<" "<<course[i].timeslot<<endl;
        }
        cfile.close();
        student.erase(student.begin()+sindex);
        fstream sfile("registration.txt", ios::out);
        for(int i = 0; i<student.size(); i++){
            sfile << student[i].studentID
                  <<" "<< student[i].courseID
                  <<" "<<student[i].timeslot<<endl;
        }
        sfile.close();
        student.clear();
        cout<<"Course was dropped successfully"<<endl;
    };
    void searchCourse(){
        int courseID;
        string courseName;
        cout<<"CourseID:";
        cin>>courseID;
        cout<<"Course Name:";
        cin>>courseName;
        int index = -1;
        for(int i = 0; i<course.size(); i++){
            if(course[i].courseID==courseID && course[i].courseName==courseName){
                index = i;
                cout<<"ID | Name | Instructor | Credits | Capacity | Enrolled | Time"<<endl;
                cout<< course[i].courseID
                <<" | "<< course[i].courseName
                <<" | "<< course[i].instName
                <<" | "<< course[i].credits
                <<" | "<<course[i].capacity
                <<" | "<<course[i].enrolled
                <<" | "<<course[i].timeslot<<endl;
                break;
            }
        }
        if(index==-1){
            cout<<"Course dont exist"<<endl;
        }
    }

    void creditSort(){
        int i, j;
        vector<CourseData> sort = course;
        CourseData c;
        for(i = 0; i<sort.size()-1; i++){
            for(j = 0; j<sort.size()-i-1; j++){
                if(sort[j].credits>sort[j+1].credits){
                    c = sort[j];
                    sort[j] = sort[j+1];
                    sort[j+1] = c;
                }
            }
        }
        cout<<"ID | Name | Instructor | Credits | Capacity | Enrolled | Time"<<endl;
        for(i = 0; i<sort.size(); i++){
            cout<< sort[i].courseID
                <<" | "<< sort[i].courseName
                <<" | "<< sort[i].instName
                <<" | "<< sort[i].credits
                <<" | "<<sort[i].capacity
                <<" | "<<sort[i].enrolled
                <<" | "<<sort[i].timeslot<<endl;
        }
    }

    void capacitySort(){
        int i, j;
        vector<CourseData> sort = course;
        CourseData c;
        for(i = 0; i<sort.size()-1; i++){
            for(j = 0; j<sort.size()-i-1; j++){
                if(sort[j].capacity-sort[j].credits<sort[j+1].capacity-sort[j+1].credits){
                    c = sort[j];
                    sort[j] = sort[j+1];
                    sort[j+1] = c;
                }
            }
        }
        cout<<"ID | Name | Instructor | Credits | Capacity | Enrolled | Time"<<endl;
        for(i = 0; i<sort.size(); i++){
            cout<< sort[i].courseID
                <<" | "<< sort[i].courseName
                <<" | "<< sort[i].instName
                <<" | "<< sort[i].credits
                <<" | "<<sort[i].capacity
                <<" | "<<sort[i].enrolled
                <<" | "<<sort[i].timeslot<<endl;
        }
    }

    void nameSort(){
        vector<CourseData> sort = course;
        CourseData c;
        int i, j;
        for(i = 0; i<sort.size()-1; i++){
            for(j = 0; j<sort.size()-i-1; j++){
                if(sort[j].courseName>sort[j+1].courseName){
                    c = sort[j];
                    sort[j] = sort[j+1];
                    sort[j+1] = c;
                }
            }
        }
        cout<<"ID | Name | Instructor | Credits | Capacity | Enrolled | Time"<<endl;
        for(i = 0; i<sort.size(); i++){
            cout<< sort[i].courseID
                <<" | "<< sort[i].courseName
                <<" | "<< sort[i].instName
                <<" | "<< sort[i].credits
                <<" | "<<sort[i].capacity
                <<" | "<<sort[i].enrolled
                <<" | "<<sort[i].timeslot<<endl;
        }
    }

    void sortCourse(){
        int way;
        cout<<"Choose the way of sorting:"<<endl;
        cout<<"1.Course Name"<<endl;
        cout<<"2.Credits"<<endl;
        cout<<"3.Available seats"<<endl;
        cin>>way;
        switch(way){
            case 1:
                nameSort();
                break;
            case 2:
                creditSort();
                break;
            case 3:
                capacitySort();
                break;
        }
    }

    void backUp(){
        ofstream file("backup.txt");
        ifstream cfile("courses.txt");
        string copy;
        while(getline(cfile, copy)){
            file<<copy<<endl;
        }
        file.close();
        cfile.close();
        cout<<"Course data saved successfully. Goodbye!"<<endl;
    }
};
int main() {
    int menu;
    Courses Manager;
    while(true){
        cout<<"1.Add New Course"<<endl;
        cout<<"2.View All Courses"<<endl;
        cout<<"3.Register to Course"<<endl;
        cout<<"4.Drop Course"<<endl;
        cout<<"5.Search Course"<<endl;
        cout<<"6.Sort Courses"<<endl;
        cout<<"7.Save & Exit"<<endl;
        cout<<"Enter the number:"<<endl;
        cin>>menu;
        switch(menu){
            case 1:
                Manager.AddCourse();
                break;
            case 2:
                Manager.ViewAllCourses();
                break;
            case 3:
                Manager.registration();
                break;
            case 4:
                Manager.dropCourse();
                break;
            case 5:
                Manager.searchCourse();
                break;
            case 6:
                Manager.sortCourse();
                break;
            case 7:
                Manager.backUp();
                break;
            default:
                cout<<"From 1 to 7:";
                break;
        }
        if(menu==7){
            break;
        }
    }
}