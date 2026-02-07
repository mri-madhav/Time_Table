#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> days={"Mon","Tue","Wed","Thu", "Fri"};

    vector<string> timings = {
        "8-8:50",
        "9-9:50",
        "10-10:50",
        "11-11:50",
        "12-12:50(L)",
        "1-1:50",
        "2-5",
        "5-6",
        "6-8"
    };
    map<string, vector<string>> timetable;

    // Monday slots
    timetable["Mon"] = {
        "A", "B", "C", "D", "LUNCH", "G", "P", "J/J3", ""
    };

    // Tuesday
    timetable["Tue"] = {
        "B", "C", "D", "E", "LUNCH", "A", "Q", "F", ""
    };

    // Wednesday
    timetable["Wed"] = {
        "C", "D", "E", "F", "LUNCH", "B", "R", "G", ""
    };

    // Thursday
    timetable["Thu"] = {
        "E", "F", "G", "A", "LUNCH", "D", "S", "H", ""
    };

    // Friday
    timetable["Fri"] = {
        "F", "G", "A", "B", "LUNCH", "C", "T", "E", ""
    };
    set<string> slots;
    for(auto day: days){
        for(auto s: timetable[day]){
            if(s!="LUNCH"&&s!=""){
                slots.insert(s);
            }
        }
    }
    map<string,string> slottosub;
    string subject;
    cout<<"Enter Subject for  each slot"<<"\n";
    for(auto &s: slots){
        cout<<"Subject in slot "<< s <<": "<<"\n";
        getline(cin >> ws, subject);   
        slottosub[s] = subject;
    }
    cout<<"\n";
    cout<<"Final Timetable"<<"\n";
    cout << left << setw(6) << "Day";
    for (auto &t : timings)
        cout << left << setw(16) << t;
    cout << endl;
    cout << string(6 + 16* timings.size(), '-') << "\n";

    // Print timetable
    for(auto day: days){
        cout<<left<<setw(6)<<day;
        for(auto slot: timetable[day]){
            if(slot=="LUNCH"){
                cout<<left<<setw(16)<<"LUNCH";
            }
            else if(slot==""){
                cout<<left<<setw(16)<<"";
            }
            else{
    cout << left << setw(16) << slottosub[slot];
}

        }
        cout<<"\n";
    }

    return 0;
}