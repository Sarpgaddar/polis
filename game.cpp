#include "game.h"

// بناء اللعبة
Game::Game() : player(0, 0), thief(5, 5) {}

// تشغيل اللعبة
void Game::start() {
    char move;
    while (true) {
        system("clear"); // تنظيف الشاشة
        player.display();
        thief.display();

        if (checkCollision()) {
            cout << "The police caught the thief! Game Over." << endl;
            break;
        }

        cout << "Enter move (w/a/s/d): ";
        cin >> move;
        player.controlMove(move);

        // تحديث الحرامي
        thief.randomMove();
    }
}

// التحقق من الاصطدام بين الشرطي والحرامي
bool Game::checkCollision() {
    return player.getX() == thief.getX() && player.getY() == thief.getY();
}
