#pragma once

class IScene
{
public:
	virtual void OnActivate() { }
	virtual void OnUpdate() { }
	virtual void OnRender() { }
};