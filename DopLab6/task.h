//
// Created by PC on 21.04.2023.
//

#ifndef DOPLAB6_TASK_H
#define DOPLAB6_TASK_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vector2f{
    float x, y;
public:
    Vector2f(float first = 0, float second = 0){
        x = first;
        y = second;
    }

    Vector2f friend operator+(Vector2f a, Vector2f b);
    Vector2f friend operator-(Vector2f a, Vector2f b);
    Vector2f friend operator*(Vector2f a, Vector2f b);
    Vector2f friend operator/(Vector2f a, Vector2f b);
    Vector2f friend operator+=(Vector2f a, Vector2f b);
    Vector2f friend operator-=(Vector2f a, Vector2f b);
    Vector2f friend operator*=(Vector2f a, Vector2f b);
    Vector2f friend operator/=(Vector2f a, Vector2f b);
    void friend print(Vector2f a);
};

void task1();
#endif //DOPLAB6_TASK_H
