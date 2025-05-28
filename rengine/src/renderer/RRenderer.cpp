#include "../platform/RWindows.h"
#include "../renderer//RRenderer.h"
#include "../../third_party/DiligentEngine/DiligentCore/Graphics/GraphicsEngineVulkan/interface/EngineFactoryVk.h"

namespace REngine {
    RRenderer::RRenderer(RWindows& window) : m_window(window) {
        // Initialize Diligent with SDL window handle
        Diligent::EngineVkCreateInfo engineCI;
        engineCI.pNativeWindowHandle = m_window.GetNativeHandle();

        auto* pFactoryVk = Diligent::GetEngineFactoryVk();
        pFactoryVk->CreateDeviceAndContextsVk(engineCI, &m_pDevice, &m_pContext);

        if (!m_pDevice || !m_pContext) {
            throw std::runtime_error("Failed to initialize Diligent!");
        }
    }

    void RRenderer::RenderFrame() {
        // Clear screen (example: red)
        const float clearColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        m_pContext->ClearRenderTarget(nullptr, clearColor, Diligent::RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
        m_pContext->Flush();
    }
}