#include "Engine.h"
#include "GraphicsWorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Graphics");

	GraphicsWorld* world = new GraphicsWorld();

	engine->setActiveWorld(world);

	int exitCode = engine->run();

	delete world;
	delete engine;

	return exitCode;
}