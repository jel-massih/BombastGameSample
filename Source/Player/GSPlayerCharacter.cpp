#include "GSPlayerCharacter.h"

#include "BombastEngineStd.h"
#include "Physics/PhysX/PhysXCharacterController.h"

using namespace physx;

GSPlayerCharacter::GSPlayerCharacter()
{

}

GSPlayerCharacter::~GSPlayerCharacter()
{
	SAFE_DELETE(m_pCharacterController);
}

bool GSPlayerCharacter::Initialize(PxControllerManager* controllerManager, PxMaterial* material)
{
	m_pCharacterController = BE_NEW PhysXCharacterController;

	PhysXCharacterControllerDesc desc;
	desc.mContactOffset = 0.01f;
	desc.mStepOffset = 0.05f;
	desc.mRadius = 0.3f;
	desc.mHeight = 1.0f;
	desc.mCrouchHeight = 0.25f;
	desc.mReportCallback = this;
	desc.mBehaviorCallback = this;
	desc.mMaterial = material;

	PxController* controller = m_pCharacterController->Initialize(desc, controllerManager);
	return controller != nullptr;
}

void GSPlayerCharacter::onShapeHit(const PxControllerShapeHit& hit)
{
}

PxControllerBehaviorFlags GSPlayerCharacter::getBehaviorFlags(const PxShape& shape, const PxActor& actor)
{
	return PxControllerBehaviorFlags(0);
}

PxControllerBehaviorFlags GSPlayerCharacter::getBehaviorFlags(const PxController&)
{
	return PxControllerBehaviorFlags(0);
}

PxControllerBehaviorFlags GSPlayerCharacter::getBehaviorFlags(const PxObstacle&)
{
	return PxControllerBehaviorFlag::eCCT_CAN_RIDE_ON_OBJECT | PxControllerBehaviorFlag::eCCT_SLIDE;
}