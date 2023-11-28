#include <string>
#include <iostream>

using namespace std;


struct LectureTitle
{
    string name = "c++";
    string autor = "NK";
};

void PrintLectureTitle(const LectureTitle& lecture_title) {
    cout << lecture_title.name << " by " << lecture_title.autor << endl;
}

LectureTitle GetLecture() {
    return {"adfas", "NK"};
}

struct Lecture
{
    LectureTitle lecture_title;
    int duration;
};



int main() {
    Lecture lecture1 = {{"123", "NK"}, 10};
    PrintLectureTitle(lecture1.lecture_title);

    Lecture lecture2;
    lecture2.duration = 10;
    lecture2.lecture_title.autor = "NK";
    lecture2.lecture_title.name = "kwa";
    PrintLectureTitle(lecture2.lecture_title);

    PrintLectureTitle(GetLecture());
    PrintLectureTitle({});

}
