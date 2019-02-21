#pragma once
#include <windows.h>
#include "ECSManager.h"
#include "Components.h"
#include "ISystem.h"
#include "Vector4.h"
#include <d3d11shader.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include "Result.h"
#include <wrl.h>

class RenderSystem : public ISystem
{
private:
	std::shared_ptr<ECSManager> ecsManager = ECSManager::Instance();
	std::vector<Entity> mLights;
	const Entity* mActiveCamera;

	/// <summary>
	/// DirectX pointers
	/// </summary>
	D3D_DRIVER_TYPE mDriverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL mFeatureLevel = D3D_FEATURE_LEVEL_11_0;
	Microsoft::WRL::ComPtr<ID3D11Device> mDevice = nullptr;
	Microsoft::WRL::ComPtr<ID3D11Device1> mDevice1 = nullptr;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> mContext = nullptr;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1> mContext1 = nullptr;
	Microsoft::WRL::ComPtr<IDXGISwapChain> mSwapChain = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRenderTargetView = nullptr;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> mDepthStencil = nullptr;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDepthStencilView = nullptr;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> mDepthStencilState = nullptr;
	Microsoft::WRL::ComPtr<ID3D11Buffer> mConstantBuffer = nullptr;
	Microsoft::WRL::ComPtr<ID3D11Buffer> mConstantBufferUniform = nullptr;
	Microsoft::WRL::ComPtr<ID3D11SamplerState> mTexSampler = nullptr;
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> mDefaultRasterizerState = nullptr;

public:
	explicit RenderSystem(const HWND& pWindow);
	virtual ~RenderSystem();

	HRESULT InitDevice(const HWND& pWindow);
	void CreateConstantBuffers();
	void Cleanup();

	void AssignEntity(const Entity& pEntity) override;
	void Process() override;
};
