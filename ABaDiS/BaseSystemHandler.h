#pragma once
class BaseSystemHandler
{
public:
	static void setupBaseSystemHandler(BaseSystem*);
	static Room* getRandomRoom();

private:
	static BaseSystem* baseSystem;
	static bool isGenerated;
};