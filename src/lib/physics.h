#pragma once

#include "cmath"
#include "vector"
#include "unordered_map"
#include "string"
#include "iostream"

#include "space.h"

using std::vector;
using std::string;
using std::unordered_map;

using space::Vector2;

namespace phys {
	const double g = 9.81;
	const double M = 5.9722 * pow(10, 24);

	const double dt = 1/30;

	unordered_map<string, void*> objects;

	class PhysObj {
		public:
			string name = "Dummy";

			double mass = 1;
			Vector2 position = Vector2(0, 0);		
			Vector2 velocity = Vector2(0, 0);

			PhysObj(string name="Dummy") {
				this->name = name;
				objects.insert({name, this});
			}

			void move(Vector2 dR){
				position += dR;
			}
	};

	void update() {
		for (auto obj : objects) {
			PhysObj* physObj = (PhysObj*)(obj.second);
			physObj->position += physObj->velocity;
		}
	}

	void status() {
		for (auto obj : objects){
			PhysObj* physobj = (PhysObj*)(obj.second);
			cout << physobj->name << ": " << physobj->position  << '\n';	
		}
	}
}


