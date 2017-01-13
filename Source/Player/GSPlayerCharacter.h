#pragma once
#include <characterkinematic/PxController.h>
#include <characterkinematic/PxControllerBehavior.h>

class PhysXCharacterController;
class PhysXPhysics;

namespace physx
{
	class PxControllerManager;
}

using namespace physx;

class GSPlayerCharacter : public PxUserControllerHitReport, public PxControllerBehaviorCallback
{
public:
	GSPlayerCharacter();
	~GSPlayerCharacter();

	bool Initialize(PxControllerManager* controllerManager, PxMaterial* playerMaterial);

	// Implements PxUserControllerHitReport
	virtual void							onShapeHit(const PxControllerShapeHit& hit);
	virtual void							onControllerHit(const PxControllersHit& hit) {}
	virtual void							onObstacleHit(const PxControllerObstacleHit& hit) {}

	// Implements PxControllerBehaviorCallback
	virtual PxControllerBehaviorFlags		getBehaviorFlags(const PxShape& shape, const PxActor& actor);
	virtual PxControllerBehaviorFlags		getBehaviorFlags(const PxController& controller);
	virtual PxControllerBehaviorFlags		getBehaviorFlags(const PxObstacle& obstacle);

private:
	PhysXCharacterController* m_pCharacterController;
};