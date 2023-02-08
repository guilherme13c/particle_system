#include "particles.hpp"

// #region [rgba(100,100,100,0.2)] Vector2

// cosntructors
Vector2::Vector2() {
    x = 0.0;
    y = 0.0;
}

Vector2::Vector2(double x, double y) {
    this->x = x;
    this->y = y;
}

// destructors
Vector2::~Vector2() {
    x = 0;
    y = 0;
}

// utils
double Vector2::norm() { return sqrt(x * x + y * y); }
Vector2 Vector2::normalized() {
    int magnitude = norm();
    return (*this) / magnitude;
}

// operators
Vector2 Vector2::operator+(const Vector2 &other) {
    return Vector2(x + other.x, y + other.y);
}
Vector2 Vector2::operator-(const Vector2 &other) {
    return Vector2(x - other.x, y - other.y);
}
// returns the dot product of the vectors
double Vector2::operator*(const Vector2 &other) {
    return (x * other.x) + (y * other.y);
}
Vector2 Vector2::operator*(const double a) { return Vector2(x * a, y * a); }
Vector2 Vector2::operator/(const double a) { return Vector2(x / a, y / a); }

// instant operators
Vector2 Vector2::operator+=(const Vector2 &other) { return (*this) + other; }
Vector2 Vector2::operator-=(const Vector2 &other) { return (*this) - other; }
double Vector2::operator*=(const Vector2 &other) { return (*this) * other; }
Vector2 Vector2::operator*=(const double a) { return (*this) * a; }
Vector2 Vector2::operator/=(const double a) { return (*this) / a; }

// getters
double Vector2::getX() { return x; }
double Vector2::getY() { return y; }

// setters
void Vector2::setX(double x) { this->x = x; }
void Vector2::setY(double y) { this->y = y; }

// #endregion

// #region [rgba(0, 200, 100, 0.05)] Particles

// constructors
Particle::Particle() {
    acceleration = Vector2();
    velocity = Vector2();
    position = Vector2();
    type = 0;
}

Particle::Particle(Vector2 position, Vector2 velocity,
                   Vector2 acceleration,
                   unsigned short int type) {
    this->acceleration = acceleration;
    this->position = position;
    this->velocity = velocity;
    this->type = type;
}

// getters
Vector2 Particle::getPosition() { return position; }
Vector2 Particle::getVelocity() { return velocity; }
Vector2 Particle::getAcceleration() { return acceleration; }
unsigned short Particle::getType() { return type; }

// setters
void Particle::setPosition(Vector2 &position) { this->position = position; }
void Particle::setVelocity(Vector2 &velocity) { this->velocity = velocity; }
void Particle::setAcceleration(Vector2 &acc) { this->acceleration = acc; }
void Particle::setType(unsigned short int type) { this->type = type; }

// #endregion
