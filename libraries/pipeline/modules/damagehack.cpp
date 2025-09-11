#include "pch-il2cpp.h"
#include "damagehack.h"
#include "../keybinds.h"
#include "pipeline/HookManager.h"
#include "imgui/imgui.h"
#include <iostream>
#include <random>


Damagehack::Damagehack() : BaseModule("Damagehack")
{
	// enabled is inherited from BaseModule and defaults to false
	damageMultiplier = false;
	damageMultiplier_value = 100;
	randomDamageType = false;
}

void Damagehack::Initialize() {
	//std::cout << "[INFO] No Fog Module initialized" << std::endl;
	LoadConfig();
}

void Damagehack::Shutdown() {
	if (enabled) {
		DisableDamagehack();
	}
	SaveConfig();
	std::cout << "[INFO] Damagehack Module shutdown" << std::endl;
}

void Damagehack::OnUpdate() {
}

void Damagehack::RenderGUI() {
	if (ImGui::CollapsingHeader("Damagehack")) {
		ImGui::Indent();
		if (
			ToggleSwitch("Damagehack enabled", &enabled)
			) {
			if (enabled) {
				EnableDamagehack();
				//std::cout << "[INFO] No Fog enabled " << std::endl;
			}
			else {
				DisableDamagehack();
				//std::cout << "[INFO] No Fog disabled" << std::endl;
			}
		}
		if (enabled) {
			ToggleSwitch("Damage Multiplier", &damageMultiplier);
			if (damageMultiplier) {
				ImGui::InputInt("Multiplier Value", &damageMultiplier_value);
			}
			ToggleSwitch("Random Damage Type", &randomDamageType);
		
		
		}

		ImGui::Unindent();
	}
}

void Damagehack::RenderOverlay() {
}

void Damagehack::ProcessHotkeys() {

}


void Damagehack::EnableDamagehack() {
	HookManager::install(app::DamageRecordProperty_DealDamage, DamageRecordProperty_DealDamage_Hook);
}

void Damagehack::DisableDamagehack() {
	
	HookManager::detach(DamageRecordProperty_DealDamage_Hook);
}



app::DamageRecord* Damagehack::DamageRecordProperty_DealDamage_Hook(app::DamageRecordProperty* __this, app::AliveEntity* attacker, app::MyFloat damage, app::IElement* element, app::MyVector3 position, app::EDamageType__Enum type, app::EDamageElementalType__Enum eType, int32_t skillGroupId, bool isCritical, bool isTriggerElement, int32_t shieldID, app::MyFloat shieldChg, MethodInfo* method) {
	Damagehack& instance = Damagehack::GetInstance();
	if (instance.enabled) {
		
		app::MyFloat new_damage = damage;
		app::EDamageElementalType__Enum randomElementType = eType;
		if(instance.damageMultiplier){
			float dmg = app::MyFloatUtility_GetFloat(damage, nullptr);
			float new_dmg_value = dmg * instance.damageMultiplier_value;
			new_damage = app::MyFloatUtility_GetMyFloat(new_dmg_value, nullptr);

		}
		//if(instance.randomDamageType)
		//{
		//	static std::random_device rd;
		//	static std::mt19937 gen(rd());
		//	constexpr auto elementTypes = magic_enum::enum_values<app::EDamageElementalType__Enum>();
		//	static std::uniform_int_distribution<size_t> dis(0, elementTypes.size() - 1);

		//	randomElementType = elementTypes[dis(gen)];
		//}
		// Random element type selection
		randomElementType = app::EDamageElementalType__Enum::Earth;
		
		//LOG_DEBUG("DealDamage_Hook  damage: {}", dmg);
		//LOG_DEBUG("DealDamage_Hook  DamageElementalType: {}", magic_enum::enum_name(randomElementType));
		return CALL_ORIGIN(DamageRecordProperty_DealDamage_Hook, __this, attacker, new_damage, element, position, type, randomElementType, skillGroupId, true, isTriggerElement, shieldID, shieldChg, method);

	}


	return CALL_ORIGIN(DamageRecordProperty_DealDamage_Hook, __this, attacker, damage, element, position, type, eType, skillGroupId, isCritical, isTriggerElement, shieldID, shieldChg, method);
}