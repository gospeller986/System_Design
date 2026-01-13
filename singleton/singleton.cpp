#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    Singleton()
    {
        cout << "Singleton Instance Created" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2 ? "Both are same instance" : "Different instances") << endl;

    return 0;
}