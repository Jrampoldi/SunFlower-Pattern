#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>



int main()
{
    int n = 1;
    int c = 8;
    double angle;
    double radius;
    double x = 0;
    double y = 0;

    int windowWidth = 1500;
    int windowHeight = 1500;

    int red;
    int blue;
    int green;

    sf::CircleShape circles[10000];
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sunflower Pattern");
    while (window.isOpen())
    {
        window.setFramerateLimit(120);
        //formulas
        angle = n * 137.5;
        radius = c * sqrt(n);
        x = (double)((radius * cos(angle)) + (windowWidth / 2));
        y = (double)((radius * sin(angle)) + (windowHeight / 2));

        red = (int)radius % 256;
        blue = (int)angle % 256;
        green = (int)(x) % 256;
        
        sf::Color color(red, blue, green);
        circles[n] = sf::CircleShape(5, 5);
        circles[n].setPosition(x, y);
        circles[n].setFillColor(color);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (int i = 0; i < n; i++)
        {
            window.draw(circles[i]);
        }


        window.display();
        if (n <= 9998)
            n++;
        
    }
    return 0;
}