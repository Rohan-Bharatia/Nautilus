#include "nautilus.h"

class Sandbox : public Nt::Application
{
public:
	Sandbox(void)
	{}

	virtual ~Sandbox(void)
	{}
};

Nt::Application* Nt::createApplication(void)
{
	return new Sandbox();
}