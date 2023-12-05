#include <string>
using namespace std;

struct Specialization {
    string specialization;

    explicit Specialization (const string& str) {
        specialization = str;
    }
};

struct Course {
    string course;

    explicit Course (const string& str) {
        course = str;
    }
};

struct Week {
    string week;

    explicit Week (const string& str) {
        week = str;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle (const Specialization& specialization_, const Course& course_, const Week& week_) {
        specialization = specialization_.specialization;
        course = course_.course;
        week = week_.week;
    }
};


int main () {

    LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th"));

    // LectureTitle title("C++", "White belt", "4th");

    // LectureTitle title = {"C++", "White belt", "4th"};

    // LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

    // LectureTitle title(
    //     Course("White belt"),
    //     Specialization("C++"),
    //     Week("4th")
    // );

    // LectureTitle title(
    //     Specialization("C++"),
    //     Week("4th"),
    //     Course("White belt")
    // );

    return 0;
}