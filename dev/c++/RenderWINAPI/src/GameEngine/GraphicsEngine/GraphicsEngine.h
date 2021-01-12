#pragma once

//#include <D3D11/Include/d3d11.h>
//#include <D3D11/Include/dxgi.h>
#include <D3D11/Include/d3d11.h>

class GraphicsEngine
{
public:
    GraphicsEngine() {}
    ~GraphicsEngine() {}

    bool init();
    bool release();

public:
    static GraphicsEngine* get();
private:
    ID3D11Device *m_d3d_device;
    D3D_FEATURE_LEVEL m_feature_level;
    ID3D11DeviceContext* m_imm_context;
};