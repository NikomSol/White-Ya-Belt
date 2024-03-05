#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

//Task
// bool operator!= (stringstream lhs, stringstream rhs) {
//     string lhsString;
//     lhs >> lhsString;
//     string rhsString;
//     rhs >> rhsString;

//     return (lhsString == rhsString);
// }

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

map <QueryType, string> QueryTypeToString {
  {QueryType::NewBus, "NEW_BUS"}, {QueryType::BusesForStop, "BUSES_FOR_STOP"},
  {QueryType::StopsForBus, "STOPS_FOR_BUS"}, {QueryType::AllBuses, "ALL_BUSES"}
};

ostream& operator << (ostream& os, const QueryType& qt) {
  os << QueryTypeToString[qt];
  return os;
}

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
  q.bus = "";
  q.stop = "";
  q.stops = {};

  string s;
  is >> s;

  if (s == QueryTypeToString[QueryType::NewBus]) {
    q.type = QueryType::NewBus;
    is >> q.bus;
    
    int stops_count;
    is >> stops_count;

    for (int i = 0; i < stops_count; i++) {
      string stop;
      is >> stop;
      q.stops.push_back(stop);
    }

  } else if (s == QueryTypeToString[QueryType::BusesForStop]) {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (s == QueryTypeToString[QueryType::StopsForBus]) {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (s == QueryTypeToString[QueryType::AllBuses]) {
    q.type = QueryType::AllBuses;
  } else {
    throw runtime_error("Unknown comand: " + s);
  }

  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
  string stop;
  vector <string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  if (r.stop != "") {
    os << "Stop " << r.stop << ":";
    for (auto item : r.buses) {
      os << " " << item;
    }
  } else {
    os << "No stop";
  }
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
  string bus;
  vector <string> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  if (r.bus != "") {
    os << "Bus " << r.bus << ":";
    for (auto item : r.stops) {
      os << " " <<  item;
    }
  } else {
    os << "No bus";
  }
  return os;
}

struct AllBusesResponse {
  vector <StopsForBusResponse> buses;
};


ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.buses.size() == 0) {
    os << "No buses";
  } else {
    for (auto bus : r.buses) {
      os << "Bus "<< bus.bus << ":";
      for (auto item : bus.stops) {
        os << " " <<  item;
      }
      os << endl;
    }
  }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    stops_for_bus[bus] = stops; 
    for (const string& stop : stops) {
      buses_for_stop[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse r;
    if (buses_for_stop.count(stop)) {
      r.stop = stop;
      r.buses = buses_for_stop.at(stop);
    }
    return r;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse r;
    if (stops_for_bus.count(bus)) {
      r.bus = bus;
      r.stops = stops_for_bus.at(bus);
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse r;
    for (auto const& [bus, stops] : stops_for_bus) {
      r.buses.push_back(GetStopsForBus(bus));
    }
    return r;
  }

private:
  map<string, vector<string>> buses_for_stop, stops_for_bus;
};
//Testing framework

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        stringstream ss;
        ss << "Assertion failed: " << t << " != " << u << " Hint: " << hint;
        throw runtime_error(ss.str());
    }
}

void Assert(const bool& b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (runtime_error& ex) {
            ++fail_count;
            cerr << test_name << " FAIL: " << ex.what() << endl;
        }
    }

    ~TestRunner() {
        if (fail_count) {
            cerr << fail_count << " tests failed. Terminate.";
            exit(1);
        }
    }
private:
    int fail_count = 0;
};

void AssertEqualStream(stringstream& sscontrol, stringstream& ssout, const string& hint) {
    while(sscontrol && ssout) {
      string sout;
      string scontrol;
      ssout >> sout;
      sscontrol >> scontrol;
      AssertEqual(sout, scontrol, hint);
    }
}

//Tests

void TestQuertyIn () {
    {
      string s = "ALL_BUSES";
      stringstream sin(s);
      Query q;

      sin >> q;

      AssertEqual(q.type, QueryType::AllBuses, s);
    }
    {
      string s = "BUSES_FOR_STOP Marushkino";
      stringstream sin(s);
      Query q;

      sin >> q;

      AssertEqual(q.type, QueryType::BusesForStop, s);
      AssertEqual(q.stop, "Marushkino", s);
    }
    {
      string s = "STOPS_FOR_BUS 32K";
      stringstream sin(s);
      Query q;

      sin >> q;

      AssertEqual(q.type, QueryType::StopsForBus, s);
      AssertEqual(q.bus, "32K", s);
    }
    {
      string s = "NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo";
      stringstream sin(s);
      Query q;

      sin >> q;

      AssertEqual(q.type, QueryType::NewBus, s);
      AssertEqual(q.bus, "32", s);
      AssertEqual(q.stops[0], "Tolstopaltsevo", s);
      AssertEqual(q.stops[1], "Marushkino", s);
      AssertEqual(q.stops[2], "Vnukovo", s);
    }
}

void TestStopsForBusResponse () {
  {
    StopsForBusResponse r;
    r.bus = "32";
    r.stops = {"32K"};

    stringstream ssout;
    ssout << r;

    stringstream sscontrol("Bus 32: 32K");
    AssertEqualStream(ssout, sscontrol, "1");
  }
  {
    StopsForBusResponse r;

    stringstream ssout;
    ssout << r;

    stringstream sscontrol("No bus");

    AssertEqualStream(ssout, sscontrol, "2");
  }
}

void TestBusesForStopResponse () {
  {
    BusesForStopResponse r;
    r.stop = "Troparyovo";
    r.buses = {"950"};

    stringstream ssout;
    ssout << r;

    stringstream sscontrol("Stop Troparyovo: 950");

    AssertEqualStream(ssout, sscontrol, "1");
  }
  {
    BusesForStopResponse r;

    stringstream ssout;
    ssout << r;

    stringstream sscontrol("No stop");

    AssertEqualStream(ssout, sscontrol, "2");
  }
}

void TestAllBusesResponse () {
  { 
    StopsForBusResponse r1, r2;
    r1.bus = "272";
    r1.stops = {"Vnukovo", "Moskovsky"};
    r2.bus = "32";
    r2.stops = {"Tolstopaltsevo", "Marushkino"};

    AllBusesResponse r;
    r.buses = {r1, r2};

    stringstream ssout;
    ssout << r;

    stringstream sscontrol("Bus 272: Vnukovo Moskovsky\nBus 32: Tolstopaltsevo Marushkino\n");

    AssertEqualStream(ssout, sscontrol, "1");
  }
  { 
    AllBusesResponse r;

    stringstream ssout;
    ssout << r;

    stringstream sscontrol("No buses");

    AssertEqualStream(ssout, sscontrol, "2");
  }
}

void TestBusManager() {
  {
    BusManager bm;
    bm.AddBus("32", {"32K"});
    stringstream ssout, sscontrol;
    
    ssout << bm.GetStopsForBus("32");
    sscontrol << "Bus 32: 32K";
    AssertEqualStream(ssout, sscontrol, "1");

    ssout << bm.GetBusesForStop("32K");
    sscontrol << "Stop 32K: 32";
    AssertEqualStream(ssout, sscontrol, "2");

    ssout << bm.GetAllBuses();
    sscontrol << "Bus 32: 32K";
    AssertEqualStream(ssout, sscontrol, "3");
  }
}

void TestIntegral() {
  stringstream scin, sout_control, scout;
  scin << "10\n\
          ALL_BUSES\n\
          BUSES_FOR_STOP Marushkino\n\
          STOPS_FOR_BUS 32K\n\
          NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo\n\
          NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo\n\
          BUSES_FOR_STOP Vnukovo\n\
          NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo\n\
          NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo\n\
          STOPS_FOR_BUS 272\n\
          ALL_BUSES\n";

  sout_control <<  "No buses\n\
                    No stop\n\
                    No bus\n\
                    Stop Vnukovo: 32 32K\n\
                    Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo\n\
                    Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo\n\
                    Bus 32: Tolstopaltsevo Marushkino Vnukovo\n\
                    Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo\n\
                    Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo\n";

  int query_count;
  Query q;

  scin >> query_count;
  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    scin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      scout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      scout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      scout << bm.GetAllBuses() << endl;
      break;
    }
  }

  AssertEqualStream(scout, sout_control, "1");
}

void TestAll () {
    TestRunner tr;
    tr.RunTest(TestQuertyIn, "TestQuertyIn");
    tr.RunTest(TestStopsForBusResponse, "TestStopsForBusResponse");
    tr.RunTest(TestBusesForStopResponse, "TestBusesForStopResponse");
    tr.RunTest(TestAllBusesResponse, "TestAllBusesResponse");
    tr.RunTest(TestBusManager, "TestBusManager");
    tr.RunTest(TestIntegral, "TestIntegral");
}

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {

  TestAll();
  
  // int query_count;
  // Query q;

  // cin >> query_count;

  // BusManager bm;
  // for (int i = 0; i < query_count; ++i) {
  //   cin >> q;
  //   switch (q.type) {
  //   case QueryType::NewBus:
  //     bm.AddBus(q.bus, q.stops);
  //     break;
  //   case QueryType::BusesForStop:
  //     cout << bm.GetBusesForStop(q.stop) << endl;
  //     break;
  //   case QueryType::StopsForBus:
  //     cout << bm.GetStopsForBus(q.bus) << endl;
  //     break;
  //   case QueryType::AllBuses:
  //     cout << bm.GetAllBuses() << endl;
  //     break;
  //   }
  // }

  return 0;
}
