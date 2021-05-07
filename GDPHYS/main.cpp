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
    vector <MyParticle*>& particleList, vector <sf::CircleShape*>& shapeList, ParticleContact& contact);
float RandomFloat(float a, float b);


int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1080, 720), "P6 Test", sf::Style::Default);

    //PhysicsWorld, Renderparticle, and Utils instance
    PhysicsWorld pWorld = PhysicsWorld();
    std::list<RenderParticle*> RenderParticles;
    Utils::offset = MyVector(0, 0);
    DragForceGenerator df = DragForceGenerator(0,0); //setted to zero(0); kinetic friction
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
    AnchoredSpring aSpring1 = AnchoredSpring(MyVector(100, 200), 5, 0.5);
    AnchoredSpring aSpring2 = AnchoredSpring(MyVector(200, 200), 5, 0.5);
    AnchoredSpring aSpring3 = AnchoredSpring(MyVector(300, 200), 5, 0.5);
    AnchoredSpring aSpring4 = AnchoredSpring(MyVector(400, 200), 5, 0.5);
    AnchoredSpring aSpring5 = AnchoredSpring(MyVector(500, 200), 5, 0.5);
    AnchoredSpring aSpring6 = AnchoredSpring(MyVector(600, 200), 5, 0.5);
    
    /*BungeeSpring bSpring1 = BungeeSpring(MyVector(100, 200), 10.0f, 5.0f);
    BungeeSpring bSpring2 = BungeeSpring(MyVector(200, 200), 10.0f, 5.0f);*/

    //for rods connections
    Rod r1 = Rod();
    Rod r2 = Rod();
    Rod r3 = Rod();
    Rod r4 = Rod();
    Rod r5 = Rod();
    Rod r6 = Rod();

    //for anchors
    MyParticle* anchor1 = new MyParticle(1.0f, MyVector(100, 200), MyVector(0, 0), MyVector(0, 0), 100, true);
    pWorld.addParticle(anchor1);
    sf::CircleShape* anchorS1 = new sf::CircleShape(anchor1->radius);
    anchorS1->setFillColor(sf::Color::Red);
    anchorS1->setOrigin(anchorS1->getRadius(), anchorS1->getRadius());
    RenderParticle* anchorRp1 = new RenderParticle(anchor1, anchorS1);
    RenderParticles.push_back(anchorRp1);

    MyParticle* anchor2 = new MyParticle(1.0f, MyVector(200, 200), MyVector(0, 0), MyVector(0, 0), 100, true);
    pWorld.addParticle(anchor2);
    sf::CircleShape* anchorS2 = new sf::CircleShape(anchor2->radius);
    anchorS2->setFillColor(sf::Color::Red);
    anchorS2->setOrigin(anchorS2->getRadius(), anchorS2->getRadius());
    RenderParticle* anchorRp2 = new RenderParticle(anchor2, anchorS2);
    RenderParticles.push_back(anchorRp2);

    MyParticle* anchor3 = new MyParticle(1.0f, MyVector(300, 200), MyVector(0, 0), MyVector(0, 0), 100, true);
    pWorld.addParticle(anchor3);
    sf::CircleShape* anchorS3 = new sf::CircleShape(anchor3->radius);
    anchorS3->setFillColor(sf::Color::Red);
    anchorS3->setOrigin(anchorS3->getRadius(), anchorS3->getRadius());
    RenderParticle* anchorRp3 = new RenderParticle(anchor3, anchorS3);
    RenderParticles.push_back(anchorRp3);

    MyParticle* anchor4 = new MyParticle(1.0f, MyVector(400, 200), MyVector(0, 0), MyVector(0, 0), 100, true);
    pWorld.addParticle(anchor4);
    sf::CircleShape* anchorS4 = new sf::CircleShape(anchor4->radius);
    anchorS4->setFillColor(sf::Color::Red);
    anchorS4->setOrigin(anchorS4->getRadius(), anchorS4->getRadius());
    RenderParticle* anchorRp4 = new RenderParticle(anchor4, anchorS4);
    RenderParticles.push_back(anchorRp4);

    MyParticle* anchor5 = new MyParticle(1.0f, MyVector(500, 200), MyVector(0, 0), MyVector(0, 0), 100, true);
    pWorld.addParticle(anchor5);
    sf::CircleShape* anchorS5 = new sf::CircleShape(anchor5->radius);
    anchorS5->setFillColor(sf::Color::Red);
    anchorS5->setOrigin(anchorS5->getRadius(), anchorS5->getRadius());
    RenderParticle* anchorRp5 = new RenderParticle(anchor5, anchorS5);
    RenderParticles.push_back(anchorRp5);

    MyParticle* anchor6 = new MyParticle(1.0f, MyVector(600, 200), MyVector(0, 0), MyVector(0, 0), 100, true);
    pWorld.addParticle(anchor6);
    sf::CircleShape* anchorS6 = new sf::CircleShape(anchor6->radius);
    anchorS6->setFillColor(sf::Color::Red);
    anchorS6->setOrigin(anchorS6->getRadius(), anchorS6->getRadius());
    RenderParticle* anchorRp6 = new RenderParticle(anchor6, anchorS6);
    RenderParticles.push_back(anchorRp6);

    //for the balls
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(100, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(200, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(300, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(400, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(500, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, contact);
    instantiateParticles(RenderParticles, pWorld, 5.0f, MyVector(600, 200),
        MyVector(0, 100), MyVector(0, 0), 100, df, particleList, shapeList, contact);

    //anchor and balls connections
    r1.particles[0] = anchor1;
    r1.particles[1] = particleList[0];
    r2.particles[0] = anchor2;
    r2.particles[1] = particleList[1];
    r3.particles[0] = anchor3;
    r3.particles[1] = particleList[2];
    r4.particles[0] = anchor4;
    r4.particles[1] = particleList[3];
    r5.particles[0] = anchor5;
    r5.particles[1] = particleList[4];
    r6.particles[0] = anchor6;
    r6.particles[1] = particleList[5];

    //sets the settings for rods
    r1.length = 200;
    pWorld.Links.push_back(&r1);
    r2.length = 200;
    pWorld.Links.push_back(&r2);
    r3.length = 200;
    pWorld.Links.push_back(&r3);
    r4.length = 200;
    pWorld.Links.push_back(&r4);
    r5.length = 200;
    pWorld.Links.push_back(&r5);
    r6.length = 200;
    pWorld.Links.push_back(&r6);

    //line/cable representation
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

    sf::VertexArray line6(sf::Lines, 2);
    line6[0].position = sf::Vector2f(600, 0);
    line6[0].color = sf::Color::White;

    /*contact.collisionNormal = contact.particles[0]->position - contact.particles[1]->position;
    contact.collisionNormal.Normalize();
    contact.restitution = 0.6f;*/

    /*MyVector dir = particleList[0]->position - particleList[1]->position;
    dir.Normalize();*/

    //pWorld.AddContact(particleList[0], particleList[1], 1, dir, );

    //realistic spring between two balls
    /*ParticleSpring* pS1 = new ParticleSpring(particleList[0], 5, 1);
    pWorld.forceRegistry.Add(particleList[1], pS1);    //adds the ParticleSpring; this should be a connection to another particle
    ParticleSpring* pS2 = new ParticleSpring(particleList[1], 5, 1);
    pWorld.forceRegistry.Add(particleList[0], pS2);    //adds the ParticleSpring; this should be a connection to another particle*/

    //pWorld.forceRegistry.Add(myP, &df);    //adds the friction
    pWorld.forceRegistry.Add(particleList[0], &aSpring1);    //adds the spring
    pWorld.forceRegistry.Add(particleList[1], &aSpring2);    //adds the spring
    pWorld.forceRegistry.Add(particleList[2], &aSpring3);    //adds the spring
    pWorld.forceRegistry.Add(particleList[3], &aSpring4);    //adds the spring
    pWorld.forceRegistry.Add(particleList[4], &aSpring5);    //adds the spring
    pWorld.forceRegistry.Add(particleList[5], &aSpring6);    //adds the spring
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
            line2[1].position = sf::Vector2f(particleList[1]->position.x, particleList[1]->position.y);
            line3[1].position = sf::Vector2f(particleList[2]->position.x, particleList[2]->position.y);
            line4[1].position = sf::Vector2f(particleList[3]->position.x, particleList[3]->position.y);
            line5[1].position = sf::Vector2f(particleList[4]->position.x, particleList[4]->position.y);
            line6[1].position = sf::Vector2f(particleList[5]->position.x, particleList[5]->position.y);
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
            std::cout << particleList.size() << endl;
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
            window.draw(line6);
            window.display();
        }
    }
    std::system("pause");
    return 0;
}

//instantiate a new particle
void instantiateParticles(std::list<RenderParticle*>& RenderParticles, PhysicsWorld& pWorld,
    float mass, MyVector position, MyVector velocity, MyVector acceleration, float lifeSpan, DragForceGenerator& df,
    vector <MyParticle*>& particleList, vector <sf::CircleShape*>& shapeList, ParticleContact& contact)
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

    contact.particles[particleIndex] = myP;
    particleList.push_back(myP);
    shapeList.push_back(myS);

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

