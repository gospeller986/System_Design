#include <iostream>
using namespace std ;


class Button {
    public :
        virtual void render() = 0 ;
        virtual ~Button() {}
};

class TextField {
    public :
        virtual void render() = 0 ;
        virtual ~TextField() {}
};


class DarkButton : public Button {
    public :
        void render() override {
            cout << "Rendering Dark Button" << endl;
        }
};

class DarkTextField : public TextField {
    public :
        void render() override {
            cout << "Rendering Dark TextField" << endl;
        }
};

class LightButton : public Button {
    public :
        void render() override {
            cout << "Rendering Light Button" << endl;
        }
};

class LightTextField : public TextField {
    public :
        void render() override {
            cout << "Rendering Light TextField" << endl;
        }
};

class ThemeFactory {
    public :
        virtual unique_ptr<Button> createButton() = 0;
        virtual unique_ptr<TextField> createTextField() = 0;
        virtual ~ThemeFactory() {}
};

class DarkThemeFactory : public ThemeFactory {
    public :
     unique_ptr<Button> createButton() override {
        return make_unique<DarkButton>();
     }

     unique_ptr<TextField> createTextField() override {
        return make_unique<DarkTextField>();
     }
};

class LightThemeFactory : public ThemeFactory {
    public :
     unique_ptr<Button> createButton() override {
        return make_unique<LightButton>();
     }

     unique_ptr<TextField> createTextField() override {
        return make_unique<LightTextField>();
     }
};

int main() {
    unique_ptr<ThemeFactory> darkTheme = make_unique<DarkThemeFactory>();
    unique_ptr<Button> darkButton = darkTheme->createButton();
    unique_ptr<TextField> darkTextField = darkTheme->createTextField();

    darkButton->render();
    darkTextField->render();

    unique_ptr<ThemeFactory> lightTheme = make_unique<LightThemeFactory>();
    unique_ptr<Button> lightButton = lightTheme->createButton();
    unique_ptr<TextField> lightTextField = lightTheme->createTextField();

    lightButton->render();
    lightTextField->render();

    return 0;
}