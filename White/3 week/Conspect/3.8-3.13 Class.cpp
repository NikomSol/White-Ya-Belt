#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Route {
    public:
        Route() {
            source = "Ufa";
            destination = "Moscow";
            UpdateLength();
        }

        Route(const string& new_source, const string& new_destination) {
            source = new_source;
            destination = new_destination;
            UpdateLength();
        }

        ~Route() {
            for (const string& s : compute_distance_log) {
                cout << s << endl;
            }
        }

        string GetSourse () const {return source;}

        string GetDestination () const {return destination;}

        int GetLength () const {return length;}

        void SetSourse (const string& new_sourse) {
            source = new_sourse;
            UpdateLength();
        }

        void SetDestination (const string& new_destination) {
            destination = new_destination;
            UpdateLength();
        }

    private:
        void UpdateLength() {
            length = destination.length() - source.length();
            compute_distance_log.push_back(
                source + " - " + destination);
        }

        string source;
        string destination;
        int length;
        vector<string> compute_distance_log;
};

void PrintRoute(const Route& route) {
    // Из метода принимающего константную ссылку можно вызвать
    // Только константные методы
    cout << "From " << route.GetSourse() 
    << " To " << route.GetDestination() 
    << " Length Is " << route.GetLength() << endl;
}

int main () {
    // Пока не было конструктора

    // Route route1;
    // route1.SetSourse("Ufa");
    // route.SetDestination("Moscow");
    // PrintRoute(route1);
    
    // Появился конструктор
    // Route route2("Ufa", "Yakutsk");
    PrintRoute({"Ufa", "Yakutsk"});

    // Появился конструктор по умолчанию
    // Route route3;
    PrintRoute({});

    vector<Route> routes;
    routes.push_back({"Ufa", "Novosibirsk"});

    for (const Route& route : routes) {
        PrintRoute(route);
    }

    Route route4;
    route4.SetSourse("Lol");
    route4.SetDestination("Kek");

    return 0;
    //Диструкция происходит при выходе за пределы области видимости
}