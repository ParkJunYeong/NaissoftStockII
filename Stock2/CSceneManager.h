#pragma once

#include <assert.h>
#include <vector>

#include "IScene.h"

class CSceneManager
{
public:
	static CSceneManager *m_pInstance;
	static CSceneManager& Get() { assert(m_pInstance); return *m_pInstance; }

private:
	std::vector<IScene *> m_Scene;
	size_t m_ActivateSceneId;

public:
	CSceneManager();
	~CSceneManager();

	void RegistryScene(IScene *pScene);
	void UnRegistryScene(IScene *pScene);

	void SetScene(size_t index);

	void _update();
	void _render();
};