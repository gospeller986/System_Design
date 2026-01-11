#include <iostream>
using namespace std;

class RoutingStrategy {
    public:
    virtual void findRoute(float startX, float startY, float endX, float endY) = 0;
};

class CarRoute : public RoutingStrategy {
    public:
    void findRoute(float startX, float startY, float endX, float endY) override {
        cout << "Finding car route from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")." << endl;
    }
};

class BikeRoute : public RoutingStrategy {
    public:
    void findRoute(float startX, float startY, float endX, float endY) override {
        cout << "Finding bike route from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")." << endl;
    }
};

class WalkingRoute : public RoutingStrategy {
    public:
    void findRoute(float startX, float startY, float endX, float endY) override {
        cout << "Finding walking route from (" << startX << ", " << startY << ") to (" << endX << ", " << endY << ")." << endl;
    }
};

class RouteContext {
   private:
   RoutingStrategy * strategy;
   public: 
   RouteContext(RoutingStrategy* strategy) {
       this->strategy = strategy;
   }
   void setRoutingStrategy(RoutingStrategy* strategy) {
       this->strategy = strategy;
   }

   void executeRoute(float startX, float startY, float endX, float endY) {
       strategy->findRoute(startX, startY, endX, endY);
   }
};

int main() {
    CarRoute carRoute;
    BikeRoute bikeRoute;
    WalkingRoute walkingRoute;

    RouteContext context(&carRoute);
    context.executeRoute(0, 0, 10, 10);

    context.setRoutingStrategy(&bikeRoute);
    context.executeRoute(0, 0, 5, 5);

    context.setRoutingStrategy(&walkingRoute);
    context.executeRoute(0, 0, 2, 2);

    return 0;
}