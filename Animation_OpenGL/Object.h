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
		void draw();
	};

	class Cloud
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
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
		void draw();
	};
}

#endif // !OBJECT_H