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

		void submit(const std::vector<Renderable2D*>& sprites) override;
		
		void begin() override;
		void onRender(float delta) override;
		void end() override;
	};
}