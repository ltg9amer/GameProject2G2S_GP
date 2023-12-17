#include "pch.h"
#include "FVector2.h"

FVector2::FVector2() : X(0.0f), Y(0.0f) {

}

FVector2::FVector2(const FVector2& Vector2) : X(Vector2.X), Y(Vector2.Y) {

}

FVector2::FVector2(POINT Point) : X((float)Point.x), Y((float)Point.y) {

}

FVector2::FVector2(int X, int Y) : X((float)X), Y((float)Y) {

}

FVector2::FVector2(long X, long Y) : X((float)X), Y((float)Y) {

}

FVector2::FVector2(float X, float Y) : X(X), Y(Y) {

}

FVector2::~FVector2() {

}
