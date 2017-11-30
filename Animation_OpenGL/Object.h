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
		float speed = .3;
		int color[3] = { 255, 220, 31 };

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
		float angle = 0;
		float x = 0, y = 0;
		float velocity = 0;
		const float gravity = .006;
		const float lift = 1.5;
		const float width = 230, height = 392;

		void draw();
		void drop();
		void fly();
	};

	class BoomWord
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
	};
}

#endif // !OBJECT_H