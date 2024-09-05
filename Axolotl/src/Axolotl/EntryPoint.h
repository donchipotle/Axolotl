#pragma once

#ifdef AX_PLATFORM_WINDOWS

extern Axolotl::Application* Axolotl::CreateApplication();


int main(int argc, char** argv)
{
	Axolotl::Log::Init();
	AX_CORE_WARN("Initialized Log");
	AX_WARN("Initialized Client Log");

	auto app = Axolotl::CreateApplication();
	app->Run();
	delete app;
}

#endif
