#ifndef INTRO_H
#define INTRO_H

class Intro
{
public:
	Intro(int width, int height);
	~Intro();
	void draw();

	bool isIntroOver;

private:
	int width, height;
};

#endif // !INTRO_H
