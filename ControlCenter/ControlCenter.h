#pragma once
class ControlCenter
{
public:
	template<typename T>
	static T* getInstance();
private:
	ControlCenter();
};
template <typename T>
T* ControlCenter::getInstance() {
	return T::getInstance();
}

