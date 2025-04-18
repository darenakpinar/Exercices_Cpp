#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::vector<int> grades;
    int input;

    std::cout<< "Enter the grades: (-1 to stop) " << std::endl;
    while (std::cin>> input && input != -1){
        grades.push_back(input);
    }
    if (grades.empty()){
        std::cout << "No grades entered!\n";
        return 0;
    }

    int sum = 0, maxGrade = grades[0], minGrade = grades[0];
    for (int grade : grades){
        sum += grade;
        maxGrade = std::max(maxGrade, grade);
        minGrade = std::min(minGrade, grade);
    }
    double avg = static_cast<double>(sum) / grades.size();

    std::sort(grades.begin(), grades.end());

    std::cout << "\nResult: \n";
    std::cout << "Avarage grade: " << avg << std::endl;
    std::cout << "Maximum grade: " << maxGrade << " Minimum Grade: " << minGrade << std::endl;
    std::cout << "Sorted Grades: " ;
    for(int grade : grades) std::cout << grade << " ";
    std::cout << std::endl;

    return 0;

}