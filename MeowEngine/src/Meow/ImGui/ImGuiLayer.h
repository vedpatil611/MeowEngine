#pragma once

#include "Meow/Core.h"
#include "Meow/Renderer/Layer.h"

namespace Meow
{
	class MEOW_API ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;
		void onUpdate() override;
		void onDettach() override;
		void onEvent(Event& e) override;
	};
}