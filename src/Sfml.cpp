#include "../include/Sfml.hpp"

SFML::SFML(double i_size)
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();

    this->window.create(sf::VideoMode(SCREEN_WIDTH * i_size, SCREEN_HEIGHT * i_size), "Triangle Fractal Point Distribution");
    this->window.setFramerateLimit(60);
    this->window.setPosition(sf::Vector2i((videoMode.width - (SCREEN_WIDTH * i_size)) / 2, (videoMode.height - (SCREEN_HEIGHT * i_size)) / 2));
}

SFML::~SFML()
{
    this->window.close();
}

void SFML::analyseEvent()
{
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->window.close();
            exit(0);
        }
    }
}

void SFML::display(Triangle &i_triangle, int counter)
{
    this->window.clear();
    this->drawTriangle(i_triangle.getPoints());

    sf::CircleShape circle(1);
    circle.setFillColor(sf::Color::White);

    int i = 0;

    sf::Text text;

    sf::Font font;
    font.loadFromFile("asset/font.ttf");
    
    text.setFont(font);
    text.setString("Points: " + std::to_string(counter));
    text.setCharacterSize(22);
    text.setLetterSpacing(1);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    for (auto &point : i_triangle.getPointsVector()) {

        circle.setScale(1, 1);
        circle.setFillColor(point.color);
        circle.setPosition(point.x, point.y);
        this->window.draw(circle);
        this->window.draw(text);
        i = 1;
    }

    this->window.display();
}
void SFML::drawTriangle(std::array<Point, 3> i_points)
{
    sf::Vertex AB[] = 
    {
        sf::Vertex(sf::Vector2f(i_points[0].x, i_points[0].y)),
        sf::Vertex(sf::Vector2f(i_points[1].x, i_points[1].y))
    };

    sf::Vertex BC[] = 
    {
        sf::Vertex(sf::Vector2f(i_points[1].x, i_points[1].y)),
        sf::Vertex(sf::Vector2f(i_points[2].x, i_points[2].y))
    };

    sf::Vertex CA[] = 
    {
        sf::Vertex(sf::Vector2f(i_points[2].x, i_points[2].y)),
        sf::Vertex(sf::Vector2f(i_points[0].x, i_points[0].y))
    };

    this->window.draw(AB, 2, sf::Lines);
    this->window.draw(BC, 2, sf::Lines);
    this->window.draw(CA, 2, sf::Lines);
}
