#pragma once

#include <cmath>
#include <iostream>

// #region [rgba(100, 255, 100, 0.05)] Vector2

class Vector2 {
  private:
    double x;
    double y;

  public:
    // constructors
    Vector2();
    Vector2(double x, double y);

    // destructors
    ~Vector2();

    // utils
    double norm();
    Vector2 normalized();

    // operators
    Vector2 operator+(const Vector2 &other);
    Vector2 operator-(const Vector2 &other);
    double operator*(const Vector2 &other);
    Vector2 operator*(const double other);
    Vector2 operator/(const double other);

    Vector2 operator+=(const Vector2 &other);
    Vector2 operator-=(const Vector2 &other);
    double operator*=(const Vector2 &other);
    Vector2 operator*=(const double other);
    Vector2 operator/=(const double other);

    // getters
    double getX();
    double getY();

    // setters
    void setX(double x);
    void setY(double y);
};

// #endregion

// #region [rgba(255, 100, 100, 0.05)] Particle

class Particle {
  private:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    unsigned short int type;

  public:
    // contructors
    Particle();
    Particle(Vector2 position, Vector2 velocity, Vector2 acceleration,
             unsigned short int type);

    // getters
    Vector2 getPosition();
    Vector2 getVelocity();
    Vector2 getAcceleration();
    unsigned short int getType();

    // setters
    void setPosition(Vector2 &position);
    void setVelocity(Vector2 &velocity);
    void setAcceleration(Vector2 &acceleration);
    void setType(unsigned short int type);

    // char encode[]() {

    // }
};

// #endregion
