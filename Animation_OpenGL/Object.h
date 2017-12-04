#ifndef OBJECT_H
#define OBJECT_H

namespace Obj
{
	class Knife
	{
	public:
		float scale = 1;
		float angle = 1;
		float x = 0, y = 0;
		float speed = 1;

		void draw();
		void reset(float xPos, float maxHeight);
		void moveLeft(float speed);
		void fall();
		float getScaledHeight();
		float getScaledWidth();

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
		void moveleft();
	};

	class Cloud
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		float speed = .3;
		int color[3] = { 255, 220, 31 };

		void draw();
		void moveleft();
	};

	class Bird
	{
	public:
		float scale = 1;
		float x = 0, y = 0;
		float velocity = 0;
		float angle = 0;
		float speed = 0;

		void draw();
		void drawDevGuideLine();
		void drop();
		void fly();
		void fall();
		void moveRight(float speed);
		float getScaledRadius();

	private:
		const float width = 230, height = 392;
		const float gravity = .006;
		const float lift = 1.5;
		bool step = false;
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
		void drop(float speed);
	};

	class Cage
	{
	public:
		float scale = 1;
		float x = 0, y = 0;

		void draw();
		void moveRight(float speed);
	};

	class Hunter
	{
	public:
		float scale = 1;
		float x = 0, y = 0;

		void draw();
		void moveRight(float speed);

	private:
		bool step = false;
		float angle = 0;
	};

	class LoadingCover
	{
	public:
		LoadingCover(float width, float height);
		void draw();
		bool moveUp(float speed);
		void reset();

	private:
		float x = 0, y = 0, width, height;
	};
}

#endif // !OBJECT_H