#include <iostream>
using namespace std;

class Notification {
    public: 
     virtual void sendNotification(string message) = 0;
     virtual ~Notification() {}
};

class EmailNotification : public Notification {
    public:
     void sendNotification(string message) override {
         cout << "Sending Email Notification: " << message << endl;
     }
};

class SMSNotification : public Notification {
    public:
        void sendNotification(string message) override {
            cout << "Sending SMS Notification: " << message << endl;
        }
};

class PushNotification : public Notification {
    public:
       void sendNotification (string message) override {
           cout << "Sending Push Notification: " << message << endl;
       }
};

class NotificationFactory {
    public : 
    virtual Notification *  createNotification() = 0 ;
    virtual ~NotificationFactory() {}
};

class EmailNotificationFactory : public NotificationFactory {
    public :
     Notification * createNotification() override {
         return new EmailNotification();
     }
};

class SMSNotificationFactory : public NotificationFactory {
    public :
     Notification * createNotification() override {
         return new SMSNotification();
     }
};

class PushNotificationFactory : public NotificationFactory {
    public :
     Notification * createNotification() override {
         return new PushNotification();
     }
};

int main() {
    NotificationFactory *factory;

    factory = new EmailNotificationFactory();
    Notification *email = factory->createNotification();
    email->sendNotification("Hello via Email!");
    delete email;
    delete factory;

    factory = new SMSNotificationFactory();
    Notification *sms = factory->createNotification();
    sms->sendNotification("Hello via SMS!");
    delete sms;
    delete factory;

    factory = new PushNotificationFactory();
    Notification *push = factory->createNotification();
    push->sendNotification("Hello via Push!");
    delete push;
    delete factory;

    return 0;
}