#include "Shake.h"

Shake* Shake::create(const float& duration, const float& strength) {
	return createWithStrength(duration, strength, strength);
}

Shake* Shake::createWithStrength(const float& duration, const float& strengthX, const float& strengthY) {
	auto* pRet = new(std::nothrow)Shake();
	if (pRet && pRet->initWithDuration(duration, strengthX, strengthY)) {
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool Shake::initWithDuration(const float& duration, const float& strengthX, const float& strengthY) {
	if (!ActionInterval::initWithDuration(duration)) {
		return false;
	}

	m_strengthX = strengthX;
	m_strengthY = strengthY;
	return true;
}

void Shake::update(float dt) {
	float randx = 25 * dt;
	float randy = 25 * dt;
	_target->setPosition(m_initialPos + Vec2(randx, randy));
}

void Shake::startWithTarget(Node* pTarget) {
	ActionInterval::startWithTarget(pTarget);

	m_initialPos = pTarget->getPosition();
}

void Shake::stop() {
	this->getTarget()->setPosition(m_initialPos);

	ActionInterval::stop();
}