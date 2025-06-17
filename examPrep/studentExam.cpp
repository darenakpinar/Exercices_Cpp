#include <iostream>
#include <string>
#include <list>
#include <vector>

class student_pool {
public:
    student_pool();
    ~student_pool();
    void new_student(student_pool& sp);
    void add_student(int id, std::string name, unsigned int grade);
    void update_grade(int id, unsigned int new_grade);
    void print_students() const;
    void print_top_k(unsigned int k) const;
    int student_id(unsigned int pos)const;
    int student_grade(unsigned int pos)const;
    int student_name(unsigned int pos)const;

    // Accessors if you like, e.g. student_id(i), student_grade(i), student_name(i)
private:
    struct student {
        int id;
        unsigned int grade;
        std::string name;
    };
    std::vector<student> v;
};
student_pool::student_pool(){}
student_pool::~student_pool(){}

int student_pool::student_id(unsigned int pos)const{
    return v.at(pos).id;
}
int student_pool::student_grade(unsigned int pos)const{
    return v.at(pos).grade;
}
string student_pool::student_name(unsigned int pos)const{
    return v.at(pos).name;
}

void student_pool::update_grade(int id, unsigned int new_grade){
    // find the student
    int i = 0;
    while (v.at(i).id != id){
        i++
    }
    v.at(i).grade = new_grade;
    for (int i = 0; i < v.size() -1; i++){
        if (v.at(i) < v.at(i+1)){
            std::swap(v.at(i), v.at(i+1));
        }
    }
}
void student_pool::print_students()const{
    for (int i = 0; i < v.size(); i++){
        cout << "Student Detail: " << student_id(i) << student_grade(i) << student_name(i) << endl; 
    }
}
void student_pool::print_top_k(unsigned int k)const{
   k = (k > v.size())? v.size() : k;
    for (int i = 0; i< k; i++){
        cout << "Student Detail: " << student_id(i) << student_grade(i) << student_name(i) << endl; 
    }
}
void student_pool::add_student(int id, std::string name, unsigned int grade){
    unsigned int n = v.size();
    int i = 0;
    while(i < v.size() && v.at(i).grade < grade ||
     (v.at(i).grade == 0 && v.at(i).id < id)){
        i++;
     }
     student newStudent{id, grade, name};
     v.push_back(student{0, 0, ""});
     for (int j = v.size()-1; j > i; j--){
        v.at(j) = v.at(j-1);
     }
     v.at(i) = newStudent;
}

int main() {
    student_pool& sp;
    int n; std::cin >> n;
    while (n--) {
        int id, grade;
        std::string name;
        std::cin >> id >> name >> grade;
        sp.add_student(id, name, grade);
    }
    sp.print_students();
    return 0;
}