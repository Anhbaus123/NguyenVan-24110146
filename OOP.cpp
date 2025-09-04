#include <iostream>
#include <string>
using namespace std;

// Lớp Vehicle mô tả một thực thể "phương tiện" trong đời thực
// với các thuộc tính (type, maxSpeed, color, typeFuel) và hành vi (accelerate, displayInfo).
class Vehicle {
private:
    // Thuộc tính (Attributes) - mô tả đặc điểm của phương tiện
    string type;      // Loại phương tiện (Car, Truck, Motorcycle...)
    int maxSpeed;     // Tốc độ tối đa (km/h)
    string typeFuel;  // Loại nhiên liệu (Gasoline, Diesel...)
    string color;     // Màu sắc

public:
    // Constructor: Khởi tạo đối tượng Vehicle với giá trị ban đầu
    Vehicle(string t, int s, string a, string f) {
        type = t;
        color = a;
        typeFuel = f;
        if (s > 0) { // Kiểm tra tốc độ hợp lệ
            maxSpeed = s;
        } else {
            cout << "Warning: Invalid speed. Set to 0" << endl;
            maxSpeed = 0;
        }
    }

    // Setter methods (thay đổi giá trị thuộc tính sau khi khởi tạo)
    void setType(string t) { type = t; }
    void setMaxSpeed(int s) {
        if (s > 0) maxSpeed = s;
        else {
            cout << "Max speed must be positive." << endl;
            maxSpeed = 0;
        }
    }
    void setColor(string a) { color = a; }
    void setTypeFuel(string f) { typeFuel = f; }

    // Getter methods (truy xuất giá trị thuộc tính)
    string getType() { return type; }
    int getMaxSpeed() { return maxSpeed; }
    string getColor() { return color; }
    string getTypeFuel() { return typeFuel; }

    // Hành vi (Behavior): phương tiện có thể tăng tốc
    void accelerate() {
        cout << "The " << type << " is accelerating to " 
             << maxSpeed << " km/h." << endl;
    }

    // Hành vi: hiển thị toàn bộ thông tin phương tiện
    void displayInfo() {
        cout << "Type: " << type << endl;
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
        cout << "Color: " << color << endl;
        cout << "Type of Fuel: " << typeFuel << endl;
    }
};

int main() {
    // Tạo 3 đối tượng phương tiện (Car, Truck, Motorcycle)
    Vehicle car("Car", 180, "Blue", "Gasoline");
    Vehicle truck("Truck", 150, "Red", "Diesel");
    Vehicle motorcycle("Motorcycle", 200, "Black", "Gasoline");

    // Hiển thị thông tin và tăng tốc
    car.displayInfo(); car.accelerate();
    truck.displayInfo(); truck.accelerate();
    motorcycle.displayInfo(); motorcycle.accelerate();

    // Nhập dữ liệu từ người dùng để tạo một phương tiện mới
    string type, color, typeFuel;
    int maxSpeed;

    cout << "\nEnter a new vehicle details:\n";
    cout << "Type: "; cin >> type;
    cout << "Max Speed: "; cin >> maxSpeed;
    // Kiểm tra nhập tốc độ hợp lệ
    while (maxSpeed < 0) {
        cout << "Invalid speed. Enter again: ";
        cin >> maxSpeed;
    }
    cout << "Color: "; cin >> color;
    cout << "Type of Fuel: "; cin >> typeFuel;

    // Tạo đối tượng Vehicle mới từ input
    Vehicle newVehicle(type, maxSpeed, color, typeFuel);
    newVehicle.displayInfo();
    newVehicle.accelerate();

    return 0;
}
