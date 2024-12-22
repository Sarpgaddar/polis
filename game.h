#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// الكائن الأساسي
class GameObject {
protected:
    int x, y; // الموقع
public:
    GameObject(int startX, int startY) : x(startX), y(startY) {}

    virtual void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    virtual void display() const = 0; // دالة افتراضية
};

// فئة الشرطي
class Player : public GameObject {
public:
    Player(int startX, int startY) : GameObject(startX, startY) {}

    void controlMove(char direction) {
        if (direction == 'w') move(0, -1); // لأعلى
        else if (direction == 's') move(0, 1); // لأسفل
        else if (direction == 'a') move(-1, 0); // لليسار
        else if (direction == 'd') move(1, 0); // لليمين
    }

    void display() const override {
        cout << "Player is at (" << x << ", " << y << ")" << endl;
    }
};

// فئة الحرامي
class Thief : public GameObject {
public:
    Thief(int startX, int startY) : GameObject(startX, startY) {
        srand(time(0)); // تهيئة التوليد العشوائي
    }

    void randomMove() {
        int dx = (rand() % 3) - 1; // -1, 0, 1
        int dy = (rand() % 3) - 1;
        move(dx, dy);
    }

    void display() const override {
        cout << "Thief is at (" << x << ", " << y << ")" << endl;
    }
};

// فئة اللعبة
class Game {
private:
    Player player;
    Thief thief;
    const int gridSize = 10; // حجم الشبكة

public:
    Game();
    void start();
    bool checkCollision();
};

#endif
