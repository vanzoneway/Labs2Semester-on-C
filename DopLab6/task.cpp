#include "task.h"

Vector2f operator+(Vector2f a, Vector2f b){
    Vector2f temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    return temp;
}

Vector2f operator-(Vector2f a, Vector2f b){
    Vector2f temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    return temp;
}

Vector2f operator*(Vector2f a, Vector2f b){
    Vector2f temp;
    temp.x = a.x * b.x;
    temp.y = a.y * b.y;
    return temp;
}

Vector2f operator/(Vector2f a, Vector2f b){
    Vector2f temp;
    temp.x = a.x / b.x;
    temp.y = a.y / b.y;
    return temp;
}

Vector2f operator+=(Vector2f a, Vector2f b){
    Vector2f temp;
    a.x += b.x;
    a.y += b.y;
    temp.x = a.x;
    temp.y = a.y;
    return temp;
}

Vector2f operator-=(Vector2f a, Vector2f b){
    Vector2f temp;
    a.x -= b.x;
    a.y -= b.y;
    temp.x = a.x;
    temp.y = a.y;
    return temp;
}

Vector2f operator*=(Vector2f a, Vector2f b){
    Vector2f temp;
    a.x *= b.x;
    a.y *= b.y;
    temp.x = a.x;
    temp.y = a.y;
    return temp;
}

Vector2f operator/=(Vector2f a, Vector2f b){
    Vector2f temp;
    a.x /= b.x;
    a.y /= b.y;
    temp.x = a.x;
    temp.y = a.y;
    return temp;
}

void print(Vector2f a){
    cout<<'('<<a.x<<','<<a.y<<')';
}

void task1(){
    Vector2f a(6,4), b(3,1);
    cout << "a + b = ";
    print(a+b);
    cout << endl << "a - b = ";
    print(a - b);
    cout << endl << "a * b = ";
    print(a * b);
    cout << endl << "a / b = ";
    print(a / b);
    cout << endl << "a += b = ";
    print(a += b);
    cout << endl << "a -= b = ";
    print(a -= b);
    cout << endl << "a *= b = ";
    print(a *= b);
    cout << endl << "a /= b = ";
    print(a /= b);
}
