#ifndef OBJECT_H
#define OBJECT_H

namespace Obj
{
	class Knife
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		void draw();
	};

	class Mountain
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		const float speed = .5;
		void draw();
	};

	class Cloud
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		const float speed = .3;
		void draw();
	};

	class Wood
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		void draw();
	};

	class Bird
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		const float gravity = .006;
		const float lift = 1.5;
		float velocity = 0;
		void draw();
		void drop();
		void fly();
	};
}

#endif // !OBJECT_H