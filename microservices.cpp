#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Employee {
public:
    int id;
    string name;

    Employee(int id, const string& name) : id(id), name(name) {}
};

class AttendanceService {
private:
    map<int, bool> attendanceData;

public:
    void markAttendance(int employeeId, bool isPresent) {
        attendanceData[employeeId] = isPresent;
    }

    bool getAttendanceStatus(int employeeId) {
        if (attendanceData.find(employeeId) != attendanceData.end()) {
            return attendanceData[employeeId];
        }
        return false; // Default: absent
    }
};

int main() {
    
    Employee emp1(1, "Usman");
 
    // Create the AttendanceService instance
    AttendanceService attendanceService;

    // Mark attendance for an employee (employeeId, isPresent)
    attendanceService.markAttendance(emp1.id, true); // Mark John Doe as present

    // Get attendance status for an employee
    bool isPresent = attendanceService.getAttendanceStatus(emp1.id);
    if (isPresent) {
        cout << emp1.name << " present today." << endl;
    } else {
        cout << emp1.name << " absent today." << endl;
    }

    return 0;
}
