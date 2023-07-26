#include "glpch.hpp"
#include "LayerStack.hpp"

namespace GLCore {
	LayerStack::LayerStack() {}
	void LayerStack::destroy() {
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer) {
		m_Layers.push_back(layer);
		layer->onAttach();

		LOG_SUCCESS(layer->getName() + " <GLCore::Layer> successfully pushed");
	}
	void LayerStack::popLayer(Layer* layer) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end()) {
			layer->onDetach();
			m_Layers.erase(it);
		}
		else {
			THROW_RUNTIME_ERROR(layer->getName() + " <GLCore::Layer> not found");
		}

		LOG_SUCCESS(layer->getName() + " <GLCore::Layer> successfully popped");
	}
}