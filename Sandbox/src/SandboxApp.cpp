#include <Axolotl.h>

class Sandbox : public Axolotl::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};
/*
int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}
*/

Axolotl::Application* Axolotl::CreateApplication()
{
	return new Sandbox();
}