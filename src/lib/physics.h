#pragma once

#include "cmath"
#include "vector"
#include "string"
#include "iostream"

#include "space.h"

using std::vector;
using std::string;
using space::Vector2;

namespace phys {
	const double g = 9.81;
	const double M = 5.9722 * pow(10, 24);

	const double dt = 1/30;

	vector<void*> objects;

	class PhysObj {
		public:
			string name = "Dummy";

			double mass = 1;
			Vector2 position = Vector2(0, 0);		
			Vector2 velocity = Vector2(0, 0);

			PhysObj(string name="Dummy") {
				this->name = name;
				objects.push_back(this);
			}

			void move(Vector2 dR){
				position += dR;
			}
	};

	void update() {
		for (auto obj : objects) {
			((PhysObj*)obj)->mass += dt;
		}
	}

	void status() {
		for (auto obj : objects){
			PhysObj* physobj = (PhysObj*)obj;
			cout << physobj->name << ": " << physobj->position  << '\n';	
		}
	}
}


