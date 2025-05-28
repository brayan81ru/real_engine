#pragma once
#include "../../third_party/DiligentEngine/DiligentCore/Graphics/GraphicsEngine/interface/RenderDevice.h"
#include "../../third_party/DiligentEngine/DiligentCore/Graphics/GraphicsEngine/interface/DeviceContext.h"
#include <memory>
namespace REngine {
    class RWindows;  // Forward declaration

    class RRenderer {
    public:
        RRenderer(RWindows& window);
        void RenderFrame();  // Main render loop

    private:
        RWindows& m_window;
        Diligent::RefCntAutoPtr<Diligent::IRenderDevice>  m_pDevice;
        Diligent::RefCntAutoPtr<Diligent::IDeviceContext> m_pContext;
    };
}
