#include <iostream>
using namespace std;

class ICharacter {
    public:
    virtual string getAbilities() = 0;
    virtual ~ICharacter() {};
};

class Mario : public ICharacter {
    public:
    string getAbilities() override {
        return  "I am Mario .";
    }
};

class IDecorator : public ICharacter {
    protected :
      ICharacter * character;
    public:
      IDecorator(ICharacter* character) {
        this->character = character;
      }    
};

class HeightUpDecorator : public IDecorator {
    public:
      HeightUpDecorator(ICharacter* character) : IDecorator(character) {}

      string getAbilities() override {
          return character->getAbilities() + " Now my has Height increased!";
      }
};

class GunPowerDecorator : public IDecorator {
    public:
      GunPowerDecorator(ICharacter* character) : IDecorator(character) {}

      string getAbilities() override {
          return character->getAbilities() + " Now my Gun power increased!";
      }
};

int main() {
    ICharacter* mario = new Mario();
    ICharacter* tallMario = new HeightUpDecorator(mario);
    ICharacter* strongMario = new GunPowerDecorator(tallMario);

    cout << strongMario->getAbilities() << endl;

    delete mario;
    delete tallMario;
    delete strongMario;

    return 0 ; 
}


