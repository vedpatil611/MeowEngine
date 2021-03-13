#pragma once

#include <Meow/Core.h>
#include "ImGuiLayer.h"

namespace Meow
{
	class MEOW_API ExampleLayer : public ImGuiLayer
	{
	public:
		ExampleLayer();
		~ExampleLayer();

		void onAttach() override;
		void onUpdate() override;
		void onDettach() override;
		void onEvent(Event& e) override;

		void begin() override;
		void onRender() override;
		void end() override;
	};
}