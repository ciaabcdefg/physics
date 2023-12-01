#pragma once

#include "iostream"

using std::ostream;

namespace space {
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

			friend ostream& operator << (ostream& os, const Vector2& v);
	};

	ostream& operator << (ostream& os, const Vector2& v) {
		os << '(' << v.x << ", " << v.y << ')';
		return os;
	}
}


