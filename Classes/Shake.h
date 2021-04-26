#ifndef _SHAKE_H
#define _SHAKE_H

#include "cocos2d.h"

USING_NS_CC;

class Shake : public ActionInterval {
public:
	static Shake* create(const float& duration, const float& strength);
	static Shake* createWithStrength(const float& durantion, const float& strengthX, const float& strengthY);
	bool initWithDuration(const float& duration, const float& strengthX, const float& strengthY);


	virtual void startWithTarget(Node* pTarget)override;
	virtual void update(float dt)override;
	virtual void stop()override;

	Vec2 m_initialPos;
	float m_strengthX, m_strengthY;
};


#endif //!_SHAKE_H