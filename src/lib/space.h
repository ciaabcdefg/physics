#pragma once

#include "iostream"

using std::ostream;

namespace space {
	template<class T>
		double dot(T v1, T v2) {
			return v1.x * v2.x + v1.y * v2.y;
		}

	class Vector2 {
		public:
			double x = 0;
			double y = 0;
			
			Vector2(double x, double y) {
				this->x = x;
				this->y = y;
			}
		
			Vector2 operator - () {
				Vector2 v = Vector2(-x, -y);
				return v;
			}

			Vector2 operator + (Vector2 const& other) {
				Vector2 v = Vector2(x + other.x, y + other.y);
				return v;
			}	
			
			Vector2 operator - (Vector2 const& other) {
				Vector2 v = Vector2(x - other.x, y - other.y);
				return v;
			}

			Vector2 operator += (Vector2 const& other) {
				x += other.x;
				y += other.y;
				return *this;
			}
			
			Vector2 operator -= (Vector2 const& other) {
				x -= other.x;
				y -= other.y;
				return *this;
			}
			
			double operator * (Vector2 const& other) {
				return dot(*this, other);
			}

			Vector2 operator * (double const& a) {
				Vector2 v = Vector2(a * x, a * y);
				return v;
			}

			friend ostream& operator << (ostream& os, const Vector2& v);
	};

	ostream& operator << (ostream& os, const Vector2& v) {
		os << '(' << v.x << ", " << v.y << ')';
		return os;
	}

	Vector2 operator * (const double a, const Vector2& other) {
		Vector2 v = Vector2(a * other.x, a * other.y);
		return v;
	}
}


