//Student : Nguyen Van
//ID: 24110146
//Object : Build a simple system to manage different types of vehicles in a transportation company.
//Use OOP concepts in C++ to design and implement the system.
//Using LLMs to assist in code generation and problem-solving (Chat GPT).
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
/*
Reflection:

In this assignment, I applied object-oriented programming (OOP) concepts in C++ to design and implement a simple vehicle management system. I started by analyzing the real-world requirement: the transportation company needs to manage different types of vehicles. From this, I identified the main entity, which is a Vehicle class, and defined its essential attributes such as type, maximum speed, color, and fuel type. I also identified the behaviors, including accelerating and displaying information.

One challenge I faced was ensuring the program could handle invalid inputs, for example when the user enters a negative value for speed. To solve this, I added input validation logic in both the constructor and setter methods. Another challenge was making the code easy to extend in case more attributes or methods are needed. I addressed this by following good OOP practices: encapsulation with private attributes, public getter and setter methods, and meaningful method names using CamelCase.

Using OOP concepts helped me clearly separate the data (attributes) and behavior (methods) of the Vehicle entity. It also made the code reusable: I could easily create multiple objects such as Car, Truck, and Motorcycle without duplicating logic. The structure allows future extensions, for example adding subclasses or new features.

Overall, this assignment reinforced my understanding of how to translate a real-world requirement into a C++ class, create objects, and use methods to represent actions. It showed me the strength of OOP in making programs modular, reusable, and easier to maintain.
*/
