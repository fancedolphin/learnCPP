#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

class FidgetSpinner {
public:
    string colour;uint8_t size;
    FidgetSpinner(const char *_colour);
    ~FidgetSpinner();
    void spin(int strength);
    void tick();
    void stop(); // Add this method to stop the spinner

protected:
    
    uint16_t spins;
    float velocity;
    float angle;
};

FidgetSpinner::FidgetSpinner(const char *_colour) :
    colour(_colour), size(5), spins(0), velocity(0), angle(0)
{
    cout << "Created a " << colour << " FidgetSpinner." << endl;
}

FidgetSpinner::~FidgetSpinner() {
    cout << "Destroyed a " << colour << " FidgetSpinner." << endl;
}

void FidgetSpinner::spin(int strength) {
    velocity += strength;
    cout << "A " << colour << " spinner has spun " << spins << " time(s)." << endl;
}

void FidgetSpinner::tick() {
    angle += velocity;
    while (angle > 10) {
        angle -= 10;
        spins++;
    }

    velocity -= size;
    if (velocity <= 0) {
        velocity = 0;
        cout << "The spinner has stopped. It stopped at angle " << angle << "." << endl;
    }
}

void FidgetSpinner::stop() { // Add this method to stop the spinner
    velocity = 0;
    cout << "The spinner has been stopped." << endl;
}

int main() {
    FidgetSpinner v("Value Veridian");
    v.spin(10);
    v.tick();
    v.tick();
    v.tick();
    v.tick();
    v.tick();
    v.stop(); // Stop the spinner after all ticks

    FidgetSpinner *r = new FidgetSpinner("Reference Red");
    r->size = 3;
    r->spin(10);
    for (int i = 0; i < 5; i++) {
        r->tick();
    }
    r->stop(); // Stop the spinner after all ticks
    delete r;

    return 0;
}


