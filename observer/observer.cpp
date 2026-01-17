#include <iostream>
#include <set>
#include <string>
using namespace std;

class ISubscribers
{
public:
    virtual void update(string videoName) = 0;
    virtual string getName() = 0;
};

class IPublisher
{
public:
    virtual void subscribe(ISubscribers *observer) = 0;
    virtual void unsubscribe(ISubscribers *observer) = 0;
    virtual void notify(string videoName) = 0;
};

class Publisher : public IPublisher
{
private:
    string name;
    set<ISubscribers *> subcribers;

public:
    Publisher(string name) {
        this->name = name;
    }

    void subscribe(ISubscribers *observer) override
    {
        subcribers.insert(observer);
        cout << observer->getName() << " subscribed to " << name << endl;
    }

    void unsubscribe(ISubscribers *observer) override
    {
        subcribers.erase(observer);
        cout << observer->getName() << " unsubscribed from " << name << endl;
    }

    void notify(string videoName) override
    {
        for (auto it : subcribers)
        {
            it->update(videoName);
        }
    }
    void uploadVideo(string videoName)
    {

        notify(videoName);
    }
};

class Subscriber : public ISubscribers
{
private:
    string name;
    Publisher *publisher;

public:
    Subscriber(string name, Publisher *publisher) : name(name), publisher(publisher)
    {
        publisher->subscribe(this);
    }
    
    string getName() override {
        return name;
    }

    void update(string videoName) override
    {
        cout << "Hey " << name << ", new video uploaded: " << videoName << endl;
    }
};

int main()
{
    Publisher *publisher = new Publisher("Tech Channel");

    Subscriber *subscriber1 = new Subscriber("Alice", publisher);
    Subscriber *subscriber2 = new Subscriber("Bob", publisher);

    publisher->uploadVideo("Design Patterns in C++");

    publisher->unsubscribe(subscriber1);

    publisher->uploadVideo("Observer Pattern in C++");

    delete subscriber1;
    delete subscriber2;
    delete publisher;

    return 0;
}
