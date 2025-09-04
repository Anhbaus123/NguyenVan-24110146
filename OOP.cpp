#include <iostream>
#include <string>

using namespace std;

class Vehicle 
{
    private:
    string type;
    int maxSpeed;
    string typeFuel;
    string color;
    public:
    Vehicle(string t, int s, string a, string f)
    {
        type = t;
        maxSpeed = s;
        color = a;
        typeFuel = f;
        if (s>0)
        {
            maxSpeed = s;
        }
        else 
        {
            cout << "Warning: Invalid speed. Set to 0" <<endl;
            maxSpeed = 0;
        }
    }
    void setType(string t) { type =t; }
    void setMaxspeed(int s)
    { 
        if (s > 0)
        {
        maxSpeed = s;
        }
        else 
        {
            cout << "Max speed must be positive." << endl;
            maxSpeed = 0;
        }

    }
    void setColor(string a) { color = a; }
    void setTypeFuel(string f) { typeFuel = f; }
    string getType() { return type; }
    int getMaxspeed() { return maxSpeed; }
    string getColor() { return color; }
    string getTypeFuel() { return typeFuel; }
    void accelerate ()
    {
        cout << "The " << type << " is accelerating to " <<maxSpeed << " km/h." << endl;
    }
    void displayInfo()
    {
        cout <<"Type: "<< type<<endl;
        cout <<"Max Speed: "<< maxSpeed<<endl;
        cout <<"Color: "<< color << endl;
        cout <<"Type of Fuel: " << typeFuel << endl;
    }
};

int main ()
{
    Vehicle car("Car", 180, "Blue", "Gasoline");
    Vehicle truck("Truck", 150, "Red", "Diesel");
    Vehicle motorcycle("Motorcycle", 200, "Black", "Gasoline");
    car.displayInfo(); car.accelerate();
    truck.displayInfo(); truck.accelerate();
    motorcycle.displayInfo(); motorcycle.accelerate();
    string type,color,typeFuel;
    int maxSpeed;
    cout << "\nEnter a new vehicle details:\n";
    cout << "Type: "; cin >> type;
    cout << "Max Speed: "; cin >> maxSpeed;
    cout << "Color: "; cin >> color;
    cout << "Type of Fuel: "; cin >> typeFuel;
    Vehicle newVehicle(type, maxSpeed, color, typeFuel);
    newVehicle.displayInfo(); newVehicle.accelerate();


    return 0;
}