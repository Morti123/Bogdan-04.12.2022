#include <SFML/Graphics.hpp>
#include <ctime>
#include"settings.h"
using namespace sf;
int main()
{
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(w_width, w_height), w_title);
    srand(time(nullptr));
    window.setFramerateLimit(60);
    RectangleShape leftBat,rightBat;
    leftBat.setSize(Vector2f(x, y));
    leftBat.setFillColor(LEFT_BAT_COLOR);
    leftBat.setPosition(rize, (w_height -y)/2);
    rightBat.setSize(Vector2f(x,y));
    rightBat.setFillColor(RIGHT_BAT_COLOR);
    rightBat.setPosition(w_width-rize-x, (w_height - y)/2);
    CircleShape circle;
    circle.setRadius(r);
    circle.setFillColor(Circle_Color);
    circle.setPosition((w_width - 2 * r) / 2, (w_height - 2 * r) / 2);
    float speed_x = 2.f;
    float speed_y = 3.f;
    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }
        // обновленике объектов игры
        window.clear(Color::Blue);
        circle.move(speed_x, speed_y);
        if (circle.getPosition().x <= 0 || circle.getPosition().x +2 * r >= w_width) {
            speed_x = -speed_x;
        }
        if (circle.getPosition().y <= 0 || circle.getPosition().y +2 * r >= w_height) {
            speed_y = -speed_y;
        }
        // Отрисовка окна 
        window.draw(leftBat);
        window.draw(rightBat);
        window.draw(circle);
        window.display();
    }

    return 0;
}