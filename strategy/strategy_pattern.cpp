#include <iostream>
using namespace std;

class PaymentStrategy {
    public :
     virtual void pay(int amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
    public :
     void pay(int amount) override {
         cout << "Paid " << amount << " using Credit Card." << endl;
     }
};

class PayPalPayment : public PaymentStrategy {
    public :
     void pay(int amount) override {
         cout << "Paid " << amount << " using PayPal." << endl;
     }
};

class PaymentContext {
    private: 
     PaymentStrategy * strategy ;
    public :
    PaymentContext(PaymentStrategy * strategy) {
        this->strategy = strategy;
    }
    void setPaymentStrategy(PaymentStrategy * strategy) {
        this->strategy = strategy;
    }
    void execute(int amount) {
        strategy->pay(amount);
    }
};

int main() {
    CreditCardPayment ccp;
    PayPalPayment pp;

    PaymentContext context(&ccp);
    context.execute(100);

    context.setPaymentStrategy(&pp);
    context.execute(200);

    return 0;
}