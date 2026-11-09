#include <iostream>
using namespace std;

#include "GameField.h"
#include "GameFieldIterator.h"
#include "Factories.h"

#include <ctime>
#include <cstdlib>
#include <utility>

#include <vector>
#include <string>

void clear() {
    system("cls");
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr)));

    AssaultFactory assaultFactory;
    DefenseFactory defenseFactory;
    SupportFactory supportFactory;


    int choice;

    while (true) {

        cout << "1. Битва Soldier против Heavy\n";
        cout << "2. Soldier и Pyro против Heavy\n";
        cout << "3. Heavy против Soldier (ответная атака)\n";
        cout << "4. Перемещение юнитов и сражение\n";

        cout << "0. Выход\n";
    

        cin >> choice;
        switch (choice) {
        
        case 0: {
            return 0;
        }
        case 1: {
            clear();
            cout << "Soldier против Heavy\n";
            GameField battleField(3, 3);

            vector<string> soldier = { "Soldier" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(defenseFactory, heavy);

            cout << "Игровое поле:\n";
            battleField.printField();

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* heavyUnit = battleField.getUnit(1);

            cout << "\nДо атаки:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nSoldier атакует Heavy\n";

            soldierUnit->attackUnit(*heavyUnit);

            cout << "\nПосле атаки:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();

        }
        case 2: {
            clear();
            cout << "Soldier и Pyro против Heavy\n";
            GameField battleField(3, 3);

            vector<string> assaultUnits = { "Soldier", "Pyro" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, assaultUnits);
            battleField.fill(defenseFactory, heavy);

            cout << "Игровое поле:\n";
            battleField.printField();

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* pyroUnit = battleField.getUnit(1);
            Unit* heavyUnit = battleField.getUnit(2);

            cout << "\nДо атаки:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nSoldier атакует Heavy\n";
            soldierUnit->attackUnit(*heavyUnit);

            cout << "\nПосле атаки Soldier:\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nPyro атакует Heavy\n";
            pyroUnit->attackUnit(*heavyUnit);

            cout << "\nПосле атаки Pyro:\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 3: {
            clear();
            cout << "Heavy против Soldier (ответная атака)\n";
            GameField battleField(3, 3);

            vector<string> soldier = { "Soldier" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(defenseFactory, heavy);

            cout << "Игровое поле:\n";
            battleField.printField();

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* heavyUnit = battleField.getUnit(1);

            cout << "\nДо атаки:\n";
            cout << "Soldier\n";
            cout << "Здоровье: " << soldierUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << soldierUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nHeavy атакует Soldier\n";
            heavyUnit->attackUnit(*soldierUnit);

            cout << "\nПосле атаки Heavy:\n";
            cout << "Soldier\n";
            cout << "Здоровье: " << soldierUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << soldierUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nSoldier атакует Heavy\n";
            soldierUnit->attackUnit(*heavyUnit);

            cout << "\nПосле ответной атаки Soldier:\n";
            cout << "Heavy\n";
            cout << "Здоровье: " << heavyUnit->getHealth().getCurrentHealth() << "\n";
            cout << "Броня: " << heavyUnit->getArmor().getCurrentArmor() << "\n";

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }
        case 4: {
            clear();
            cout << "Перемещение юнитов и сражение\n";

            GameField battleField(3, 3);

            vector<string> soldier = { "Soldier" };
            vector<string> heavy = { "Heavy" };

            battleField.fill(assaultFactory, soldier);
            battleField.fill(defenseFactory, heavy);

            Unit* soldierUnit = battleField.getUnit(0);
            Unit* heavyUnit = battleField.getUnit(1);

            cout << "Начальное расположение:\n";
            battleField.printField();

            soldierUnit->move(1, 0);
            heavyUnit->move(0, 1);

            cout << "\nПосле перемещения:\n";
            battleField.printField();

            cout << "\nДо атаки:\n";
            cout << "Soldier health: " << soldierUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy health: " << heavyUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy armor: " << heavyUnit->getArmor().getCurrentArmor() << '\n';

            soldierUnit->attackUnit(*heavyUnit);

            cout << "\nПосле атаки Soldier:\n";
            cout << "Soldier health: " << soldierUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy health: " << heavyUnit->getHealth().getCurrentHealth() << '\n';
            cout << "Heavy armor: " << heavyUnit->getArmor().getCurrentArmor() << '\n';

            cout << "\nВыход - Enter";
            cin.ignore();
            cin.get();
            clear();
            break;
        }

        }
    }

    return 0;
}