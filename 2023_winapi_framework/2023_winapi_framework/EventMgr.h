#pragma once
class Button;
class Object;
struct tEvent
{
	EVENT_TYPE eEve; // 이벤트 타입
	Button* button;
	Object* Obj;
	OBJECT_GROUP ObjType;
};
class EventMgr
{
	SINGLE(EventMgr);
public:
	void Update();
	void ClickButton(Button* _pButton);
	void DeleteObject(Object* _pObj);
private:
	void Excute(const tEvent& _eve);
private:
	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecDead;
};

