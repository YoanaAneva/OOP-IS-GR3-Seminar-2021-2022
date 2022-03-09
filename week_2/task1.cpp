#include <iostream>
#include <fstream>

struct Student{
    char facNum[10];
    char name[14];
    double grade;

    void create(){
        std::cout << "Enter faculty number: ";
        std::cin.getline(facNum, 10);
        std::cout << "Enter name: ";
        std::cin.getline(name, 14);
        std::cout << "Enter average grades: ";
        std::cin >> grade;
        std::cin.ignore();
    }

     void write(std::ofstream& output){
        output << "Faculty number: " << facNum << '\n';
        output << "Name: " << name << '\n';
        output << "Average grades: " << grade << "\n\n";
    }

    void read(std::ifstream& input){
        char c;
        while(input.get(c))
            std::cout << c;
    }
};

void writeStudent(Student students[], int numOfStudents, std::ofstream& out){
    for(int i = 0; i < numOfStudents; i++){
        out << "Faculty number" << students[i].facNum << '\n';
        out << "Name: " << students[i].name << '\n';
        out << "Average grades: " << students[i].grade << '\n';
    }
}

void readStudent(Student students[], int numOfStudents, std::ifstream& in){
    for(int i = 0; i < numOfStudents; i++){
        char c;
        while(in.get(c))
            std::cout << c;
    }
}

int main(){

    Student students[3]; 
    
    for(int i = 0; i < 3; i++)
        students[i].create();
    
    std::ofstream out;
    out.open("students.txt");
    
    for(int i = 0; i < 3; i++)
        students[i].write(out);
    
    out.close();

    std::ifstream in;
    in.open("students.txt");

    std::cout << '\n';
    for(int i = 0; i < 3; i++)
        students[i].read(in);

    in.close();

    std::ofstream out1;
    out1.open("students.txt");
    writeStudent(students, 3, out1);
    out1.close();

    std::ifstream in1;
    in1.open("students.txt");
    readStudent(students, 3, in1);
    in1.close();

    return 0;
};