#pragma once
#include "BaseModule.h"
#include "imgui/imgui.h"

class Damagehack : public BaseModule {
public:
	// Singleton pattern
	static Damagehack& GetInstance() {
		static Damagehack instance;
		return instance;
	}

	virtual ~Damagehack() = default;

	// Delete copy constructor and assignment operator
	Damagehack(const Damagehack&) = delete;
	Damagehack& operator=(const Damagehack&) = delete;

	// BaseModule interface implementation
	void Initialize() override;
	void Shutdown() override;
	void OnUpdate() override;
	void RenderGUI() override;
	void RenderOverlay() override;
	void ProcessHotkeys() override;



	// Module uses BaseModule's enabled variable directly

private:
	Damagehack();  // Private constructor for singleton


	// Hook function
	bool damageMultiplier ;
	int damageMultiplier_value ; 
	bool randomDamageType ;
	static app::DamageRecord* DamageRecordProperty_DealDamage_Hook(app::DamageRecordProperty* __this, app::AliveEntity* attacker, app::MyFloat damage, app::IElement* element, app::MyVector3 position, app::EDamageType__Enum type, app::EDamageElementalType__Enum eType, int32_t skillGroupId, bool isCritical, bool isTriggerElement, int32_t shieldID, app::MyFloat shieldChg, MethodInfo* method);
	// Helper functions
	void EnableDamagehack();
	void DisableDamagehack();

};