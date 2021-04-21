enum NHArtefactsModifiers
{
	MDF_ART_VIVERT = 1,
	MDF_ART_SOUL = 2,
	MDF_ART_FIREBALL = 3,
	MDF_ART_MEDUSA = 4,
	MDF_ART_MINCER_MEAT = 5,
	MDF_ART_DUMMY_DUMMY = 6, 
	MDF_ART_DUMMY_BATTERY = 7, 
	MDF_ART_EYE = 8,
	MDF_ART_FUZZ_KOLOBOK = 9,
	MDF_ART_KRISTALL = 10,
	MDF_ART_PSI_FIELd = 11
};

modded class ModifiersManager
{
	override void Init()
	{
        NHDebugPrint("ModifiersManager::Init");
		super.Init();
		AddModifier(new NHArtModifierVivert);
		AddModifier(new NHArtModifierSoul);
	}
};