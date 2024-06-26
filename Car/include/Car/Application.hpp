#pragma once

#include "Car/Core/Core.hpp"

#include "Car/Core/Timestep.hpp"
#include "Car/Events/Event.hpp"

#include "Car/Layers/Layer.hpp"
#include "Car/Layers/LayerStack.hpp"
#include "Car/Layers/ImGuiLayer.hpp"
#include "Car/Window.hpp"


namespace Car {
	class Application {
	public:
		Application();
		virtual ~Application() = 0;

		void pushLayer(Layer*);
		void popLayer(Layer*);
		void pushOverlay(Layer*);
		void popOverlay(Layer*);

		virtual bool onMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		virtual bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		virtual bool onMouseMovedEvent(MouseMovedEvent& event);
		virtual bool onMouseScrolledEvent(MouseScrolledEvent& event);
		virtual bool onKeyPressedEvent(KeyPressedEvent& event);
		virtual bool onKeyReleasedEvent(KeyReleasedEvent& event);
		virtual bool onWindowResizeEvent(WindowResizeEvent& event);
		virtual bool onWindowCloseEvent(WindowCloseEvent& event);
		virtual bool onWindowFocusEvent(WindowFocusEvent& event);
		virtual bool onWindowLostFocusEvent(WindowLostFocusEvent& event);

		virtual void onImGuiRender(double deltaTime) {UNUSED(deltaTime); };

		virtual void onUpdate(double deltaTime) { UNUSED(deltaTime); }
		virtual void onRender() = 0;

		inline const Ref<Car::Window> getWindow() const { return mWindow; }
		static const Car::Application* Get();

		// meant to be called by EntryPoint
		void run();
	public:
		bool isRunning=true;
	private:
		bool onEvent(Car::Event& event);
	private:
		Ref<Car::Window> mWindow;
		Car::ImGuiLayer mImGuiLayer;
		Car::LayerStack mLayerStack;
		double mLastFrameTime = 0.0;
	};

	// To be defined in CLIENT
	Application* createApplication();
}
