#include "CSceneManager.h"

CSceneManager * CSceneManager::m_pInstance = nullptr;

CSceneManager::CSceneManager() : m_ActivateSceneId(-1)
{
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::RegistryScene(IScene *pScene)
{
	m_Scene.push_back(pScene);
}

void CSceneManager::UnRegistryScene(IScene *pScene)
{
	auto it = std::find(m_Scene.begin(), m_Scene.end(), pScene);

	if (it != m_Scene.end()) m_Scene.erase(it);
}

void CSceneManager::SetScene(size_t index)
{
	m_ActivateSceneId = index;

	m_Scene[index]->OnActivate();
}

void CSceneManager::_update()
{
	if (m_ActivateSceneId == -1) return;

	m_Scene[m_ActivateSceneId]->OnUpdate();
}

void CSceneManager::_render()
{
	if (m_ActivateSceneId == -1) return;

	m_Scene[m_ActivateSceneId]->OnUpdate();
}
