#include <iostream>

class Apple {
public:
    static Apple* getInstance() {
        if (instance == nullptr) 
        {
            instance = new Apple();
        }
        return instance;
    }
    void SetNutritionalValue(int value) {
        NutritionalValue = value;  
    }

    void SetTimeToRiot(int time) {
        timeToRiot = time;
    }

    int GetNutritionalValue() {
        return NutritionalValue;
    }

    int GetTimeToRiot() {
        return timeToRiot;
    }

private:
    int NutritionalValue;
    int timeToRiot;

    Apple() : NutritionalValue(100), timeToRiot(10) {
        std::cout << "Apple created\n";
    }

    static Apple* instance;

    Apple(const Apple&) = delete;
    Apple& operator=(const Apple&) = delete;
};

Apple* Apple::instance = nullptr;

int main()
{
    setlocale(LC_ALL, "ru");
    
    Apple* apple1 = Apple::getInstance();
    std::cout << "NutritionalValue" << apple1->GetNutritionalValue() << std::endl;
    std::cout << "TimeToRiot" << apple1->GetTimeToRiot() << std::endl;
    //Меняем значения полей
    apple1->SetNutritionalValue(90);
    apple1->SetTimeToRiot(5);

    //Получаем экземпляр класса и проверяем, что значения полей совпадают
    Apple* apple2 = Apple::getInstance();

    std::cout << "NutritionalValue" << apple2->GetNutritionalValue() << std::endl;
    std::cout << "TimeToRiot" << apple2->GetTimeToRiot() << std::endl;


    return 0;
}

