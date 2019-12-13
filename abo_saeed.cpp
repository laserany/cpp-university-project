//Name: Nedaa Mohammad
//ID: 1834121
//Serial number: 48
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iomanip> 
#include <algorithm>

using namespace std;

static int id_counter = 2017401;

class Student {
    public:
        int id;
        string first_name;
        string last_name;
        int score;
        Student(string first_name, string last_name)
        {
            this->id = id_counter++;
            this->first_name = first_name;
            this->last_name = last_name;
            this->score = rand() % 46 + 50;
        }
};

bool score_comparator(Student s1, Student s2) {
    return s1.score>s2.score;
}

int main()
{
    srand ( time(NULL) );
    Student student1("Khalil","Yousef");
    Student student2("Mohammad","Khalid");
    Student student3("Suhib","Mohd");
    Student student4("John","Jamal");
    Student student5("Hamzeh","Nabeel");
    Student student6("Nadeen","Rafat");
    Student student7("Fadi","Ali");
    Student student8("Ruba","Omar");
    Student student9("Baraa","Hasan");
    Student student10("Ahmad","Tamer");
    Student students[] = {student1,student2,student3,student4,student5,student6,student7,student8,student9,student10};

    cout<<"Displaying all students:-\n"<<endl;
    cout<<"first name | last name | score | id"<<endl;
    for (int i = 0;i<sizeof(students)/sizeof(students[0]);i++) {
        cout<<students[i].first_name<<setw(students[i].last_name.length()-students[i].first_name.length()+13)<<students[i].last_name<<setw(14-students[i].last_name.length())<<students[i].score<<setw(13)<<students[i].id<<endl;
    }
    cout<<endl;
    cout<<"Displaying student with maximum score:-:\n"<<endl;
    sort(students,students+sizeof(students)/sizeof(students[0]),score_comparator);
    cout<<"first name | last name | score | id"<<endl;
    cout<<students[0].first_name<<setw(students[0].last_name.length()-students[0].first_name.length()+13)<<students[0].last_name<<setw(14-students[0].last_name.length())<<students[0].score<<setw(13)<<students[0].id<<endl;
    int student_id;
    cout<<"Please enter the student ID: ";
    cin>>student_id;
    for (int i = 0;i<sizeof(students)/sizeof(students[0]);i++) {
        if (student_id == students[i].id) {
            cout<<"student initials are: "<<students[i].first_name.at(0)<<"."<<students[i].last_name.at(0)<<" and his/her ID is "<<students[i].id<<" and his/her score is "<<students[i].score<<endl;
            break;
        }
        if (i == sizeof(students)/sizeof(students[0])-1) {
            cout<<"Could not find a student with student id "<<student_id<<endl;
        }   
    }
    char student_grade;
    do {
        cout<<"Please enter a valid student grade: ";
        cin>>student_grade;
    }
    while(!(student_grade == 'A' || student_grade == 'B' || student_grade == 'C' || student_grade == 'D' || student_grade == 'F'));
    cout<<"first name | last name | score | id"<<endl;
    for (int i = 0;i<sizeof(students)/sizeof(students[0]);i++) {
        switch(student_grade) {
            case 'A':
                if(students[i].score>=90) {
                    cout<<students[i].first_name<<setw(students[i].last_name.length()-students[i].first_name.length()+13)<<students[i].last_name<<setw(14-students[i].last_name.length())<<students[i].score<<setw(13)<<students[i].id<<endl;
                }
                break;
            case 'B':
                if(students[i].score>=80 && students[i].score<90) {
                    cout<<students[i].first_name<<setw(students[i].last_name.length()-students[i].first_name.length()+13)<<students[i].last_name<<setw(14-students[i].last_name.length())<<students[i].score<<setw(13)<<students[i].id<<endl;
                }
                break;
            case 'C':
                if(students[i].score>=70 && students[i].score<80) {
                    cout<<students[i].first_name<<setw(students[i].last_name.length()-students[i].first_name.length()+13)<<students[i].last_name<<setw(14-students[i].last_name.length())<<students[i].score<<setw(13)<<students[i].id<<endl;
                }
                break;
            case 'D':
                if(students[i].score>=60 && students[i].score<70) {
                    cout<<students[i].first_name<<setw(students[i].last_name.length()-students[i].first_name.length()+13)<<students[i].last_name<<setw(14-students[i].last_name.length())<<students[i].score<<setw(13)<<students[i].id<<endl;
                }
                break;
            case 'F':
                if(students[i].score<60) {
                    cout<<students[i].first_name<<setw(students[i].last_name.length()-students[i].first_name.length()+13)<<students[i].last_name<<setw(14-students[i].last_name.length())<<students[i].score<<setw(13)<<students[i].id<<endl;
                }
                break;
        }
    }
    return 0;
}