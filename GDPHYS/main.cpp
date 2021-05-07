//Created by Emerson Paul P. Celestial

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
#include "Assignments/DragForceGenerator.h"
#include "Assignments/Springs/AnchoredSpring.h"
#include "Assignments/Springs/ParticleSpring.h"
#include "Assignments/Springs/BungeeSpring.h"
#include "Assignments/Collision/ParticleContact.h"
#include "Assignments/Collision/ContactResolver.h"
#include "Assignments/Links/Rod.h"
#define PI 3.14159265

using namespace std::chrono_literals;
using namespace std::chrono;

//16ms = 1 frame in a 60fps
constexpr nanoseconds timestep(16ms);

//function declarations
void instantiateParticles(std::list<RenderParticle*>& RenderParticles, PhysicsWorld& pWorld,
    float mass, MyVector position, MyVector velocity, MyVector acceleration, float lifeSpan, DragForceGenerator& df,
    vector <MyParticle*>& particleList, vector <sf::CircleShape*>& shapeList,
    Rod& r, ParticleContact& contact);
float RandomFloat(float a, float b);


int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1080, 720), "P6 Test", sf::Style::Default);

    //PhysicsWorld, Renderparticle, and Utils instance
    PhysicsWorld pWorld = PhysicsWorld();
    std::list<RenderParticle*> RenderParticles;
    Utils::offset = MyVector(0, 0);
    DragForceGenerator df = DragForceGenerator(0,0); //setted to zero(0); kinetic friction
    Rod r = Rod();
    /*r->particles[0] = &particle1;
    r->particles[1] = &particle2;
    r->length = 100;
    pWorld.Links.push_back(r);*/

    ParticleContact contact = ParticleContact();
    vector <MyParticle*> particleList;
    vector <sf::CircleShape*> shapeList;

    /*
    * //for particles
    particle1.velocity = MyVector(-10, 0);
    particle2.velocity = MyVector(10, 0);
    particle1.dampening = 1;
    particle2.dampening = 1;

    ParticleContact contact = ParticleContact();
    contact.particles[0] = &particle1;
    contact.particles[1] = &particle2;
    contact.collisionNormal = particle1.position - particle2.position;
    contact.collisionNormal.Normalize();
    contact.restitution = 1;

    //for wall
    particle1.velocity = MyVector(-50, 0);
    contact.particles[1] = NULL;
    contact.collisionNormal = MyVector(1,0); //bounce back to the right
    */

    /*float lifeSpan;
        lifeSpan = RandomFloat(100.0f, 100.0f); //randomLifeSpan value*/
    AnchoredSpring aSpring = AnchoredSpring(MyVector(100, 200), 5, 0.5);
    AnchoredSpring aSpring1 = AnchoredSpring(MyVector(200, 200), 5, 0.5);
    AnchoredSpring aSpring2 = AnchoredSpring(MyVector(300, 200), 5, 0.5);
    AnchoredSpring aSpring3 = AnchoredSpring(MyVector(400, 200), 5, 0.5);
    AnchoredSpring aSpring4 = AnchoredSpring(MyVector(500, 200), 5, 0.5);
    BungeeSpring bSpring1 = BungeeSpring(MyVector(100, 200), 10.0f, 5.0f);
    BungeeSpring bSpring2 = BungeeSpring(MyVector(200, 200), 10.0f, 5.0f);

    /*instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(150, 0),
        MyVector(-30, 0), MyVector(0, 0), 100.0f, 50.0f, df, aSpring, bSpring, particleList);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(50, 0),
        MyVector(30, 0), MyVector(0, 0), 100.0f, 50.0f, df, aSpring, bSpring, particleList);*/


    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(100, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(200, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(300, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(400, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(500, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);
    sf::VertexArray line1(sf::Lines, 2);
    line1[0].position = sf::Vector2f(100, 0);
    line1[0].color = sf::Color::White;

    sf::VertexArray line2(sf::Lines, 2);
    line2[0].position = sf::Vector2f(200, 0);
    line2[0].color = sf::Color::White;

    sf::VertexArray line3(sf::Lines, 2);
    line3[0].position = sf::Vector2f(300, 0);
    line3[0].color = sf::Color::White;

    sf::VertexArray line4(sf::Lines, 2);
    line4[0].position = sf::Vector2f(400, 0);
    line4[0].color = sf::Color::White;

    sf::VertexArray line5(sf::Lines, 2);
    line5[0].position = sf::Vector2f(500, 0);
    line5[0].color = sf::Color::White;

    /*instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(245, 20),
        MyVector(-30, 5), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);
    instantiateParticles(RenderParticles, pWorld, 1.5f, MyVector(160, -30),
        MyVector(100, 5), MyVector(0, 0), 100, df, particleList, shapeList, r, contact);*/

    /*contact.collisionNormal = contact.particles[0]->position - contact.particles[1]->position;
    contact.collisionNormal.Normalize();
    contact.restitution = 0.6f;*/

    /*MyVector dir = particleList[0]->position - particleList[1]->position;
    dir.Normalize();*/

    //pWorld.AddContact(particleList[0], particleList[1], 1, dir, );
    r.length = 20;
    //pWorld.Links.push_back(&r);

    //realistic spring between two balls
    /*ParticleSpring* pS1 = new ParticleSpring(particleList[0], 5, 1);
    pWorld.forceRegistry.Add(particleList[1], pS1);    //adds the ParticleSpring; this should be a connection to another particle
    ParticleSpring* pS2 = new ParticleSpring(particleList[1], 5, 1);
    pWorld.forceRegistry.Add(particleList[0], pS2);    //adds the ParticleSpring; this should be a connection to another particle*/

    //pWorld.forceRegistry.Add(myP, &df);    //adds the friction
    pWorld.forceRegistry.Add(particleList[0], &aSpring);    //adds the spring
    pWorld.forceRegistry.Add(particleList[1], &aSpring1);    //adds the spring
    pWorld.forceRegistry.Add(particleList[2], &aSpring2);    //adds the spring
    pWorld.forceRegistry.Add(particleList[3], &aSpring3);    //adds the spring
    pWorld.forceRegistry.Add(particleList[4], &aSpring4);    //adds the spring
    //pWorld.forceRegistry.Add(particleList[0], &bSpring1);    //adds the spring
    //pWorld.forceRegistry.Add(particleList[1], &bSpring2);    //adds the spring
    //pWorld.forceRegistry.Add(myP, &bSpring);    //adds the spring


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


            //Updates the shapes and particles
            pWorld.Update((float)ms.count() / 1000);
            line1[1].position = sf::Vector2f(particleList[0]->position.x, particleList[0]->position.y);
            line1[1].color = sf::Color::White;
            line2[1].position = sf::Vector2f(particleList[1]->position.x, particleList[1]->position.y);
            line2[1].color = sf::Color::White;
            line3[1].position = sf::Vector2f(particleList[2]->position.x, particleList[2]->position.y);
            line3[1].color = sf::Color::White;
            line4[1].position = sf::Vector2f(particleList[3]->position.x, particleList[3]->position.y);
            line4[1].color = sf::Color::White;
            line5[1].position = sf::Vector2f(particleList[4]->position.x, particleList[4]->position.y);
            line5[1].color = sf::Color::White;
            //contact.Resolve((float)ms.count() / 1000); //Contact ResolutionTesting
            /*cout << "V of a: " << particleList[0]->position.x << "," << particleList[0]->position.y << endl;
            cout << "V of b: " << particleList[1]->position.x << "," << particleList[1]->position.y << endl;*/

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
            window.draw(line1);
            window.draw(line2);
            window.draw(line3);
            window.draw(line4);
            window.draw(line5);
            window.display();
        }
    }
    std::system("pause");
    return 0;
}

//instantiate a new particle
void instantiateParticles(std::list<RenderParticle*>& RenderParticles, PhysicsWorld& pWorld,
    float mass, MyVector position, MyVector velocity, MyVector acceleration, float lifeSpan, DragForceGenerator& df,
    vector <MyParticle*>& particleList, vector <sf::CircleShape*>& shapeList,
    Rod& r, ParticleContact& contact)
{
    MyParticle* myP = new MyParticle(mass, position, velocity, acceleration, lifeSpan);
    //add particle to the PhysicWorld
    pWorld.addParticle(myP);
    sf::CircleShape* myS = new sf::CircleShape(myP->radius);
    /*sf::CircleShape* myS = new sf::CircleShape(myP->radius);*/

    //random addForce
    /*float randomX;
    randomX = RandomFloat(-0.3f, 0.3f);
    float randomForce;
    randomForce = RandomFloat(9000.0f, 16000.0f);
    myP->AddForce(MyVector(0, -1 * randomForce));*/

    static int particleIndex = 0;

    myS->setFillColor(sf::Color::White);
    myS->setOrigin(myS->getRadius(), myS->getRadius());

    RenderParticle* myRp = new RenderParticle(myP, myS);
    RenderParticles.push_back(myRp);

    myP->dampening = 1;
    contact.particles[particleIndex] = myP;
    particleList.push_back(myP);
    shapeList.push_back(myS);
    r.particles[particleIndex] = myP;

    /*//for particles
    myP->dampening = 1;*/

    particleIndex++;
    /*
    //for wall
    particle1.velocity = MyVector(-50, 0);
    contact.particles[1] = NULL;
    contact.collisionNormal = MyVector(1,0); //bounce back to the right
    */
}

//returns a random float between the two float values
float RandomFloat(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

