#include <iostream>

class Surprise {
    private:
        void SayIt(double x) {}
    public:
        void SayIt(int x) {}
};

int main() {
    Surprise srpr;
    srpr.SayIt(1.0); // access violation
    return 0;
}
