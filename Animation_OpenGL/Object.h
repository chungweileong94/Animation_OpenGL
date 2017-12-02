#ifndef OBJECT_H
#define OBJECT_H

namespace Obj
{
	class Knife
	{
	public:
		float scale = 1;
		float rotation = 1;
		float x = 0, y = 0;
		float speed = 1;


		void draw();
		void reset(float xPos, float maxHeight);
		void moveLeft();
		float getScaledHeight();

	private:
		const float width = 81, height = 243;
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
		float x = 0, y = 0;
		float velocity = 0;
		float angle = 0;
		
		void draw();
		void drawDevGuideLine();
		void drop();
		void fly();
		float getScaledRadius();

	private:
		const float width = 230, height = 392;
		const float gravity = .006;
		const float lift = 1.5;
	};

	class Chatbox
	{
	public:
		float scale = 1;
		float x = 0, y = 0;

		void draw();
	};

	class Tear
	{
	public:
		float scale = 1;
		float x = 0, y = 0;

		void draw();
	};

	class Cage
	{
	public:
		float scale = 1;
		float x = 0, y = 0;

		void draw();
	};

	class Hunter
	{
	public:
		float scale = 1;
		float x = 0, y = 0;

		void draw();
	};
}

#endif // !OBJECT_H