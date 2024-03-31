#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>

typedef struct Point {
    double x;
    double y;
    sf::Color color;

    Point(double i_x, double i_y, sf::Color i_color) : x(i_x), y(i_y), color(i_color)
    {
    }

    Point(double i_x, double i_y) : x(i_x), y(i_y), color(sf::Color::White)
    {
    }

    Point(const Point &p, sf::Color i_color) : x(p.x), y(p.y), color(i_color)
    {
    }

    Point(sf::Color i_color): x(0), y(0), color(i_color)
    {
    }

    Point operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
        return *this;
    }
} Point;

// point A = (200, 25
// point B = (12.36, 350)
// point C = (387.64 , 137.5)

class Triangle
{
public:
    Triangle(int ac, char **av);
    ~Triangle() = default;

    void generateRandomPoint();
    Point calcNewPoint(Point A, Point B);
    int pickRandomPoint();

    void addNewPoint();

    Point getM() { return M; };
    std::array<Point, 3> getPoints() { return points; };
    std::vector<Point> getPointsVector() { return points_vector; };
    int getPointNumber() { return point_number; };
    double getTimer() { return timer; };
    double getSize() { return size; };

private:
    std::array<Point, 3> points = {Point(200, 25, sf::Color::White), Point(12.36, 350, sf::Color::White), Point(387.64, 350, sf::Color::White)};
    Point M = Point(0, 0);

    std::vector<Point> points_vector;

    int point_number = 500;
    double timer = 50.0f;
    double size = 1.0f;
};