//Created by Emerson Paul P. Celestial and Joseph Cristopher C. Santos

#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <iterator>
#include "Assignments/MyParticle.h"
#include "Assignments/MyVector.h"
#include "Assignments/Utils.h"
#include "Assignments/PhysicsWorld.h"
#include "Assignments/RenderParticle.h"
#define PI 3.14159265

using namespace std::chrono_literals;
using namespace std::chrono;

//16ms = 1 frame in a 60fps
constexpr nanoseconds timestep(16ms);

//function declarations
void instantiateParticles(std::list<RenderParticle*>& RenderParticles, PhysicsWorld& pWorld,
    float mass, MyVector position, MyVector velocity, MyVector acceleration, float ranDirection, float circleRadius);
float RandomFloat(float a, float b);


int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(700, 500), "P6 Test", sf::Style::Default);

    //PhysicsWorld, Renderparticle, and Utils instance
    PhysicsWorld pWorld = PhysicsWorld();
    std::list<RenderParticle*> RenderParticles;
    Utils::offset = MyVector(0, 250);

    //clock/frame 
    using clock = high_resolution_clock;
    auto curr_time = clock::now();
    auto prev_time = curr_time;
    nanoseconds curr_ns(0ns);

    //particle effects properties
    int particleLimitSize = 25;

    sf::Event event;

    while (1) {
        curr_time = clock::now();
        auto dur = duration_cast<nanoseconds> (curr_time - prev_time);
        prev_time = curr_time;

        curr_ns += dur;
        if (curr_ns >= timestep) {

            auto ms = duration_cast<milliseconds>(curr_ns);

            //Call the update when it reaches a cetain timestep
            //ms is in milisecs while engine is using secs so we divide by 1000
            //(float)ms.count() / 1000
            if (pWorld.Particles.size() < particleLimitSize)
            {
                float ranDirection;
                ranDirection = RandomFloat(0.5f, 1.0f); //randomLifeSpan value
                instantiateParticles(RenderParticles, pWorld, 1.0f, MyVector(350, 200), 
                    MyVector(0, 0), MyVector(0, 0), ranDirection, 10.0f);
            }

            //Updates the shapes and particles
            pWorld.Update((float)ms.count() / 1000);

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
            //iterates the particles then draw
            for (std::list<RenderParticle*>::iterator i = RenderParticles.begin();
                i != RenderParticles.end(); i++)
            {
                (*i)->Draw(&window);
            }
            window.display();
        }
    }
    std::system("pause");
    return 0;
}

//instantiate a new particle
void instantiateParticles(std::list<RenderParticle*>& RenderParticles, PhysicsWorld& pWorld, 
    float mass, MyVector position, MyVector velocity, MyVector acceleration, float ranDirection, float circleRadius)
{
    MyParticle* myP = new MyParticle(mass, position, velocity, acceleration, ranDirection);
    sf::CircleShape* myS = new sf::CircleShape(circleRadius);

    int randomColor;
    randomColor = rand() % 3;
    switch (randomColor)
    {
    case 1:
        myS->setFillColor(sf::Color::Red);
        break;
    case 2:
        myS->setFillColor(sf::Color::Blue);
        break;
    case 3:
        myS->setFillColor(sf::Color::White);
        break;
    }
    //random addForce
    float randomX;
    randomX = RandomFloat(-0.3f, 0.3f);
    float randomForce;
    randomForce = RandomFloat(9000.0f, 16000.0f);
    myP->AddForce(MyVector(randomX * randomForce, 1 * randomForce));

    //add particle to the PhysicWorld
    pWorld.addParticle(myP);

    RenderParticle* myRp = new RenderParticle(myP, myS);
    RenderParticles.push_back(myRp);
}

//returns a random float between the two float values
float RandomFloat(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

