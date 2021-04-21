enum NHArtefactsModifiers
{
	MDF_ART_VIVERT = 1,
	MDF_ART_SOUL,
	MDF_ART_FIREBALL,
	MDF_ART_MEDUSA,
	MDF_ART_MINCER_MEAT,
	MDF_ART_DUMMY_DUMMY, 
	MDF_ART_DUMMY_BATTERY, 
	MDF_ART_EYE,
	MDF_ART_FUZZ_KOLOBOK,
	MDF_ART_KRISTALL,
	MDF_ART_PSI_FIELD,
};

enum NHArtefactsModifiersValues
{
	HEALTH_INCREMENT_PER_SEC = 5,
	BLOOD_INCREMENT_PER_SEC = 20,
	RADIATION_DECREMENT_PER_SEC = -0.33,
	RADIATION_INCREMENT_PER_SEC = 0.33,
	PSI_DECREMENT_PER_SEC = -0.66,
	PSI_INCREMENT_PER_SEC = 0.66,
	HEATBUFFER_INCREMENT_PER_SEC = 1.0,
};

modded class ModifiersManager
{
	override void Init()
	{
        NHDebugPrint("ModifiersManager::Init");
		super.Init();
		AddModifier(new NHArtModifierVivert);
		AddModifier(new NHArtModifierSoul);
		AddModifier(new NHArtModifierFireball);
	}
};