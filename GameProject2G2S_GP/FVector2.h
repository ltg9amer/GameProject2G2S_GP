#pragma once
#include<assert.h>

class FVector2 {
public:
	float X;
	float Y;

public:
	FVector2();

	FVector2(const FVector2& Vector2);

	FVector2(POINT Point);

	FVector2(int X, int Y);

	FVector2(long X, long _Y);

	FVector2(float X, float Y);

	~FVector2();

	FVector2 operator + (const FVector2& Other) {
		return FVector2(X + Other.X, Y + Other.Y);
	}

	FVector2 operator - (const FVector2& Other) {
		return FVector2(X - Other.X, Y - Other.Y);
	}

	FVector2 operator * (const FVector2& Other) {
		return FVector2(X * Other.X, Y * Other.Y);
	}

	FVector2 operator / (const FVector2& Other) {
		assert(!(0.0f == Other.X || 0.0f == Other.Y));

		return FVector2(X / Other.X, Y / Other.Y);
	}

	FVector2 operator * (const int& Multiflier) {
		return FVector2(X * (float)Multiflier, Y * (float)Multiflier);
	}

	FVector2 operator * (const long& Multiflier) {
		return FVector2(X * (float)Multiflier, Y * (float)Multiflier);
	}

	FVector2 operator * (const float& Multiflier) {
		return FVector2(X * Multiflier, Y * Multiflier);
	}

	FVector2& Normalize() {
		float Length = GetLength();

		assert(Length != 0.0f);

		X /= Length;
		Y /= Length;

		return *this;
	}

	float GetLength() {
		return float(sqrt(pow(X, 2) + pow(Y, 2)));
	}
};

