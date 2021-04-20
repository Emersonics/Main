//Created by Emerson Paul P. Celestial

#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <stddef.h>
#include "Assignments/MyParticle.h"
#include "Assignments/MyVector.h"
#include "Assignments/Utils.h"

using namespace std::chrono_literals;
using namespace std::chrono;

//16ms = 1 frame in a 60fps
constexpr nanoseconds timestep(16ms);

MyParticle& instantiateParticle(sf::Color color, int mass, MyVector velocity,
    MyVector acceleration, MyVector position, sf::CircleShape& shape);
void updateShapes(MyParticle& particle, MyVector& renderPoint, sf::CircleShape& circle, float count);
bool finishLineChecker(sf::CircleShape shape1, sf::CircleShape shape2, sf::CircleShape shape3, std::string rankings[3],
    MyParticle& particle1, MyParticle& particle2, MyParticle& particle3, float timer);
void displayStatistics(std::string rankings[3], MyParticle& particle, std::string name, int index);


int main() {
    sf::RenderWindow window(sf::VideoMode(700, 500), "P6 Test", sf::Style::Default);

    Utils::offset = MyVector(0, 250);

    //GameState
    bool allAreFinished = false;
    std::string rankings[3] = { "","","" };
    float timer = 0.0f;
    //renderPoint instance
    MyVector renderPoint1;
    MyVector renderPoint2;
    MyVector renderPoint3;
    //FinishLine instance
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(700, 3));
    line.setOrigin(line.getSize().x/2, line.getSize().y / 2);
    line.setRotation(90);
    line.setPosition(500, window.getSize().y / 2);
    //Circle Shapes instance
    sf::CircleShape shape1(10);
    sf::CircleShape shape2(10);
    sf::CircleShape shape3(10);
    //MyParticle class instance
    MyParticle Bourbon = instantiateParticle(sf::Color::White, 10, MyVector(35, 0), MyVector(8, 0), MyVector(0,-225), shape1);
    MyParticle Creek = instantiateParticle(sf::Color::Blue, 10, MyVector(26, 0), MyVector(11, 0), MyVector(0,0), shape2);
    MyParticle Scarlet = instantiateParticle(sf::Color::Red, 10, MyVector(55, 0), MyVector(3, 0), MyVector(0,225), shape3);
    //clock/frame 
    using clock = high_resolution_clock;
    auto curr_time = clock::now();
    auto prev_time = curr_time;
    nanoseconds curr_ns(0ns);

    sf::Event event;

    while (!allAreFinished) {
        curr_time = clock::now();
        auto dur = duration_cast<nanoseconds> (curr_time - prev_time);
        prev_time = curr_time;

        curr_ns += dur;
        if (curr_ns >= timestep) {
            auto ms = duration_cast<milliseconds>(curr_ns);

            //Call the update when it reaches a cetain timestep
            //ms is in milisecs while engine is using secs so we divide by 1000
            //(float)ms.count() / 1000
            timer += (float)ms.count() / 1000;
            //Updates the shapes
            updateShapes(Bourbon, renderPoint1, shape1, (float)ms.count());
            updateShapes(Creek, renderPoint2, shape2, (float)ms.count());
            updateShapes(Scarlet, renderPoint3, shape3, (float)ms.count());
            //Checks if all shapes are past the finish line
            allAreFinished = finishLineChecker(shape1, shape2, shape3, rankings,
                Bourbon, Creek, Scarlet, timer);
            if (allAreFinished)
            {
                window.close();
                displayStatistics(rankings, Bourbon, "Bourbon", 0);
                displayStatistics(rankings, Creek, "Creek", 1);
                displayStatistics(rankings, Scarlet, "Scarlet", 2);
            }

            curr_ns -= timestep;

            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }

            window.clear();
            window.draw(line);
            window.draw(shape1);
            window.draw(shape2);
            window.draw(shape3);
            window.display();
        }
    }
    system("pause");
    return 0;
}

MyParticle& instantiateParticle(sf::Color color, int mass, MyVector velocity, MyVector acceleration, 
    MyVector position, sf::CircleShape& shape)
{
    MyParticle particle = MyParticle(mass, position, velocity, acceleration);

    shape.setFillColor(color);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    MyVector renderPoint = particle.GetRenderPoint();
    shape.setPosition(renderPoint.x, renderPoint.y);

    return particle;
}

void updateShapes(MyParticle& particle, MyVector& renderPoint, sf::CircleShape& circle, float count)
{
    particle.Update(count / 1000);
    renderPoint = particle.GetRenderPoint();
    circle.setPosition(renderPoint.x, renderPoint.y);
    //for min and max setter
    if (particle.maxVelocity < particle.velocity.x)
        particle.maxVelocity = particle.velocity.x;
    if (particle.minVelocity > particle.velocity.x)
        particle.minVelocity = particle.velocity.x;
}

bool finishLineChecker(sf::CircleShape shape1, sf::CircleShape shape2, sf::CircleShape shape3, std::string rankings[3],
    MyParticle& particle1, MyParticle& particle2, MyParticle& particle3, float timer)
{
    const std::string ranksList[3] = { "1st", "2nd", "3rd" };
    static int finishers = 0;
    if (shape1.getPosition().x >= 500 && rankings[0]._Equal(""))
    {
        particle1.timeFinished = timer;
        rankings[0] = ranksList[finishers];
        ++finishers;
    }
    if (shape2.getPosition().x >= 500 && rankings[1]._Equal(""))
    {
        particle2.timeFinished = timer;
        rankings[1] = ranksList[finishers];
        ++finishers;
    }
    if (shape3.getPosition().x >= 500 && rankings[2]._Equal(""))
    {
        particle3.timeFinished = timer;
        rankings[2] = ranksList[finishers];
        ++finishers;
    }
    if (shape1.getPosition().x >= 500 && shape2.getPosition().x >= 500 && shape3.getPosition().x >= 500)
    {
        return true;
    }
    return false;
}



void displayStatistics(std::string rankings[3], MyParticle& particle, std::string name, int index)
{
    std::cout << name << " " << rankings[index] << std::endl;
    printf("Mag. of velocity at finish line %0.2f m/s\n", particle.velocity.getMagnitude());
    printf("Ave. Velocity in the last 500m (%0.2f,%0.2f) m/s\n", (particle.maxVelocity + particle.minVelocity)/2, 0);
    printf("%0.2fsecs\n\n", particle.timeFinished);
}

